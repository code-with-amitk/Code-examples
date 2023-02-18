- [Applications/Use cases](#uc)
- [Terms: Broker, Consumer, Consumer Group, High-water mark, Topics & Messages, Offset, Producer, Partitions, Replication & Fault Tolerance, Kafka connect, Streams](Terms)
- Configuring kafka to communicate over JSON
  - [1. Install kafka and zookeeper](#install)

<a name=what></a>
## [Kafka](https://kafka.apache.org/intro)
- Kafka(Apache) is distributed,scalable,fault tolerant,open source publish-subscribe messaging system. It can store the messages, replay back(to subscribers)
- **How kafka messaging works?**
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
- **Kafka usecases:**
  - _1. Messaging:_ Kafka can working as MOM
  - _2. Analytics and stream processing:_ Applications sends real-time usage information to Kafka Topics. Data analytics tools can be added on top of the target data store.
  - _3. Log Aggregation:_ Application provides logs to Kafka topics, which sends them to log management applications(eg ElasticSearch, Logstash, Kibana)

<a name=images/kafka.png width=500/>


