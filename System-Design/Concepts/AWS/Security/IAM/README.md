**Identity and Access Management / IAM**
- **Users**
  - [Best Practices](#bp)
  - [Root User](#r)
  - [IAM Users](#iu)
- Terms
  - [Policies](#p)
  - [Groups](#g)
  - [Roles](#r)
  - [Access Keys](#ak)

## IAM
- IAM enables you to manage access to AWS services and resources securely.   
- With IAM we can configure access based on company’s security needs. 

### Users
<a name=bp></a>
#### Best Practices
- _1._ Enable MFA(multifactor auth for root user.
- _2._ Create IAM user. Logout and try login
- _3._ Create password policy
<a name=r></a>
#### Root user
- When we create AWS account(using email, password), a root user is created. It has complete access to all the AWS services and resources in the account.
- **Best Practice?**
  - Do not use root user to perform day-to-day tasks, instead create a IAM user and assign it permissions to perform tasks(eg:create other users).
  - Then, continue to create other IAM users, and access those identities for performing regular tasks throughout AWS
  - **Principle of least priviledges:** By following this principle, you prevent providing more permissions to users than needed to perform their tasks.

<a name=iu></a>
#### IAM users
- This is the identity that we create in AWS. It represents the person or application that interacts with AWS services and resources. It consists of a name and credentials.
- _Grant permissions:_
  - IAM user is created with NO PERMISSIONS(even no permissions to login).
  - Grant permissions to AWS user to perform any task(eg: launching an Amazon EC2 instance or creating an Amazon S3 bucket).

## Terms
<a name=p></a>
### IAM policies
- This is a document that allows/denies permissions to AWS services/resources.
- Policy example: When root attaches this policy to IAM user, it allows to view, get objects from s3:bucket1.
```c
{
  version: 1.0
  Statement: {
    Effect: Allow
    Action: [s3:ListObject, s3:GetObject]   //Listing, Getting objects is allowed
    Resources: ["s3:bucket1"::]             //From bucket1
  }
}
```

<a name=g></a>
### IAM Group
- This is collection of IAM users. When IAM policy is assigned to a group, all users in the group are granted permissions specified by the policy.

<a name=r></a>
### IAM Roles
- An IAM role is an identity that you can assume to gain temporary access to resource.
- When someone assumes an IAM role, they abandon all previous permissions that they had under a previous role and assume the permissions of the new role. 
- _Use case:_ IAM roles are ideal for situations in which access to services or resources needs to be granted temporarily, instead of long-term.

<a name=ak></a>
### IAM Access Keys
These are long-term credentials for an IAM user or root user. Access keys can be used to programatic request to:
- AWS APIs, AWS CLI
