- [What is MOM/Message Oriented Middleware](#mom)
  - [1. Terms](#terms)
- [ESB(Enterprise Service Bus](#esb)

<a name=mom></a>
## MOM(Message Oriented Middleware)
- This is a Message Queue where Processes(written in different languages on diffeernt OS) can communicate with each other. It's high availabile. Examples
  - IBM MQ, Apache(Kafka, RocketMQ), Amazon SQS(Simple Queue Service), Amazon SNS(Simple Notification Service), RabbitMQ
```console
                          |      SQS            |             Kafka                |
    Consumer types       | Single Consumer type | Consumers can be different types |
On stream data analytics |       no             |               yes                |
```

<a name=terms></a>
### 1. Terms
- *Message broker?* Service that gathers and routes messages from senders to the right receivers.
- *Publisher/subscriber model/[Observer DP](/Languages/Programming_Languages/c++/Design_Pattens)?* Subscribers registers for message publication and once message is published its received by subscriber.

<a name=esb></a>
## ESB / Enterprise Service Bus
- ESB does more tasks wrt MOM. ESB can route, log, and performs other 'technical' (i.e. non-business) functions on messages. 
