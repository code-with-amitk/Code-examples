## Database vs Datawarehouse

| | Database | Datawarehouse |
| --- | --- | --- |
| Purpose | Stores customer data | helps analyze data |
| Contians | related data | historical & commutative data |
| Orientation | application-oriented-collection of data | subject-oriented collection of data |
| Uses | Online Transactional Processing (OLTP) |  Online Analytical Processing (OLAP) |
| Modelling Techniques used | ER modeling techniques | data modeling techniques |

## Object vs Block vs File storage

| | Object | Block | File |
| --- | --- | --- | --- |
| Stores | objects{ID,metaData+data} | raw blocks(xfs,ext4 etc) | data in file, with limited meta-data |
| Scaling | Easy | Tough(on high volume becomes unmanagable) |
| Suitable for | Static data(docs,photos,songs,videos) |
| Accessible from internet | yes | no(this is just disk drive) |
| Examples | [Amazon S3](https://github.com/amitkumar50/Code-examples/blob/master/System-Design/Concepts/aws/storage/s3.md), ceph, openstack swift, Google cloud, Microsoft Azure, Blackblaze | [Amazon EBS](https://github.com/amitkumar50/Code-examples/blob/master/System-Design/Concepts/aws/storage/ebs.md), SAN-arrays | [Amazon EFS](https://github.com/amitkumar50/Code-examples/blob/master/System-Design/Concepts/aws/storage/efs.md), Gluster |
