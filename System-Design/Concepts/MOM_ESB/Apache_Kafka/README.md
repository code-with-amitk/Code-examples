- **Kafka?**
  - [Applications/Use cases](#uc)
  - Kafka Implementations
    - [librdkafka](#lrdk)
- **Terms** 
  - [Broker](#br)
  - [Consumer, Consumer Group](#con)
  - [High-water mark](#hwm)
  - [Messages](#msg)
  - [Offset](#off)
  - [Producer](#pr)
  - [Topics & Partitions](#tp)
  - [Replication & Fault Tolerance](#rf)
  - [Kafka connect](#kc)
  - [Streams](#st)
- Configuring kafka to communicate over JSON
  - [1. Install kafka and zookeeper](#install)

<a name=what></a>
## [Kafka](https://kafka.apache.org/intro)
Kafka(Apache) is distributed,scalable,fault tolerant,open source publish-subscribe messaging system. It can store the messages, replay back(to subscribers)
```c
Producer1   Producer2   Producer3   //microservice
  |           |           |
   ------    \/  ---------
        [kafka Broker]
  |-----------|-----------|
Consumer1   Consumer2   Consumer3   //microservice
```
**How kafka messaging works?**
```c
                          kafka-Broker(192.168.0.1:9092)   //1. broker starts
consumer                                                   //2. consumer subscribes to topic
      --subscribe topic(t1)->
while(1){
..
}
                                                        Producer //3. Producer produces topic
                           Broker<--|topic=t1,payload="test"|--
  <--|topic=t1,payload="test"|-
```
- **3 types of message delivery methods:**
  - _1. At-least-once semantics:_ Producer can keep on sending same message until Broker does not ACK.
  - _2. At-most-once semantics:_ Producer sends message once only & never retries, Even if ACK comes or not.
  - _3. Exactly-once semantics(EOS):_ A message is only seen once by the consumer of the message

### kafka Implementations
<a name=lrdk></a>
#### [librdkafka](https://github.com/edenhill/librdkafka)
This is C library implementation of the Apache Kafka protocol. librdkafka has no affiliation with and is not endorsed by The Apache Software Foundation.

<a name=uc></a>
### Applications/Use cases
<a name=uc></a>
### 1. Messaging
Kafka can working as MOM

#### 2. Analytics and stream processing
Applications sends real-time usage information (e.g., clicks, visitors, sessions, page views, and purchases) to Kafka Topics. 
Apache Spark reads messages from the various topics, transforms the data (map/reduce), and sends it to a data store such as Hadoop(via Flume). Data analytics tools(data visualization) can be added on top of the target data store.

#### 3. Log Aggregation
Application provides logs to Kafka topics, which sends them to log management applications(eg ElasticSearch, Logstash, Kibana). 
Kafka could be used in front of Logstash to receive large data volumes and allow Logstash to perform more-expensive operations at its own pace without losing messages.

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

#### Consumer Group
- Its possible that multiple consumers are intrested in listening to one [topic](#topic), kafka creates group of these consumers which are intrested in 1 topic.
- 1 partition can contain multiple topics. But all consumers in (consumer group 1) are interested in topic=1 only.
- consumer1 reads topic1 from partition-1, consumer2 reads topic1 from partition2.
- One consumer is assigned 1 partition. Different consumers can be responsible for different partitions
- **Advantages of approach?** By using consumer groups, consumers can be parallelized so that multiple consumers can read from multiple partitions on a topic, allowing a very high message processing throughput.
```c
                      |----- Kafka Broker-1 ---------|
                      |                              |
                      | |(Partition-1) t1, t2, ... | |
    |---------------> | |(Partition-3) t3, t4, ... | |      |----- Consumer Group 1(Topic-1)----|
    |                 |------------------------------|      |                                   |
  Producer                                                  | |consumer1, consumer2, consumer3| |
    |                 |------ Kafka Broker-2 --------|      |                                   |
    |---------------> |                              |      |-----------------------------------|
                      | |(Partition-2) t1, t5, ... | |
                      | |(Partition-3) t9, t8, ... | |
                      |------------------------------|

consumer1 will read topic1(t1) from Partition-1(Broker-1)
consumer2 will read topic1(t1) from Partition-2(Broker-2)
This ensures consumer group has all data stored on different partitions for Topic-1
```

<a name=hwm></a>
### High-water mark
- When subscriber reads from Leader. [Leader](#rf) never returns messages which have not been replicated to a minimum set of [ISRs](#isr).
- Leader keeps track of highest water mark. Highest watermark is the [offset](#off) for that partition replication.
- Example(in figure below): Leader does not return messages greater than offset ‘4’, as it is the highest offset message that has been replicated to all followers.

<img src=./images/high-water-mark.JPG width=600/>

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

<a name=tp></a>
### Topics & Partitions
#### Topics
- Same type of messages are grouped into topics. Topic is like DB Table or Folder in Filesystem. Topics are replicated.
- Messages written to partitions are immutable and cannot be updated.
```c
  msg1= {                         msg2= {
    deviceid=1                      deviceid=2
    info = {                        info = {
      create_time,                    create_time,
      device_config{core,speed}       device_config{core,speed}
    }                               }
  }                               }
---------topic=Device_Ready-------------------------------------
  
  msg1    msg2    msg3                       msg5    msg6    msgk
  ------topic=Device_Ready-------           ------topic-n-------
```
#### Partition (Provide Fault Tolerance)
- Partition is disk partition for storing topics. 1 topic can be stored on multiple paritions hosted on different [Brokers](#br).
- See Diagram on [Consumer Groups](#con);

<img src=./images/kafka_partition1.JPG width=600/>

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
