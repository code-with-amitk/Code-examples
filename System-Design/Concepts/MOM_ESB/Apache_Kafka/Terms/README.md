**Terms**
  - [Broker](#br)
  - [Consumer, Consumer Group](#con)
  - [High-water mark](#hwm)
  - [Messages](#msg)
  - [Offset](#off)
  - [Producer](#pr)
  - [Topics & Messages](#tm)
  - [Replication & Fault Tolerance](#rf)
  - [Kafka connect](#kc)
  - [Streams](#st)


## Terms
<a name=br></a>
### Broker
- TCP Server(listening on 9092) which recieve Topics(`<key=id,value=payload>`) and store them. There is always cluster of Brokers for storing the [topics](#tp)
- **Bootstrap Broker:**
  - On Init, kafka needs(at least one) broker called the bootstrap brokers. The client will connect to the bootstrap brokers specified by the bootstrap.servers configuration property and query cluster Metadata information which contains the full list of brokers, topic, partitions and their leaders in the Kafka cluster.

<a name=con></a>
### Consumer
- Registers/Subscribes to a Topic and reads messages as they become available.
- Consumers can read messages from any Partition they choose.


#### Consumer Group (For Scalability & Fault Tolerance)
- Kafka consumers are separate physical nodes which want to read messages.
- Internally inside kafka each consumer is identified by a unique consumer ID and other attributes.
- Consumer informations is stored in Consumer Group.
- A Consumer Group is group consumers which are intrested in 1 topic.
- 1 consumer reads 1 partition only
- **topic="__consumer_offsets"**
  - This is a special topic stores all information of consumers of a group.
  - It maintain committed offsets, consumes messages, consumerId etc.
- **Scalability & fault-tolerant using Consumer Group**
  - Consumer1 reads from Partition1
  - Consumer2 reads from Partition2
  - Along with consumer offset, Topic offset is maintained.
  - Consumer1 does not need to read Partition2 and viceversa.

<a name=hwm></a>
### High-water mark
- When subscriber reads from Leader. [Leader](#rf) never returns messages which have not been replicated to a minimum set of [ISRs](#isr).
- Leader keeps track of highest water mark. Highest watermark is the [offset](#off) for that partition replication.
- Example(in figure below): Leader does not return messages greater than offset ‘4’, as it is the highest offset message that has been replicated to all followers.

<img src=../images/high-water-mark.JPG width=600/>

<a name=msg></a>
### Message / Record
- Data in kafka is called message. Each message has timestamp, a value, and an optional key.
```c
  key                                 Value                   timestamp
1234567 failed with the message “Alert: Machine Failed” at “2020-10-02T10:34:11.654Z”
```

<a name=off></a>
### Offset
- Each message is assigned a unique ID(sequence number, offset), which monotonically increases on that [Partition](#tp)
- Offset sequences are unique only to each partition. This means, to locate a specific message, we need to know the Topic, Partition, and Offset number.

<a name=pr></a>
### Producer
Applications/microservices that publishes/writes messages kakfa [Queue or Topic](#tp)

<a name=rf></a>
### Replication & Fault Tolerance
- Every topic can be replicated to multiple Kafka brokers to make the data fault-tolerant and highly available. [Digram](#con). Each topic partition has one leader broker and multiple replica (follower) brokers
#### Leader
- Leader is responsible for partitions(not topics).
- Every partition has one Kafka broker acting as a leader.
- Partition Leader information is stored on [Zookeeper](System-Design/Concepts/Databases/Database_Scaling/Sharding/README.md#cs).
- All Read/Write operation as performed by Partition Leader, hence All producers & consumers talk to zookeeper to address of leader of partition.
#### Follower/Replica
Followers replicate the leader’s data to serve as a ‘backup’ partition & can become leader when leader goes down
##### In sync Replica (ISR)
An ISR is a broker that has the latest data for a given partition. A leader is always an in-sync replica. Only ISRs are eligible to become partition leaders.

<a name=sch></a>
### Schemas
Schemas are imposed on messages (Eg: XML, JSON) so that messages can be understood easily.

<a name=tm></a>
### Topics & Messages
- Same type of messages are grouped into topics. Topics are replicated. Messages written to partitions are immutable and cannot be updated.

### Partition (Provide Fault Tolerance)
- This is **not Disk Partition**
- **What?** Partition is way of splitting data inside [topic](#tm)
- 1 partition will Always have 1 Topic. 1 partition cannot have store 2 topics.

<a name=kc></a>
#### Kafka connect
Software/Library/Modules which fetches data from legacy systems(Eg: database, some SaS products) and put that into kafka queue for it to be consumed by other consumers.

<a name=st></a>
### Streams
This is not message from 1 application to other, but real-time flow of records. Records are `<key,value>` pairs.
```c
  --|key=a,value=x|---|key=c,value=z|---|key=b,value=y|-->
```
#### Stream APIs
APIs/Code for consuming/using streams. These APIs are publicly available as shared objects/crates.
