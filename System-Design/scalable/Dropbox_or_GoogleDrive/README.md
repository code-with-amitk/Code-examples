# DropBox/Google Drive/Cloud File Storage

# A. REQUIREMENTS
### A1. FUNCTIONAL
- **Word or Xls Document or Videos** User should be able to
  - ***Upload***
    - Create document
    - Write into document
    - Document should be auto-saved.
  - ***Download*** the documents.
  - ***Share*** files with other users
  - ***Synchronization*** Automatic synchronization between devices, i.e., after updating a file on one device, it should get synchronized on all devices.
  - ***Offline upload/edits*** User should be able to upload/edit while he's offline, information should go on drive as he comes online.
### A2. NON-FUNCTIONAL
- S<sup>3</sup> L<sup>3</sup> C<sup>2</sup> A<sup>3</sup> R<sup>2</sup> F
  - Scalable, Secure, SOA
  - Logging, Load, Latency
  - Cache(Invalidation, negative cache)
  - Available, Accurate, Analyze, Authenticate
  - Reliable, Redundant(Using DB)
  - Fast
### A3. Extended 
- **Snaphot of data** System should support snapshotting of the data, so that users can go back to any version of the files.

# B. BOE Calculations
### B1. Free Account User
- Free account user can use = 15 GB space.
- This is collective space, user can use it in docs, xls, videos (any way they want) but sum up should be < 15 GB.

| | Word Document | Xls Document | Videos |
| --- | --- | --- | --- |
| Max Size/Document | 2 MB | 20 MB | 1 GB |
| No of documents | 1000 | 100 | 10 |
| Size occupied | 2x10<sup>9</sup> | 2x10<sup>9</sup> | 1x10<sup>9</sup> |
> Total size occupied = 14 GB

### B2. For paid account
- 15 TB space allocated for basic paid account.

| | Word Document | Xls Document | Videos |
| --- | --- | --- | --- |
| Max Size/Document | 200 MB | 2000 MB | 1 TB |
| No of documents | 10000 | 10000 | 10 |
| Size occupied | 2x10<sup>12</sup> | 2x10<sup>12</sup> | 1x10<sup>12</sup> |
> Total size occupied = 15 TB

### B3. How many users are using Google Drive/Gmail?
- All users using Gmail are given their personal google-drive.

| Percentage & Population | |
| --- | --- |
| World Population(2019) | 7 Billion(10<sup>9</sup>) |
| 40% using internet | 28x10<sup>8</sup> |
| 50% of this 40% using Gmail | 28x10<sup>7</sup> |
| <ul><li>Free Users(50%)</li></ul> <ul><li>Paid Users(50%)</li></ul>| <ul><li>Space used by free Users(14x10<sup>7</sup>x15 GB)</li></ul> <ul><li>Space used by paid Users(14x10<sup>7</sup>x15 TB)</li></ul> |
> Total Space used = 14x15x10<sup>16</sup> + 14x15x10<sup>19</sup> = 210x10<sup>19</sup> = 10<sup>22</sup> bytes

# C. HLD/Design
## A. 1 Server, 1 User Design
### CASE-1: NEW FILE CREATION
#### WHAT HAPPENS ON CLIENT & SERVER
1. Normal User creates a gmail/google drive account. On server space of 15 GB gets reserved for user.
2. A sort of Dashboard is allocated to user on server, whenever user connects to Google Drive URL, dashboard is rendered to user.
3. User creates a file. A client Application running on user's machine sends these information to server
     - Unique Id assigned to user.  =>  userID
     - Unique Id assigned to file   =>  uniqueFID
     - Actual content of file (sent in JSON format/websockets)
     - startPtr of file
     - endPtr of file
     - sha3 hash calculated of file content
4. **Object-store-DB** Actual file-content/Photos/Videos are stored on seperate DB
     - Text, Photos, Videos stored on Object store DB   
5. **Meta-data server** stores following informtion:
   - File's Metadata is stored in following table
   
| userId | uniqueFileID (uniqueFID) | startPtr of File | endPtr of File | sha3HashOfFile | ActualFileLocation (PtrOnDB) | Directory structure | Shared-With |
| --- | --- | --- | --- | --- | --- | --- | --- |
| amit | amit102 | 0x42 | 0x506 | faga1B | DB_4-offset_89100 | dir1/dir2/file | user10,user41 |

![ImgURL](https://i.ibb.co/LNfsTc4/dropbox1.png)


### CASE-2: UPDATING THE EXISTING FILE
#### 1. WHAT HAPPENS ON CLIENT
- Let's suppose a file of 50kb already exists, maybe 500 lines. There are 2 cases here:
  1. User erases last 100 lines and adds new 100 lines. File size is still same but contents are changed.
  2. User erases last 100 lines and adds new 200 lines. File size is changed.
- **Hash based solution** 
  - We will pre-divide whole file into chunks. Chunk-1{0-100 lines=10kb}, Chunk-2, Chunk-3 and so on.
    - Bigger the file, larger the chunk size maybe.
    - Client will store hash of chunks.
    - Whenever user writes to file, Client Application will recalculate the hashes for chunk.
      - Whichever hash mismatches, means this chunk is changed & this needed to be transmitted to server.
- **Modules of Client Application** We can create different modules inside Client-Application doing above task.
  1. ***Internal Metadata Database*** Stores all files user have, no of chunks, versions, start, endPtr, pointer to structure storing hash of chunks.
    
| fileUniqueID | No of chunks | sizeofChunk | fileStartPointer | fileEndPointer | ptrTo_hash_structure | version |
| --- | --- | --- | --- | --- | --- | --- |
| 0x8129 | 4 | 200 bytes | 0x45 | 0x789 | 0x492m | 4 |
                                               |
                                               | 
                                              \/
                                        | hashOf-Chunk1 | hashOf-Chunk2 | hashOf-Chunk3 | hashOf-Chunk4 |
                                          hashOf_chunkStructure

  2. ***Watcher*** This will keep watch on workspace for any changes made by user. When user changes file.
     - It will notify chunker about the change.
     - This also implements **select()/poll()/epoll()** API, it listens for communication from drop-box server.
  3. ***Chunker*** Module doing all processing about chunks. Fills/updates *Internal Metadata database*.
     - Decide chunk-size on the fly based on directions from dropbox server.
     - On reception of message from watcher, Calculate hash of all the chunks.
     - Compare oldHashes with newHash deciding on which chunk to be transmitted.
     - This module is also responsible for recreation of file on reception of **chunks**.
  4. ***Transmitter*** Module sending the changed chunk to dropbox server
     - Chunker will provide this information to transmitter:
       - Old Hash of chunk        //Dropbox server is also storing hashes,server will find this hash in its DB and know this field needs updation
       - New Hash of chunk        //If data is modified in transit, server can detect data is malformed.
       - Actual data of chunk     //To be stored on object store
 ![ImgURL](https://i.ibb.co/TMDWjLr/dropbox-client-application.png)

#### 2. WHAT HAPPENS ON SERVER
- Server was storing actual files on `Object store` & file,related information on `metadata server`.
- Server gets information from Transmitter:
  - For user=uniqueUserID, uniqueFileID, oldHash, newHash, actual changed content are changed.   //When existing file updated
    - Updates metadata server, object store database.
  - For user=uniqueUserID, new file is created, size, chunk-hashes, actual file content.
