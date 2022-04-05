**Lambda / FaaS(Function as a service)**
- [Lambda is Serverless](#sl)
- [Steps of running code in Lambda](#s)

## Lambda
<a name=sl></a>
### Lambda is [Serverless](/System-Design/Concepts/AWS/) Architecture
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
