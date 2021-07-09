# [GFS / Google File System](https://storage.googleapis.com/pub-tools-public-publication-data/pdf/035fc972c796d33122033a0614bc94cff1527999.pdf)

- [1. Requirements](#Requirements)
  - [1.1 Functional](#Functional)
- [2. Architecture](#Architecture)
  - [2.1 Chunks](#Chunks)
  - [2.2 GFS Master](#GFS_Master)
    - [2.2.a Stores metadata, Operation Logs](#stores)
  - [2.3 GFS Client](#GFS_Client)
    - [2.3.1 Read Operation: User Reading a File](#Read_File)
    - [2.3.2 Write Operation: User Writing to File](#write)
    - [2.3.3 User creates snapshot of workspace](#snapshot)
    - [2.3.4 Deleting a file & Garbage Collection](#delete)
  - [2.4 Chunk Servers](#Chunk_Servers)
- [3. Caching](#Caching)
- [4. Fault Tolerance](#tolerance)
- [5. Data Integrity](#di)
- [6. BOE](#boe)
  - [6.1 Reads](#boereads)



<a name="Requirements"></a>
# 1. Requirements
<a name="Functional"></a>
## 1.1 Functional
- _1._ The system is built from many inexpensive commodity components that often fail. 
  - It must constantly monitor itself and detect, tolerate, and recover promptly from component failures on a routine basis. 
- _2._ System stores 1-100GB sized millions of files.
- **_3._ Reads:**
  - _a._ Large reads(reading hundreds of KBs).
  - _b._ Small random reads(read few KBs at some arbitrary offset), often read through a contiguous region of a file.
- _4._ **Write to files:** Operations similar to reads
  - _a._ Small writes at arbitrary positions in a file are supported but do not have to be efficient
  - _b._ mutliple clients concurrently append to same file
    - Need atomicity with min synchronization overhead.

<a name="Architecture"></a>
# 2. Architecture
- GFS cluster consists of a 1 master and multiple chunkservers and is accessed by multiple clients
```c
    docx, xls
  [Drop-box]GFS-Client1 <---->      Chunkserver1(linux)  ---hb-----------
                                                                        |
                                    Chunkserver2(linux)  --heartbeat -- GFS-Master
                                                                        |
        client2	 <---->             Chunkserver3(linux)	----hb----------
          |
          | --------------which chunkserver to contact for file-x----------->
          | <--------------------- chunkserver3 ----------------------------
          | <------- RW ----------------->
          
```

<img src=gfs_architecture.JPG width=500/>

<a name="Chunks"></a>
## 2.1 Chunks
- Files are divided into fixed-size chunks
- Each chunk is identified by an immutable(non-changable) and globally unique 64 bit chunk. Assigned by the master at the time of chunk creation.
- For reliability, each chunk is replicated on multiple chunkservers(By default, 3 replicas)

### 2.1.a Chunk size = 64MB
- **Advantages of large chunk?**
  - Only 1st time client need to contact gfs-master to get chunk-replica-ip-address. //See Read operation below
  - On a large chunk, gfs-client can perform many operations, it reduces network overhead.
  - It reduces the size of the metadata stored on the master.

<a name="GFS_Master"></a>
## 2.2 GFS Master

<a name="stores"></a>
### 2.2.a GFS Master Stores
#### A. All metadata 
- Keeps 64bytes of metadata for each 64MB chunk.
  - chunk namespace(think similar to c++ namespaces), Mapping from files to chunks  //These 2 are stored persistant using [long Mutations](/System-Design/Terms)
  - Current location of each chunk's replica, access control information.
    - Chunk location is asked by gfs-master from chunkservers at startup, after that master will updates its DB since all chunkplacement is done by master with regular HeartBeat messages to chunkservers.
- metadata is stored in [IMDB, In memory database](/System-Design/Concepts/Databases).

#### B. Operation Logs 
- These are stored on gfs-master disk and remotely both.
- *Purpose?*
  - Stores time of creation of Files, chunks, their versions.
  - In case master crashes this will help in recuprating master again.
    - We will keep **checkpoints**(Maintained as compact [B-Tree](/DS_Questions/Data_Structures/Trees/M-Ary_Trees/B+Tree/)) in log file, so that when master need to recover it does not read whole file and take lot of time.
    - New checkpoint is created in seperate thread every minute or so for cluster containing 1-10 Million files.
    - After new checkpoint is created, older checkpoints can be deleted, some can be kept to guard against catastrophes.

- **Tasks Performed**
  - _1. Chunk management_
    - Garbage collection of orphaned chunks, chunkmigration between chunkservers.
    - Replication decisions using global knowledge
    - Sophisticated chunk placement
- **Does not:**
  - Involve in reads and writes with clients, so that it does not become a bottleneck.

<a name="GFS_Client"></a>
## 2.3 GFS Client
- GFS client is linked to each Client application implements the file system API and communicates with the master and chunkservers.
- Only interacts with GFS master to know which chunkserver to contact for RW, RW is done using chunkserver.

<a name="Read_File"></a>
### 2.3.1 Read Operation: User Reading a File
- 1. User opens dropbox space, opens a file and places cursor on some index.
- 2. GFS Client reads Filename, byte offset(in file). Converts byte offset to chunk index, sends Filename, Chunk-index to GFS master.
  - unordered_map<key=offset, value=index>
- 3. Master returns chunk_handle(ie file handle), chunkserver-replicas ip address to GFS Client.
- 4. GFS Client will cache this information <key=chunk_index, value=handle>
  - key=chunk_index, value=filename
- 5. Client connects with nearst replica, sends chunk_handle,offset & get chunk. client can request multiple chunks within 1 request.
```console
  Dropbox-space
  - User opens a.txt at offset=1000   //1
  
              GFS-CLIENT
            converts offset=1000 to index=2   //2
            
                  ----------- a.txt, index=2---------->   GFS-Master
                  <----chunk_handle=60, chunkserver-replicas----            //3
            
               Caches                //4
          <key=chunk_index, value=handle>
          
             GFS-CLIENT
          connects to nearest replica 
                  ----------chunk_handle, start_offset, end_offset-------> Replica
                  <--------- chunk.. ---------------------------------------
```

<a name="write"></a>
### 2.3.2 Write Operation: User writing to a File
- _1._ User opens dropbox space, opens a file and writes on some index.
- _2._ GFS Client asks which chunk-replica holds ownership/lease of current chunk. if noone has lease master assigns lease to one and returns all 
  - _Chunk Ownership/LEASE:_ Every chunk would be owned by 1 of chunk-replica for specific time. This lease is assigned by master to chunk-replica.
- _3._ Master returns chunkserver-replicas ip address to GFS Client.
- _4._ GFS Client will push data to primary chunk-replica. Primary chunk-replica will forward data to its NEAREST chunk replica-b. Chunk-replica-b will forward data to its nearst chunk-replica. This way N/W Bandwidth is saved, latency is minimized. 1MB is roughly stored/distributed in 80ms.
- _5._ Primary Chunk-replica, ie to which lease was provided by master assigns serial number to chunks written.
- _6._ In case of any error in write, its communicated to GFS-Client. In case of failure in writing chunk, particular data block would not been assigned serial number by chunk-replica and its possibly lost or in inconsistent state. Client will retry rewriting the data ie failed mutations.
```console
  Dropbox-space
  - User opens a.txt at offset=1000 and writes data-y  //1
    a.txt,offset=1000 = chunk-x
    
              GFS-CLIENT
              Get chunk-server holding lease //2
            
                  ----------------- chunk-x ---------->   GFS-Master
                  <----chunkserver-replicas list----            //3
                      
              Push data to all replicas //4
                  ------------ data-y ----------> chunk-replica-a   //5
                  <-------- ACK ----------------
                  
                                                      --- data-y --> chunk-replica-b
                                                      <---- ACK ----
                                                                      --- data-y --> chunk-replica-c
                                                                      <---- ACK ----
```

<a name=snaphot></a>
### 2.3.3 User creates snapshot of workspace
- **snaphot?** Makes a copy of a file or a directory tree (the “source”) almost instantaneously, without affecting any ongoing mutations/write operations.
- _1._ User opens dropbox space, and presses button for snapshot.
- _2._ When the gfs-master receives a snapshot request, it 1st revokes any outstanding leases on the chunks in the files it is about to snapshot. This ensures that any subsequent writes to these chunks will require an interaction with the master to find the lease holder. gfs-master creates new copy of chunk 1st.
  - _Chunk Ownership/LEASE:_ Every chunk would be owned by 1 of chunk-replica for specific time. This lease is assigned by master to chunk-replica
- _3._ Master writes changes to operation log.
- _4._ Makes snapshot's file-1 point to file-1 in same workspace of client. Newly created snapshot files point to the same chunks as the source files.
- _5._ GFS Client writes new chunk-x to old file-y in snaphot, it sends request to gfs-master to find chunk-replica.
- _6._ GFS-master creates chunk-x on chunk-replica that holds file-y. This ensures data is copied locally(no network based writes), now its same as 2.3.1
```console
Dropbox-space/GFS-Client
  Take snapshot   //1
   
        -------------------------->   GFS-Master
                                  Revoke outstanding leases   //2
                                  Logs data to operation log  //3
                                  Makes newly created snapshot point to old data //4
                      
  GFS-Client
add chunk-x to old file-y on snaphot  //5
        -----------Find chunk-replica------>
                                  Creates chunk-x on chunk-replica  //6
                                  that holds the file-y
                                          ------------- Create chunk-x ----------> chunk-replica
                                //Same as writing to chunk
```

<a name=delete></a>
### 2.3.4 Deleting a file, Lazy Claiming. Distributed Garbage Collection.
- _1._ User deletes a file in its namespace.
- _2._ Delete request goes to master, master does not immediattely goes to replica deletes/reclaims the space. Instead master marks deleted file as `hidden`.
  - Hidden file remains on filesystem for 3(comfigurable) days, if user tries to restore he can.
  - After 3 days, during regular scan of filesystem of chunk-servers by master. File and its meta-data are deleted.
  - During this scan only if master finds orphaned chunks, it reclaims their spaces also deletes their meta-data.
- This is done when master is relatively free.

<a name="Chunk_Servers"></a>
## 2.4 Chunk Servers
  -  Stores chunks as local files. No caching is needed here.

<a name="Caching"></a>
# 3. Caching
- **Caching File Data:** Neither on client nor the chunkserver. 
  - Client caches offer little benefit because most applications stream huge files or have working sets too large.
  - It also creates cache coherance problems.
- **Caching metadata:** Yes
to be cached.

<a name="tolerance"></a>
# [4. Fault Tolerance](/System-Design/Concepts/Terms)
- Among hundreds of servers in a GFS cluster, some are bound to be unavailable at any given time. System is kept highly available using these strategies.

<a name="fastr"></a>
## 4.1 Fast recovery 
- _1._ GFS-master and chunkservers are designed such that, if they fail/terminated, they can restart quickly and restore their state in few seconds.

<a name="replication"></a>
## 4.2 Chunk replication
- _1._ Each chunk is replicated on multiple chunkservers on different racks(so that if 1 rack fails all chunkservers should not go down).
- 2. Redundancy schemes between replicas: parity or erasure codes.

<a name=di></a>
## 5. Data Integrity
- Each chunkserver uses checksum(32 bit) to ensure chunk is not corrupted. Each 64MB chunk is broken into 64KB blocks. As metadata, checksum is also stored in-memory(ie [IMDB](/System-Design/Concepts/Databases)).
- if we try to fetch checksum from other cuhnkservers it would lead to lot of traffic, so each chunkserver will maintain its own checksum record.
- If a block does not match the recorded checksum, the chunkserver returns an error to the requestor and reports the mismatch to the master.
  - Now requestor will read from other replica and master will clone chunk from other replica.

<a name=boe></a>
## 6. BOE
- Considering test env as:
  - 1 master, 2 master replicas, 16 chunkservers, 16 clients. Memory for every machine: RAM=2GB, Harddisk=80GBx2
  - All machines are connected to each other using switch.
```console
                |----------------1 Gbps cable------------------------|
            switch-1(100 Mbps)                                  switch-2(100Mbps)
               |                                                    |
  |------|--------------|--------|                    |--------|-----------|--------|
master  replica-1 replica-2 16-chunkservers       client1   client2   client3   client4
```
<a name=boereads></a>
### 6.1 Reads
- Max reads limits on provided [1Gbps ethernet cable](/Networking/OSI-Layers/Layer-1/Media_Types) and 100Mbps switch
  - 1 Gbps Line. 10<sup>9</sup> / 16 = 62.5 Mbps
  - 100 Mbps switch. 100<sup>6</sup> / 16 = 6.25 Mbps
- 1 reader's Read limit = 6.25Mbps(ie lower of above two). This will drop further when readers increases.
- Limit can be increased by using [CAT7 ethernet cable](/Networking/OSI-Layers/Layer-1/Media_Types).
<a name=appends></a>
### 6.2 Appends
- let us consider all clients tries to append to 1 file, for 1 writer = 6.25 Mbps.
- Considering collisions on network, packet drops append/client reduces to 4.8Mbps.
