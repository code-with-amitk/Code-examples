**Whatsapp**
- [1. Requirements](#req)
- [2. BOE](#boe)
- [3. APIs](#api)
- _4. DB Schema_
  - [DB Tables](#dbt)
  - [All Tables in 1 DB or Multiple DBs(Having distributed tables)](#1orm)
  - [SQL or NoSql or HDFS](#sn)
- _Use cases_
  - [1. Client sends Large Video/Image file](#u1)

<a name=req></a>
### 1. Requirements
#### Functional
- User Authentication
- Sender Send messages (txt, videos, Audio, Images)
- Status display of Receipents (Online, Offline, last seen)
#### Non-Functional
- Available
- Fast
- Reliable (Encyrption)
- Scalable: Handle large number of messages, users
#### Extended
- Group chat
- Broadcast messages

<a name=boe></a>
### 2. BOE
#### Bandwidth Estimates
- DAU(Daily Active Users):
  - World population: 7 x 10<sup>9</sup>. 7 Billion
  - DAU Whatsapp users: 30-40%: 2.1 10<sup>9</sup>. 2 Billion Users per day
- Incoming Data: 100kb x 2GB = 200 TB/Day. 200TB/86400 = 20MB/sec
  - some users send "Hi=100 bytes"
  - some users send images = 100kb
  - some users send videos = 100Mb
  - On Average, 1 user sends = 100kb/day.
#### Storage Estimates
- Incoming data: 200TB/day. 70 PB/year. 350PB for 5 years
- Postgres, MySQL, Oracle DB can store upto 1 PB of data. But remember as database size grows, DB queries start taking time. Need to implement sharding,caching,indexing
- Servers needed: 70 (for 1 year). Data can be recycled.

<a name=api></a>
### 3. APIs
- Whatsapp does not use REST APIs, rather it uses proprietary messaging protocol that is based on the **Signal Protocol**
- **Why Signal protocol**
  - This is Application layer protocol sitting over IP network.
  - This is designed as lightweight and optimized for mobile devices.
  - Contains additional features(such as message queuing, message retries, and message acknowledgments) that are not in REST APIs.

- [Signal Protocol Architecture Txt](images/signal_protocol_whatsapp.txt)

<img src=images/signal_protocol_whatsapp.png width=500/>

<a name=db></a>
### 4. DB Schema
#### Entities
- User
- Message
- Push Notification Settings
- Groups
- contact list
- Public,Pvt keys

#### Relationship
```c
User 1----------* Message
User 1----------1 Push Notification Settings
Message 1----------1 Notification
User 1----------* Groups
User 1----------1 contact list
```

<a name=dbt></a>
#### DB Tables
```c
// User Table
| user_id(pk) | username | Phone_no | password | Profile picture | settings | preferences | etc |

// Contact table: Contains information about a user's contacts
| contact_id(pk) | user_id(fk) | contact_phone_no | contact_display_name | status | last_seen |
  - user_id: is the user who owns the contact
  - status: Current status of contact he's online or offline
  - last_seen: stores the timestamp of the last time the contact was seen online
  
// Public key table: Stores public key of registered users
| key_id(pk) | user_id(fk) | public_key | key_type(RSA, Ecliptic curve) | key_status(Active,Revoked) |
  - key_id: uniquely identify each public key record
  - user_id:  identifies the user associated with the public key
  - public_key: stores the actual public key for the user
    => No need to save this encrypted but while sending use SSL/TLS so that its not tempered by MoM.

// Messages Table: store information about each message
| message_id(pk) | from_user_id(fk) | to_user_id(fk) | content_url | timestamp |
Note:
 - content(audio, video) is stored on HDFS or Amazon S3
 - Server generates unique id which is stored here
 - When a recipient receives a message with an image or video, the WhatsApp server retrieves the file from the file storage
   system using the unique id & sends the file to the recipient's device.

// Push Notification Settings Table: Store information about each user's push notification settings
| notification_id(pk) | user_id(fk) | how_frequent_to_push | etc |

// Groups Table: store information about each group chat
| group_id(pk) | user_id(fk) | list_of_members_in_group | group_chat_url | group_profile_picture

// Contact list Table: store information about each user's contacts
| contact_list_id(pk) | user_id(fk) | map <user_id, phone_no> | map <user_id, diplay_names> |
```

<a name=1orm></a>
#### All Tables in 1 DB or Multiple DBs(Having distributed tables)
> It's a design decision. No hard and fast rule.
##### All tables in 1 database
- Simplify management and maintenance, reduce the overall complexity of the system
- Easier to ensure consistency and integrity across all tables.
- Easier to implement backups and disaster recovery.

**Multiple DBs(Having distributed tables)**
- _Storing Frequently accessed Tables(Eg: User, contact tables) in multiple DBs:_
  - Reduce contention and improve overall response times by reducing the load on the main database and improving data access times
  - When multiple applications or users are accessing the same database simultaneously, there can be contention for resources such as CPU, memory, and I/O. 
- _Storing less frequently accessed tables(Eg:Public key table) in multiple DBs:_
  - help reduce the overall size and complexity of the main database and make it easier to manage

<a name=sn></a>
#### SQL or NoSql or HDFS
- User, contact, Public key on Postgres(SQL)
- NoSQL(MongoDb):
  - Storing chatlogs, media files, and message metadata
- Hadoop HDFS(Distributed file systems): 
  - To store and analyze large data sets

### Use cases
<a name=u1></a>
#### 1. Client sends Large Video/Image file
```c
      Alice
1GB > [converter] > MPEG/MP4
                      \/
                  [Fragementation]
                      \/
                  f1,f2..fn
                      \/
                  [Encrypt each fragment] < Alice Pvt key
                      \/
                            -----------Payload[f1]-------------->
```
<a name=u2></a>
#### 2. Last Seen
- Implemented using field last_seen in [contact table](#db).
