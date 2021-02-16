## 1. MOM(Message Oriented Middleware)
- Processes can communicate using MOM. MOM is commercial implementations of MQ which provides high availability.
- **Message broker?** Service that gathers and routes messages from senders to the right receivers.
- **Publisher/subscriber model?** Sender/Publisher of message does not send message directly to receiver/subscriber. Subscribers registers beforehand for message publication and once message is published its received by subscriber.
- **MOM Examples:**  IBM MQ, Apache(Kafka, RocketMQ), Amazon SQS(Simple Queue Service), Amazon SNS(Simple Notification Service), RabbitMQ

||SQS|Kafka|
|---|---|---|
|Consumer types|Single Consumer type|Consumers can be different types|
|On stream data analytics|no|yes|

## ESB(ENTERPRISE SERVICE BUS) 
- ESB does more tasks wrt MOM. ESB can route, log, and performs other 'technical' (i.e. non-business) functions on messages. 
