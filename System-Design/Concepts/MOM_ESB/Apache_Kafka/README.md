- [What is Kafka](#what)
- [Terms: Producer, Consumer, Topic, Broker, Offset](#terms)
- Kafka Application/Use Cases
  - [1. MOM](#mom)
  - [2. Analysis & Stream Processing](#analysis)
  - [3. Log Aggregation](#la)
- Configuring kafka to communicate over JSON
  - [1. Install kafka and zookeeper](#install)

<a name=what></a>
## Kafka
- Kafka(written in Java) is open source enterprise class [MOM](/System-Design/Concepts/MOM_ESB).

<a name=terms></a>
## Terms
- _Producer_ Publishes messages to a Topic.
- _Consumer_ Registers/Subscribes to a Topic and reads messages as they become available.
- _Topic_ A named channel/queue.
- _Broker_ A Kafka server that manages one or more Topics.
- _Offset_ A unique ID for a message within a Partition. This is how Kafka maintains the ordering and sequencing of messages.

## Kafka Application/Use Cases
<a name=mom></a>
### 1. Messaging
Kafka can working as MOM

<a name=analysis></a>
### 2. Analytics and stream processing
Applications sends real-time usage information (e.g., clicks, visitors, sessions, page views, and purchases) to Kafka Topics. 
Apache Spark reads messages from the various topics, transforms the data (map/reduce), and sends it to a data store such as Hadoop(via Flume). Data analytics tools(data visualization) can be added on top of the target data store.

<a name=la></a>
### 3. Log Aggregation
Application provides logs to Kafka topics, which sends them to log management applications(eg ElasticSearch, Logstash, Kibana). 
Kafka could be used in front of Logstash to receive large data volumes and allow Logstash to perform more-expensive operations at its own pace without losing messages.

## Configuring kafka to communicate over JSON
<a name=install></a>
### 1. Install kafka and zookeeper
```c
# tar -zxf ZooKeeper-3.4.9.tar.gz
export PATH=$PATH:$<Zookeeper-Install-Path>/zookeeper-3.4.9/bin
# tar -zxf kafka_2.11-0.10.1.1.tgz			//
export PATH=$PATH:<Kafka-Install-Path>/zookeeper-3.4.9/bin
```
