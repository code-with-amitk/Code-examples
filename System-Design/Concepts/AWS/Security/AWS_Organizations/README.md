**AWS Organizations**
- [Service control policies / SCPs](#scp)
- [AWS Organizational units](#ou)


## AWS Organizations
- AWS Organizations is used to consolidate and manage multiple AWS accounts within a central location.
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
