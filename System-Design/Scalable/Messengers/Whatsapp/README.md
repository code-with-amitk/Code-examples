**Whatsapp**
- [1. Requirements](#req)
- [2. BOE](#boe)
- [3. APIs](#api)

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
