**MOM/Message Oriented Middleware**

- **Terms**
  - [1. Message broker](#mb)
  - [2. Publisher/subscriber](#ps)
- [ESB(Enterprise Service Bus](#esb)

## MOM(Message Oriented Middleware)
This is a Message Queue where Processes(written in different languages on diffeernt OS) can communicate with each other. It's high availabile. Examples
  - IBM MQ, Apache(Kafka, RocketMQ), Amazon SQS(Simple Queue Service), Amazon SNS(Simple Notification Service), RabbitMQ
```console
                          |      SQS            |             Kafka                |
    Consumer types       | Single Consumer type | Consumers can be different types |
On stream data analytics |       no             |               yes                |
```

### Terms
<a name=mb></a>
#### Message broker
Service that gathers and routes messages from senders to the right receivers.
<a name=ps></a>
#### Publisher/subscriber model/[Observer DP](/Languages/Programming_Languages/c++/Design_Pattens)? 
Subscribers registers for message publication and once message is published its received by subscriber.

<a name=esb></a>
## ESB / Enterprise Service Bus
ESB does more tasks wrt MOM. ESB can route, log, and performs other 'technical' (i.e. non-business) functions on messages. 
