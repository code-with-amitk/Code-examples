# GFS / Google File System

- [Requirements](#Requirements)
  - [Functional](#Functional)
- [Architecture](#Architecture)
  - [Chunks](#Chunks)
  - [GFS_Master](#GFS_Master)
  - [Client-Application/GFS-Client](#Client-Application/GFS-Client)

## Requirements
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
  [Drop-box]GFS-Client1 <---->      Chunkserver(linux)  ---hb-----------
                                                                        |
                                    Chunkserver(linux)  --heartbeat -- GFS-Master
                                                                        |
        client2	 <---->             Chunkserver(linux)	----hb----------
```
#### Chunks
  - Files are divided into fixed-size chunks
  - Each chunk is identified by an immutable(non-changable) and globally unique 64 bit chunk. Assigned by the master at the time of chunk creation.
  - For reliability, each chunk is replicated on multiple chunkservers(By default, 3 replicas)
#### GFS_Master
  - Maintains all meta-data. Meta-data: namespace, access control information, Mapping from files to chunks, current location of chunks.
  - Does chunk management eg: garbage collection of orphaned chunks, chunkmigration between chunkservers.
#### Client-Application/GFS-Client
  - GFS client is linked to each application implements the file system API and communicates with the master and chunkservers.
