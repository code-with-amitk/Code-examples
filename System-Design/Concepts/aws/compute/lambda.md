## Lambda(Serverless Architecture)
  - **What**
    - you can upload your code and create a Lamdba function
    - Lambda takes care of provisioning and managing the servers that you use to run the code
    - do not have to worry about operating systems, patching, scaling etc
    - AWS Lambda runs your code in response to events. 
      - These events could be changes to the data in an Amazon S3 bucket or an Amazon Dynamo DB table
  -  **Why to use lambda**
    - Just need to upload the code, then scaling, load balancing is done by lamba.
    - Lambdas event-driven model means you can integrate with a range of AWS services, but still ensure loose coupling.
  - FaaS(Function as a service)
    - some cloud providers call this as “Function as a Service” FaaS.
    
### How Lambda works
![ImgUrl](https://i.ibb.co/WWswQcw/lamdba.png)

- **Steps**
  1. ***Angular client***: add images from S3
  2. ***Save/Delete Lambda Function***
    - handle image upload and delete events from S3.
    - invoked by S3 when a new image is uploaded.
    - The image details will be saved to DynamoDB
  3. ***Retrieve Image Details Lambda Function***
    - it will retrieve image details from DynamoDB and return JSON result
  4. ***Dynamo DB***
    - All interactions with DynamoDB will happen via the Lambda functions.
  5. ***API Gateway***
    - Provides image to web app using lambda
