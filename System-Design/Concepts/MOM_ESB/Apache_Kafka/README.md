- [What is Kafka](#what)

<a name=what></a>
## Kafka
- Kafka(written in Java) is open source project, which can be used in following use cases:
  - **1. Messaging:** Working as MOM
  - **2. Analytics and stream processing:** Applications sends real-time usage information (e.g., clicks, visitors, sessions, page views, and purchases) to Kafka Topics. Apache Spark reads messages from the various topics, transforms the data (map/reduce), and sends it to a data store such as Hadoop(via Flume). Data analytics tools(data visualization) can be added on top of the target data store.
  - **3. Log Aggregation:** Application provides logs to Kafka topics, which sends them to log management applications(eg ElasticSearch, Logstash, Kibana). Kafka could be used in front of Logstash to receive large data volumes and allow Logstash to perform more-expensive operations at its own pace without losing messages
