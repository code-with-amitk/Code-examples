**Kafka Producer Consumer**
- [a. Start kafka Broker, zookeeper](#s1)
- [b. Create a Topic](#s2)
- [c. Set consumer in listening state, Consumer will read Event/Message](#s3)
- [d. Write Event/Message into topic from Producer](#s4)

## Using CLI Tools
<a name=s1></a>
#### a. Start kafka Broker, zookeeper
FROM https://kafka.apache.org/quickstart
```c
Ubuntu machine 
$ wget https://dlcdn.apache.org/kafka/3.0.0/kafka_2.13-3.0.0.tgz    //1. Get latest Kafka release and extract it
$ cd kafka_2.13-3.0.0

//From Another terminal
$ bin/zookeeper-server-start.sh config/zookeeper.properties         //2. Start ZooKeeper service. Soon, ZooKeeper will no longer be required by Apache Kafka

//From Another Terminal
$ bin/kafka-server-start.sh config/server.properties            //3. Start the Kafka broker service
```
<a name=s2></a>
#### b. Create a [Topic](/System-Design/Concepts/MOM_ESB/Apache_Kafka/README.md#tp)
```c
//Another Terminal
$ bin/kafka-topics.sh --create --partitions 1 --replication-factor 1 --topic quickstart-events --bootstrap-server localhost:9092
```
<a name=s3></a>
#### c. Set consumer in listening state, Consumer will read Event/Message
```c
//Another Terminal
$ bin/kafka-console-consumer.sh --topic quickstart-events --from-beginning --bootstrap-server localhost:9092
Event,Message-1
Event,Message-2
```
<a name=s4></a>
#### d. Write Event/Message into topic from Producer
```c
//Another Terminal
$ bin/kafka-console-producer.sh --topic quickstart-events --bootstrap-server localhost:9092
Event,Message-1
Event,Message-2
```
