- **DropBox/Google Drive/Cloud File Storage?**
  - This is file hosting service. Securely storing data on remote servers. Read:Write ratio is same.
  - If files are stored/transffered in smaller chunks(eg: 4MB) it will save lot of BW and space.
  - *Advantages?* 
    - Data is available anytime,anywhere on any device(mobile,linux,windows etc).
    - Reliable(multiple copies are stored) data will not be lost.

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

### 3.1 Use Cases
- **1 New File Creation**
  - *a.* User creates a file. A client Application running on user's machine sends following information (userId, fileId, file content, hash of file)
  - *b.* Server stores text/photo/video on [Object-DB]() and following on meta-data SQL server.
```c
File's Metadata table:
   
| userId | uniqueFileID (uniqueFID) | startPtr of File | endPtr of File | sha3HashOfFile | ActualFileLocation (PtrOnDB) | Directory structure | Shared-With |
```

- **2 Updating Existing File**
  - Let's suppose a file of 50kb already exists, maybe 500 lines. There are 2 cases here:
    - *a.* User erases last 100 lines and adds new 100 lines. File size is still same but contents are changed.
    - *b.* User erases last 100 lines and adds new 200 lines. File size is changed.
      - **Hash based solution:** We will pre-divide whole file into chunks. Chunk-1{0-100 lines=10kb}, Chunk-2, Chunk-3 and so on.
      - Client will store hash of chunks. Whenever user writes to file, Client Application will recalculate the hashes for chunk. Whichever hash mismatches, means this chunk is changed & this needed to be transmitted to server.

### 3.2 Flow
- *1-6.* Same as [Facebook newsfeed]()
- *7.* Application server stores connection info in conn_db. Push file Content, MetaData recieved from client on [MOM]().
- *8.* Updater will receive notification, stores file Content on [Object Store]() and meta data on [SQL DB]().
- *9.* Pooler service keeps on pooling for changed row from Meta-data server and recieves notification, it Reads newly/changed added row. Read userId, fileId and pushes on MOM.
- *10.* Acknowledgement service will recieve notification from MOM, gets connection information from conn-DB and sends ACK to userId for FileID.

<img src=Dropbox.jpg width=1000 />

### 3.3 [Client Application](Client_Application)

## 4. DB
- **Data Partitioning?** We can use Hash based [Sharding](/System-Design/Concepts/Databases/Database_Scaling). Take hash of fileId. Hashes from 1-100 goes to DB-server1, 100-200 goes to DB-server2 and so on.
  - Sharding based on Hash of fileId can fail on overloaded environment, We should use [Consistent hashing](/System-Design/Concepts/Hashing)
- **[Caching](/System-Design/Concepts/Cache)?** Before Meta-data-DB: Memcached

## 5. Load Balancers
- [Where Load Balancer can be placed](/System-Design/Concepts/Load_Balancer)? 
  - *a.* B/W client application & Application server. 
  - *b.* B/W client application & meta data sever

## 6. [Overall Tradeoffs/Bottlenecks & correction](/System-Design/Concepts/Bottlenecks_of_Distributed_Systems/Bottlenecks.md)
- *1.* if 2 users are viewing same file at a time, how consistent view can be provided?
  - *Solution:* 
    - Introduce a synchronization server will read meta-data server and will provide info to users.
    - Instead of transmitting entire files from clients to the server or vice versa, we can just transmit the difference between two versions of a file
- *2.* If high number of clients are connected system may respond slow.
  - *Solution:*
    - Provide MOM between Application server & clients which will queue client requests.
    - Provide MOM between synchronization server & clients. MOM can queue millions of requests.
- *3.* Sharding based on Hash of fileId can fail on overloaded environment.
  - Solution: Consistent hashing

## [7. Adjusting to changing requirements](/System-Design/Concepts/Changing_Requirements/README.md)
