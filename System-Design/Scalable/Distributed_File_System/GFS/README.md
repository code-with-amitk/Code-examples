# GFS / Google File System

- [Requirements](#Requirements)
  - [Functional](#Functional)
- [Architecture](#Architecture)
  - [2.1Chunks](#2.1Chunks)

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
```
	Client1	<---->			chunkserver(linux)
							
							        chunkserver(linux)		GFS-Master
							
	client2	<---->			chunkserver(linux)	
```
### 2.1Chunks
- **What?** Files are divided into fixed-size chunks
	- Each chunk is identified by an immutable(non-changable) and globally unique 64 bit chunk. Assigned by the master at the time of chunk creation.
- For reliability, each chunk is replicated on multiple chunkservers(By default, 3 replicas)
