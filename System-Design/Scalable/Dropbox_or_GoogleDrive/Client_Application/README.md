## Client Application
- We can create different modules inside Client-Application doing above task. Eg:

### 1. Internal Metadata Database
- Stores this information: all files user have, no of chunks, versions, start, endPtr, pointer to structure storing hash of chunks. 
- Client will store meta data information locally as well.
```c
| fileID | No of chunks | sizeofChunk | fileStartPtr | fileEndPtr | ptrTo_hash_structure | version |
| 0x8129 | 4 | 200 bytes | 0x45 | 0x789 | 0x492m | 4 |
                                              \/
                                        | hashOf-Chunk1 | .... | hashOf-Chunk4 |
                                          hashOf_chunkStructure
```

### 2. Watcher 
- This will keep watch on workspace for any changes made by user. When user changes file.
- It will notify chunker about the change. This also implements *select()/poll()/epoll()* API, it listens for communication from drop-box server.

### 3. Chunker 
- Module doing all processing about chunks. Fills/updates *Internal Metadata database*.
- Decide chunk-size on the fly based on directions from dropbox server.
- On reception of message from watcher, Calculate hash of all the chunks.
- Compare oldHashes with newHash deciding on which chunk to be transmitted.
- This module is also responsible for recreation of file on reception of **chunks**.

### 4. Transmitter 
- Module sending the changed chunk to dropbox server. Chunker will provide this information to transmitter:
- Old Hash of chunk        //Dropbox server is also storing hashes,server will find this hash in its DB and know this field needs updation
- New Hash of chunk        //If data is modified in transit, server can detect data is malformed.
- Actual data of chunk     //To be stored on object store
- **On Server on reception of chunk:** Sending and updating data using Hash and Chunk is called **DATA DECUPLICATION**.
```c
  if (recieved_HASH == stored_Hash) 
    Discard Chunk.
  else
    Update Original File content, Hash of chunk
```
 <img src=dropbox-client-application.PNG width=600 />
