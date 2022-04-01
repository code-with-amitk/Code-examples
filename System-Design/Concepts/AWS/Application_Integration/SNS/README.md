- [Simple Notification Service / SNS](#sns)
- [Simple Queue Service / SQS](#sqs)

<a name=sns></a>
### SNS
- Publisher/Subscriber service same as [kafka](/System-Design/Concepts/MOM_ESB/Apache_Kafka).
- Subscribers:
  - can be web servers, email addresses, AWS Lambda functions, or several other options.
  - Subscriber can subscriber to 1 or more [topics](/System-Design/Concepts/MOM_ESB/Apache_Kafka#tp).

<a name=sqs></a>
### SQS
- This is is a message queuing service.
- **Advantages:** Messages are not lost. Messages are buffered if consumer is slow/dead.
```c
//Drawbacks without SQS
  process1  >>message>> process2    //if process2 is dead/busy then message would be lost
  
//With SQS
                Queue
  process1  >>|message2,message1|>> process2    //As soon process2 comes online it removes message from top
```
