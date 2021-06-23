# GFS / Google File System

1. [ Description. ](#desc)
  - [Functional](#Functional)
- [Architecture](#Architecture)
  - [1.Chunks](#1.Chunks)
  - [GFS_Master](#GFS_Master)
  - [GFS_Client](#GFS_Client)
  - [Chunk_Servers](#Chunk_Servers)
- [Caching](#Caching) 

<a name="desc"></a>
## 1. Description
### Functional
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

## Architecture
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
### 1.Chunks
  - Files are divided into fixed-size chunks
  - Each chunk is identified by an immutable(non-changable) and globally unique 64 bit chunk. Assigned by the master at the time of chunk creation.
  - For reliability, each chunk is replicated on multiple chunkservers(By default, 3 replicas)
### GFS_Master
  - **Stores**
    - Maintains all meta-data. Meta-data: namespace, access control information, Mapping from files to chunks, current location of chunks.
  - **Does Tasks**
    - _1. Chunk management_
      - Garbage collection of orphaned chunks, chunkmigration between chunkservers.
      - Replication decisions using global knowledge
      - Sophisticated chunk placement
  - **Does not:**
    - Involve in reads and writes with clients, so that it does not become a bottleneck.
### GFS_Client
  - GFS client is linked to each Client application implements the file system API and communicates with the master and chunkservers.
  - Only interacts with GFS master to know which chunkserver to contact for RW, RW is done using chunkserver.
### Chunk_Servers
  -  Stores chunks as local files. No caching is needed here.

## Caching
- **Caching File Data:** Neither on client nor the chunkserver. 
  - Client caches offer little benefit because most applications stream huge files or have working sets too large.
  - It also creates cache coherance problems.
- **Caching meta data:** Yes
to be cached.
