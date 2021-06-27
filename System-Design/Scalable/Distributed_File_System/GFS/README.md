# GFS / Google File System

- [1. Requirements](#Requirements)
  - [1.1 Functional](#Functional)
- [2. Architecture](#Architecture)
  - [2.1 Chunks](#Chunks)
  - [2.2 GFS Master](#GFS_Master)
    - [2.2.a Stores meta-data, Operation Logs](#stores)
  - [2.3 GFS Client](#GFS_Client)
    - [2.3.1 Case-1: Read Operation: User Reading a File](#Read_File)
    - [2.3.2 Case-2: Write Operation: User Writing to File](#write)
  - [2.4 Chunk Servers](#Chunk_Servers)
- [3. Caching](#Caching) 

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
#### A. All meta-data 
- Keeps 64bytes of meta data for each 64MB chunk.
  - chunk namespace(think similar to c++ namespaces), Mapping from files to chunks  //These 2 are stored persistant using [long Mutations](/System-Design/Terms)
  - Current location of each chunk's replica, access control information.
    - Chunk location is asked by gfs-master from chunkservers at startup, after that master will updates its DB since all chunkplacement is done by master with regular HeartBeat messages to chunkservers.
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
- 1. User opens dropbox space, opens a file and writes on some index.
- 2. GFS Client asks which chunk-replica holds ownership/lease of current chunk. if noone has lease master assigns lease to one and returns all 
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

<a name="Chunk_Servers"></a>
## 2.4 Chunk Servers
  -  Stores chunks as local files. No caching is needed here.

<a name="Caching"></a>
# 3. Caching
- **Caching File Data:** Neither on client nor the chunkserver. 
  - Client caches offer little benefit because most applications stream huge files or have working sets too large.
  - It also creates cache coherance problems.
- **Caching meta data:** Yes
to be cached.
