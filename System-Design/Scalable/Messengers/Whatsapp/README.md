**Whatsapp**
- [1. Requirements](#req)
- [2. BOE](#boe)
- [3. APIs](#api)
- [4. DB](#db)
  - [What DBs Used](#wd)

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

#### Relationship
```c
User 1----------* Message
User 1----------1 Push Notification Settings
Message 1----------1 Notification
User 1----------* Groups
User 1----------1 contact list
```

#### DB Tables
```c
// User Table
| user_id(pk) | name | Phone_no | password | Profile picture | settings | etc |

// Messages Table: store information about each message
| message_id(pk) | from_user_id(fk) | to_user_id(fk) | content_url | timestamp |
Note:
 - content(audio, video) is stored on HDFS or Amazon S3
 - Server generates unique id which is stored here
 - When a recipient receives a message with an image or video, the WhatsApp server retrieves the file from the file storage system using the unique id & sends the file to the recipient's device.

// Push Notification Settings Table: Store information about each user's push notification settings
| notification_id(pk) | user_id(fk) | how_frequent_to_push | etc |

// Groups Table: store information about each group chat
| group_id(pk) | user_id(fk) | list_of_members_in_group | group_chat_url | group_profile_picture

// Contact list Table: store information about each user's contacts
| contact_list_id(pk) | user_id(fk) | map <user_id, phone_no> | map <user_id, diplay_names> |

```
<a name=wd></a>
#### What databases Whatsapp uses to store data?

