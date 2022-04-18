**Dynamo DB**
- [Amazon RDS vs DynamoDB](#vs)
- [DynamoDB Accelrator](#ac)

## Dynamo DB (Key,value DB store)
- This is [serverless](/System-Design/Concepts/AWS/). Provides single-digit millisecond retrieval at any scale, stored on **SSD.**
- **Storage:** Supports both: document data model, key value data model
```c
 key    value
  1   name:Amit,Address: 123 Any Street, Favorite drink: Medium latte
  2   name:Mary,Address: 100 Main Street,Birthday: July 5, 1994
```
- **Consistent** by default. Consistency across all copies of data is usually reached within a second
- **Scaling:** As size of grows/shrink DB automatically grows/shrinks.

<a name=ac></a>
### DynamoDB Accelrator
This is used to enhance read performance of applications reading from dynamo db.

<a name=vs></a>
### Amazon RDS vs DynamoDB
||RDS|DynamoDB|
|---|---|---|
|Schema|Controlled by admin|Key-value pair (No schema required)|
|Ownership of data|Controlled by admin|not controlled|
|Usecase|Where multiple tables are present & data pulled from multiple tables & join is done|everything else|
