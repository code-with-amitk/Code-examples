**Identity and Access Management / IAM**
- Terms
  - [AWS Account Root User](#r)

## IAM
- IAM enables you to manage access to AWS services and resources securely.   
- With IAM we can configure access based on company’s security needs. 

### Terms
<a name=r></a>
#### AWS Account Root user
- When we create AWS account(using email, password), a root user is created. It has complete access to all the AWS services and resources in the account.
- **Best Practice?**
  - Do not use root user to perform day-to-day tasks, instead create a IAM user and assign it permissions to perform tasks(eg:create other users).
  - Then, continue to create other IAM users, and access those identities for performing regular tasks throughout AWS

<a name=iu></a>
#### IAM users
- This is the identity that we create in AWS. It represents the person or application that interacts with AWS services and resources. It consists of a name and credentials.
- _Grant permissions:_
  - IAM user is created with NO PERMISSIONS(even no permissions to login).
  - Grant permissions to AWS user to perform any task(eg: launching an Amazon EC2 instance or creating an Amazon S3 bucket).
