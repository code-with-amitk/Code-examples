**Lambda / FaaS(Function as a service)**
- [Steps of running code in Lambda](#s)
- [Create lambda](#c)
- [Write source, Test in lambda](#w)

### Lambda is [Serverless](/System-Design/Concepts/AWS/Terms#sl)
- Some cloud providers call this as FaaS(Function as a service).
- **Advantages:**
  - *1. Lambda takes care of Scaling:* if load increases Lambda will provision new machines and run code there.
  - _2. No patching:_ Lambda takes care of patching and upgrades.
  - _3. Lambda is Event Driven:_ Lambdas event-driven model means you can integrate with a range of AWS services, but still ensure loose coupling.
  - _4. Cost:_ AWS charges only when code is running in lambda.
    
<a name=s></a>
### Steps of running code in Lambda
![ImgUrl](https://i.ibb.co/WWswQcw/lamdba.png)
1. **Angular client**: add images from S3
2. **Save/Delete Lambda Function:** handle image upload and delete events from S3, invoked by S3 when a new image is uploaded. The image details will be saved to DynamoDB
3. **Retrieve Image Details Lambda Function:** it will retrieve image details from DynamoDB and return JSON result
4. **Dynamo DB:** All interactions with DynamoDB will happen via the Lambda functions.
5. **API Gateway:** Provides image to web app using lambda

<a name=c></a>
### Creating Lambda
```c
AWS Management console > Lambda > Create Lambda
Author from scratch
name:             myLambda
Runtime:          Python 3.9(or your language of choice)
//Lambda will create an execution role named myLambda-role-i7t8fwvj, with permission to upload logs to Amazon CloudWatch Log
Create Function
```

<a name=w></a>
### Write source, Test in lambda
```c
//Write source in lambda
print("Hello world")

Press Test Button
START RequestId: 859acc88-061d-43f2-a28e-bbdcbec2945c Version: $LATEST
END RequestId: 859acc88-061d-43f2-a28e-bbdcbec2945c
REPORT RequestId: 859acc88-061d-43f2-a28e-bbdcbec2945c	Duration: 1.03 ms	Billed Duration: 2 ms	Memory Size: 128 MB	Max Memory Used: 36 MB	Init Duration: 110.76 ms

Add Trigger
- lambda can be triggered from different sources(as kafka, API g/w, cloudwatch etc)
- Also 3rd party AWS partners.
```
