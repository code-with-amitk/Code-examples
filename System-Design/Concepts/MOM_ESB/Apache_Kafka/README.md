- [What is Kafka](#what)
- [Kafka Application/Use Cases](#usecases)
  - [1. MOM](#mom)
  - [2. Analysis & Stream Processing](#analysis)
  - [3. Log Aggregation](#la)

<a name=what></a>
## Kafka
- Kafka(written in Java) is open source project

<a name=usecases></a>
## Kafka Application/Use Cases

<a name=usecases></a>
### 1. Messaging
- Kafka can working as MOM

<a name=analysis></a>
### 2. Analytics and stream processing
Applications sends real-time usage information (e.g., clicks, visitors, sessions, page views, and purchases) to Kafka Topics. Apache Spark reads messages from the various topics, transforms the data (map/reduce), and sends it to a data store such as Hadoop(via Flume). Data analytics tools(data visualization) can be added on top of the target data store.

<a name=la></a>
### 3. Log Aggregation
Application provides logs to Kafka topics, which sends them to log management applications(eg ElasticSearch, Logstash, Kibana). Kafka could be used in front of Logstash to receive large data volumes and allow Logstash to perform more-expensive operations at its own pace without losing messages
