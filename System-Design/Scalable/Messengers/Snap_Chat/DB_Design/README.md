## DB Design
- We can store information in SQL or noSQL database.

### 1. SQL DB Design
- **User's Table**
  - Has one-to-many relationship with photo table, since 1 user can have multiple photos.
```c
Primary Key: userID

| UserID | messageID | TextURL | VideoURL | Timestamp | src_UserID | email |
| ------ | --------- | ------- | -------- | --------- | ---------- | ----- |
| User_B | kanskna   | <>      |  <>      | 123       | User_A     |a@a.com|
```
- **Photo Table**
  - All photos which are posted by particular user. Each photo will have incremental photo-ID
  - Photos will be stored in any [distributed File Storage server: HDFS or GFS](/Operating_Systems/Linux/FileSystem)
```c
Primary Key: photo ID

| Photo-IDs | User-ID | Caption | location | Time of upload |   URL  |
| --------- | ------- | ------- | -------- | -------------- | ------ |
|    1      | user-A  | <>      |   <>     |  epoch time    |   -    |
|    4      | user-B  | <>      |   <>     |  epoch time    |   -    |
|    6      | user-A  | <>      |   <>     |  epoch time    |   -    |
```
- **Video Table**   //Similar to Photo Table
- **Follower Table**
  - let userA(follower) follows userB(followee).
```c
| Followee | map<Followers> |
| -------- | -------------- |
| UserB    | UserA          |
```

### 2. NoSQL DB Design
- We can store same data in [noSQL Databases(Eg: dynamoDB, Cassandra)](/System-Design/Concepts/Databases) since noSQL are highly scalable, hence highly available and low latency.
- **Photo Table (Key, value)**
  - Key would photoId and value would be object containing all metadata related to photo(Eg: location/url, timestamp, size etc)
```c
| UserID    |       <Key=PhotoIDs, value=Object_Containing_all_metadata>     |
| --------- | -------------------------------------------------------------- |
| userA     | key=photo-1, Value=Object<Location_of_photo, timestamp, size > |
            | key=photo-2, ...                                               |
```
- **Follower Table**
  - 
