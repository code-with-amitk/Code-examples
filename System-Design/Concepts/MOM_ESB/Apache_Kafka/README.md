- **Kafka?**
  - [Applications/Use cases](#uc)
  - Kafka Implementations
    - [librdkafka](#lrdk)
- **Terms** 
  - [Consumer](#con)
  - [Messages](#msg)
  - [Producer](#pr)
  - [Topic](#tp)
  - [Broker](#br)
  - [Kafka connect](#kc)
  - Offset
  - [Streams](#st)
- Configuring kafka to communicate over JSON
  - [1. Install kafka and zookeeper](#install)

<a name=what></a>
## [Kafka](https://kafka.apache.org/intro)
- Kafka(Apache foundation) is open source distributed streaming platform. It has 3 main capabilities:
  - RW records like a message queue
  - Store records with fault tolerance
  - Process streams as they occur
```c
Producer1   Producer2   Producer3
  |           |           |
   ------    \/  ---------
        [kafka Broker]
  |-----------|-----------|
Consumer1   Consumer2   Consumer3
```
- **3 types of message delivery methods:**
  - _1. At-least-once semantics:_ Producer can keep on sending same message until Broker does not ACK.
  - _2. At-most-once semantics:_ Producer sends message once only & never retries, Even if ACK comes or not.
  - _3. Exactly-once semantics(EOS):_ A message is only seen once by the consumer of the message


- enterprise class [MOM](/System-Design/Concepts/MOM_ESB) works over TCP Protocol written in java. There are multiple replicas of Kakfa written in other languages.
- How kafka messaging works?
```c
                          kafka-Broker(192.168.0.1:9092)   //1. broker starts
consumer(0.2)                                              //2. consumer subscribes to topic
      --subscribe topic(t1)->
while(1){
..
}
                                                        producer(0.3) //3. Producer produces topic
                           Broker<--|topic=t1,payload="test"|--
  <--|topic=t1,payload="test"|-
```

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

<a name=bro></a>
### Broker
server in kafka which recieves message.

<a name=con></a>
### Consumer
Registers/Subscribes to a Topic and reads messages as they become available.

<a name=msg></a>
### Message / Record
- Data in kafka is called message. Each message has timestamp, a value, and an optional key.
```c
  key                                 Value                   timestamp
1234567 failed with the message “Alert: Machine Failed” at “2020-10-02T10:34:11.654Z”
```

<a name=pr></a>
### Producer
Applications/microservices that publishes/writes messages kakfa [Queue or Topic](#tp)

<a name=sch></a>
### Schemas
Schemas are imposed on messages (Eg: XML, JSON) so that messages can be understood easily.

<a name=top></a>
### Topics
Messages are categorized into topics. Topic = DB Table or Folder in Filesystem.
```c
```
- Events which are stored on servers/disks in form of QUEUE. These topics are replicated. Example:
  - _1._ Temprature changed from 40 to 45   //All are events
  - _2._ Train changed speed from 80 to 90 etc
- Events are not deleted after reading, but we can define how long kafka should keep the events. Topics are spread over a number of "buckets" located on different Kafka brokers makes it scalable. A common production setting is a replication factor of 3, i.e., there will always be three copies of topics. 
- **Usage of topics?** Microservices can talk to each other using topics.
```
                    ms-4 (Listening on topic/Consumer
                      /\  Does processing) ----publishes to other Queue --> |t101|t102|..|
                      |                                                     kakfa Queue
                      |
kafka topics  |t1|t2|t3|t4|...
                      /\
ms-1    ms2           |t3
                    ms-3(Publishing topic/Producer)
```

<a name=kc></a>
#### Kafka connect
Software/Library/Modules which fetches data from legacy systems(Eg: database, some SaS products) and put that into kafka queue for it to be consumed by other consumers.

<a name=br></a>
### Broker 
- A TCP server that listens(default 9092) for Topics(`<key=id,value=payload>`) from producers & provides topics to subscribed consumers.
- **Bootstrap Broker:**
  - On Init, kafka needs(at least one) broker called the bootstrap brokers. The client will connect to the bootstrap brokers specified by the bootstrap.servers configuration property and query cluster Metadata information which contains the full list of brokers, topic, partitions and their leaders in the Kafka cluster.

#### Offset 
A unique ID for a message within a Partition. This is how Kafka maintains the ordering and sequencing of messages.

<a name=st></a>
### Kafka Streams
This is not message from 1 application to other, but real-time flow of records. Records are `<key,value>` pairs.
```c
  --|key=a,value=x|---|key=c,value=z|---|key=b,value=y|-->
```
#### Stream APIs
APIs/Code for consuming/using streams. These APIs are publicly available as shared objects/crates.
