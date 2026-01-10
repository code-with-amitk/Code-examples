**MOM(Message Oriented Middleware)/Broker**
- Comparison
  - [SQS vs Kafka](#vs1)
  - [Broker vs Database](#vs2)
- [Kafka](#kafka)
- Examples
  - [Apache Kafka](Apache_Kafka)
- [ESB(Enterprise Service Bus](#esb)

## MOM / Broker
Message Queue where Processes(written in different languages on diffeernt OS) can communicate with each other. It's high availabile. Examples
  - IBM MQ, Apache(Kafka, RocketMQ), Amazon SQS(Simple Queue Service), Amazon SNS(Simple Notification Service), RabbitMQ
```c
Producer1   Producer2   Producer3   //microservice
  |           |           |
   ------    \/  ---------
        [MOM Broker]
  |-----------|-----------|
Consumer1   Consumer2   Consumer3   //microservice
```

<a name=vs1></a>
#### SQS vs Kafka
||SQS|Kafka|
|---|---|---|
|Consumer types|Single|Different|
|Onstream Analytics|No|Yes|

<a name=vs2></a>
#### Broker vs DB
||Database|Broker|
|---|---|---|
|Storage|keep data until it is explicitly deleted|Delete a message when it has been successfully delivered to its consumers|
|Search|Supports different ways(eg: Secondary index)|Provides methods to subscribe|
|Writing|Data can be overwritten|Append only|

<a name=Kafka></a>
## [Kafka](https://code-with-amitk.github.io/System_Design/Concepts/index.html)
* Message delivery methods
* Architecture
* Terms: Cluster, Consumer, Consumer Group, Broker, Topics & Messages, Stream
* Replication & Fault Tolerance: Leader, Replica, High-water mark

<a name=esb></a>
## ESB / Enterprise Service Bus
ESB does more tasks wrt MOM. ESB can route, log, and performs other 'technical' (i.e. non-business) functions on messages. 
