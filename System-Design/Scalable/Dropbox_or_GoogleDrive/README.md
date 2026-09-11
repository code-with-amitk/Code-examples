

- [Requirements](#req)
- [BOE](#boe)
- [HLD](#hld)
  - [1. New File Creation](#new_file_creation)
    - [Fault Tolerance (Client Side)](#Fault_Tolerance)
    - [Idempotency Handling (Server Side)](#Idempotency_Handling)
  - [2. Edit Existing File](#edit)

# Distributed DropBox/Google Drive/Cloud File Storage?
This is file hosting service. Securely storing data on Distributed remote servers. Read:Write ratio is same.

<a name=req></a>
# 1. Requirements
- **Functional:**
  - *1.* File upload/download/edit supported simultaneously by multiple users
  - *2.* Offline editing. User is offline, he edits the file, Once User comes online information should go on drive.
  - *3.* After updating a file on one device, it should get synchronized on all devices.
- **Non-functional:**
  - Highly available
  - Eventual consistent
- **Extended:**
  - Snaphot of data: System should support snapshotting of the data, so that users can go back to any version of the files.

<a name=boe></a>
# 2. BOE

|World Population|InternetUsers(60%)|DropBox users(2%)|Daily Active users(10~12%)|
|---|---|---|---|
|7 Billion //Year 2020|7 x 0.6 = 4.2 Billion|4.2 x 0.2 = 840 Million |840 x .12 = 100 Million|

- **Storage Estimates:** Assume On average each user has 500 file/photos daily. 
  - Each file=100KB. Storage/day 100M x 100K x 500 = 5PB. For 5 years = 5 x 30 x 12 x 5 = 9ExaBytes

- **Traffic Estimates:** Assume 1M active users/min. Each sending 100KB file. 100GB/min. 166MB/sec

<a name=hld></a>
# 3. HLD
```
|--- laptop ------|                    |--------------- Datacenter --------------------------------------------|
|User -> ClientApp| --> GLB(GlobalLB)  |                                                                       |
|--------- | -----|        \/          |                                                                       |
           |           Regional LB  -------> Nginx ---> KubernetsIngressLB ---> AppServer --metadata--> SQLDB  |
           |                           |                                                                       |
           |----------upload FILE CHUNK using presigned URL --------------> Object Store                       | 
                                       |-----------------------------------------------------------------------|
File's Metadata table:   
file_id, owner, filename, size, chunks, object-store keys, version
```

<a name=new_file_creation></a>
## 1. New File Creation
1. User creates a new file. Client Application running on user's machine sends following meta data (userId, fileId, file content, hash of file) to Appserver
2. Server will store metadata to SQL DB and generate a pre-signed URL and sent to client App
3. Client App will send file chunks to pre signed URL and file is assemble inside object store

<a name=Fault_Tolerance></a>
### Fault Tolerance (Client Side)
```
file => chunk-0(10-30), chunk-1(31-60), chunk-2(61-90)
```

**1. ClientApp crashes after sending chunk-0**
- Once clientApplication restarts, it will get information from AppServer that chunk-0 is received and will start from chunk-1

<a name=Idempotency_Handling></a>
### Idempotency Handling (Server Side)
- ClientApp sends chunk-0, chunk-1. Server recieved chunk-0, chunk-1 and sends ACK1, ACK2. ClientApp recieves ACK1 & network failure happened, ClientApp did not recieve ACK2.
- Network resumes and clientApp sends chunk-1 again.
- In order for server to not create 2 copies of chunk-1, Server need to maintain a idempotency key which is(file_id + version + chunk_number). if same key is found duplicate is rejected.

<a name=edit></a>
## 2. Edit Existing File
- Let's suppose a file of 50kb already exists, maybe 500 lines. There are 2 cases here:
  - *a.* User erases last 100 lines and adds new 100 lines. File size is still same but contents are changed.
  - *b.* User erases last 100 lines and adds new 200 lines. File size is changed.
    - **Hash based solution:** We will pre-divide whole file into chunks. Chunk-1{0-100 lines=10kb}, Chunk-2, Chunk-3 and so on.
    - Client will store hash of chunks. Whenever user writes to file, Client Application will recalculate the hashes for chunk. Whichever hash mismatches, means this chunk is changed & this needed to be transmitted to server.

<a name=flow></a>
# Flow Diagram
- *1-6.* Same as [Facebook newsfeed]()
- *7.* Application server stores connection info in conn_db. Push file Content, MetaData recieved from client on [MOM]().
- *8.* Updater will receive notification, stores file Content on [Object Store]() and meta data on [SQL DB]().
- *9.* Pooler service keeps on pooling for changed row from Meta-data server and recieves notification, it Reads newly/changed added row. Read userId, fileId and pushes on MOM.
- *10.* Acknowledgement service will recieve notification from MOM, gets connection information from conn-DB and sends ACK to userId for FileID.

<img src=Dropbox.jpg width=1000 />

<a name=db></a>
# DB
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
