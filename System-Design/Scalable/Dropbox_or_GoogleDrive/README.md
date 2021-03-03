- **DropBox/Google Drive/Cloud File Storage?**
  - This is file hosting service. Storing data on remote servers.
  - Read:Write ratio is same.
  - If files are stored/transffered in smaller chunks(eg: 4MB) it will save lot of BW and space.
  - *Advantages?* 
    - Data is available anytime,anywhere on any device(mobile,linux,windows etc).
    - Reliable(multiple copies are stored) data will not be lost.
    - Secure

## [To Cover](/System-Design/Scalable)

## 1. Requirements
- **Functional:**
  - *1.* Upload files/photos from any device ie create/write and auto-saving of document.
  - *2.* Other users can download the files/photos from any device.
  - *3.* Offline editing. User should be able to upload/edit while he's offline, information should go on drive as he comes online.
  - *4.* Share files with others.
  - *5. Synchronization* Automatic synchronization between devices, i.e., after updating a file on one device, it should get synchronized on all devices.
- **Non-functional:** S<sup>3</sup> L<sup>3</sup> C<sup>2</sup> A<sup>3</sup> R<sup>2</sup> F
- **Extended:** Snaphot of data: System should support snapshotting of the data, so that users can go back to any version of the files.

## 2. BOE

|World Population|InternetUsers(60%)|DropBox users(2%)|Daily Active users(10~12%)|
|---|---|---|---|
|7 Billion //Year 2020|7 x 0.6 = 4.2 Billion|4.2 x 0.2 = 840 Million |840 x .12 = 100 Million|

- **Storage Estimates:** Assume On average each user has 500 file/photos daily. 
  - Each file=100KB. Storage/day 100M x 100K x 500 = 5PB. For 5 years = 5 x 30 x 12 x 5 = 9ExaBytes

- **Traffic Estimates:** Assume 1M active users/min. Each sending 100KB file. 100GB/min. 166MB/sec

## 3. HLD
> User creates gmail account, 15GB space is reserved for him, once he logs in dashboard is provided to user.

- **3.1 New File Creation**
  - *a.* User creates a file. A client Application running on user's machine sends following information (userId, fileId, file content, hash of file)
  - *b.* Server stores text/photo/video on [Object-DB]() and following on meta-data SQL server.
```c
File's Metadata table:
   
| userId | uniqueFileID (uniqueFID) | startPtr of File | endPtr of File | sha3HashOfFile | ActualFileLocation (PtrOnDB) | Directory structure | Shared-With |
```

- **3.2 Updating Existing File**
  - Let's suppose a file of 50kb already exists, maybe 500 lines. There are 2 cases here:
    - *a.* User erases last 100 lines and adds new 100 lines. File size is still same but contents are changed.
    - *b.* User erases last 100 lines and adds new 200 lines. File size is changed.
      - **Hash based solution:** We will pre-divide whole file into chunks. Chunk-1{0-100 lines=10kb}, Chunk-2, Chunk-3 and so on.
      - Client will store hash of chunks. Whenever user writes to file, Client Application will recalculate the hashes for chunk. Whichever hash mismatches, means this chunk is changed & this needed to be transmitted to server.
 
#### Modules of Client Application
> We can create different modules inside Client-Application doing above task.
  - **1. Internal Metadata Database** Stores this information: all files user have, no of chunks, versions, start, endPtr, pointer to structure storing hash of chunks.
```c
| fileUniqueID | No of chunks | sizeofChunk | fileStartPointer | fileEndPointer | ptrTo_hash_structure | version |
| --- | --- | --- | --- | --- | --- | --- |
| 0x8129 | 4 | 200 bytes | 0x45 | 0x789 | 0x492m | 4 |
                                               |
                                               | 
                                              \/
                                        | hashOf-Chunk1 | hashOf-Chunk2 | hashOf-Chunk3 | hashOf-Chunk4 |
                                          hashOf_chunkStructure
```

  - **2. Watcher** This will keep watch on workspace for any changes made by user. When user changes file.
     - It will notify chunker about the change. This also implements *select()/poll()/epoll()* API, it listens for communication from drop-box server.
  - **3. Chunker** Module doing all processing about chunks. Fills/updates *Internal Metadata database*.
     - Decide chunk-size on the fly based on directions from dropbox server.
     - On reception of message from watcher, Calculate hash of all the chunks.
     - Compare oldHashes with newHash deciding on which chunk to be transmitted.
     - This module is also responsible for recreation of file on reception of **chunks**.
  - **4. Transmitter** Module sending the changed chunk to dropbox server. Chunker will provide this information to transmitter:
      - Old Hash of chunk        //Dropbox server is also storing hashes,server will find this hash in its DB and know this field needs updation
      - New Hash of chunk        //If data is modified in transit, server can detect data is malformed.
      - Actual data of chunk     //To be stored on object store
      - **On server on reception of chunks:** Actual file content/chunk is updated on object store. For userId, fileId, oldHash is replaced with newHash.
 ![ImgURL](https://i.ibb.co/TMDWjLr/dropbox-client-application.png)

#### Modules of Application Server
- **1. Communication Server**
- Recieves/Sends messages to/from client applications.
- If client is offline, it pools to client for updates as soon as client comes online(it responds).
### 2. **DB Server Updater** 
- Updates DB with actual file/photo/video contents.
- Client application can directly send/recv messages to object store.
### 3. **MOM** 
- Used for communication b/w server and client. Types of queues in MOM
  - *Request queues* Global queue shared by all clients.
  - *Response Queues* Sending update messages to each client. we need to create separate Response Queues for each subscribed client to share update messages
### 4. **Meta data Server Updater** 
- Stores meta data of files/photos/videos. 
### 5. **Synchronization Server** 
- Sends notification to all subscribed users of particular user about change of document/photo etc.
![ImgURL](https://i.ibb.co/1XMg8Zk/dropbox-server.png)

![ImgURL](https://i.ibb.co/fN50SNG/dropbox-server1.png)


## D. METADATA SERVER PARTIONING
### Hash Based Partioning
- Take hash of userID. Hashes from 1-100 goes to DB-server1, 100-200 goes to DB-server2 and so on.
- Still this approach can get overloaded.
- We should use **consistent hashing**.

## E. CACHING
### 1. Chunk cacher
- Stores frequently accessed chunks of files by particular user.
- **memcached** is fit for solution.
- **LRU** can be used as cache replacement policy.

## F. LOAD BALANCEER
- LB can be placed at 2 places.
### 1. B/W client application & Dropbox reciver component
### 2. B/W client application & meta data sever
- Client application later on will interact directly with meta data server after proper end point are discoverd.


  
