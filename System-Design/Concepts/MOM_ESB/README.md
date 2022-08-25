**MOM(Message Oriented Middleware)/Broker**

- **Terms**
  - [1. Message broker](#mb)
- [ESB(Enterprise Service Bus](#esb)
- Examples
  - [Apache Kafka](Apache_Kafka)

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
||SQS|Kafka|
|---|---|---|
|Consumer types|Single|Different|
|Onstream Analytics|No|Yes|

## Terms
<a name=mb></a>
#### Broker
Service that gathers and routes messages from senders to the right receivers.

<a name=esb></a>
## ESB / Enterprise Service Bus
ESB does more tasks wrt MOM. ESB can route, log, and performs other 'technical' (i.e. non-business) functions on messages. 
