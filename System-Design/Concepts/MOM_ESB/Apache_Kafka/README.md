- **Kafka?**
  - [Applications/Use cases](#uc)
- **Terms** 
  - [Producer](#pr)
  - [Consumer](#con)
  - [Topic](#tp)
  - [Broker](#br)
  - [Kafka connect](#kc)
  - Offset
- Kafka Application/Use Cases
  - [1. MOM](#mom)
  - [2. Analysis & Stream Processing](#analysis)
  - [3. Log Aggregation](#la)
- Configuring kafka to communicate over JSON
  - [1. Install kafka and zookeeper](#install)

<a name=what></a>
## [Kafka](https://kafka.apache.org/intro)
Kafka(written in Java) is open source enterprise class [MOM](/System-Design/Concepts/MOM_ESB) works over TCP Protocol.
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
<a name=pr></a>
#### Producer
Applications/microservices that publishes/writes messages kakfa [Queue or Topic](#tp)

<a name=con></a>
#### Consumer
Registers/Subscribes to a Topic and reads messages as they become available.

<a name=tp></a>
### Topics/Events/Message
- Collection of events(specifically logs) which are stored on servers/disks in form of QUEUE. These topics are replicated. For example:
  - _1._ temprature changed from 40 to 45   //All are events
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
ms-1    ms2           |
                    ms-3(Publishing topic/Producer)
```

<a name=kc></a>
#### Kafka connect
Software/Library/Modules which fetches data from legacy systems(Eg: database, some SaS products) and put that into kafka queue for it to be consumed by other consumers.

<a name=br></a>
#### Broker 
A Kafka server that manages one or more Topics.

#### Offset 
A unique ID for a message within a Partition. This is how Kafka maintains the ordering and sequencing of messages.
