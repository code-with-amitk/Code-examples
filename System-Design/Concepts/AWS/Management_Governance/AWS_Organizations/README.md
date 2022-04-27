**AWS Organizations**
- [Service control policies / SCPs](#scp)
- [AWS Organizational units](#ou)


## AWS Organizations
- This service helps to manage multiple AWS accounts from central location.
- The default maximum number of accounts allowed for an organization is 4, but you can contact AWS Support to increase your quota.
- Root user is created which is parent of all users.

<a name=scp></a>
### Service control policies / SCPs
- SCPs places restrictions on AWS services, resources, individual API actions that users and roles in each account can access.
- SCP can be applied to:
  - [AWS OU](#ou)
  - Indivisual Member account

<a name=ou></a>
### AWS Organizational units
Inside AWS Organizations, we can group accounts into organizational units (OUs) who have similar business or security requirements.
