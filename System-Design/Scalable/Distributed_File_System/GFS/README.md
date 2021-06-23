# GFS / Google File System

- [1. Requirements](#Requirements)
  - [1.1 Functional](#Functional)
- [2. Architecture](#Architecture)
  - [2.1 Chunks](#Chunks)
  - [2.2 GFS Master](#GFS_Master)
  - [2.3 GFS Client](#GFS_Client)
    - [2.3.1 Case-1: Read Operation: User Reading a File)(#Read_File)
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

<a name="GFS_Master"></a>
## 2.2 GFS Master
  - **Stores**
    - Maintains all meta-data. Meta-data: namespace, access control information, Mapping from files to chunks, current location of chunks.
  - **Does Tasks**
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
