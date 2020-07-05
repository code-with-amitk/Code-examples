**Contents**
- database vs datawarehouse
- Object vs block vs file storage
- SQL vs NoSQL DB

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
| Consistency | Eventual consistent | Strongly consistent|
| Use cases | Not good for transactional data(bcoz of eventual consistency |
| Examples | [Amazon S3](https://github.com/amitkumar50/Code-examples/blob/master/System-Design/Concepts/aws/storage/s3.md), ceph, openstack swift, Google cloud, Microsoft Azure, Blackblaze | [Amazon EBS](https://github.com/amitkumar50/Code-examples/blob/master/System-Design/Concepts/aws/storage/ebs.md), SAN-arrays | [Amazon EFS](https://github.com/amitkumar50/Code-examples/blob/master/System-Design/Concepts/aws/storage/efs.md), Gluster |

### Every Object contains
  - **data** anything we want to store, from a family photo to a 400,000-page manual for assembling an aircraft.
  - **Metadata** contains contextual information about what the data is, what it should be used for Metadata can include anything from the security classification of the file within the object to the importance of the application associated with the information. 
- **globally unique identifier** address given to the object in order for the object to be found over a distributed system

## SQL vs noSQL

| | SQL, Relational, Structured | noSQL, nonRelational, unStructured |
| --- | --- | --- |
| Storage form | Table(Records searched using primary key) | key-value or xml or json or objects |
| Huge data support | no(becomes slow) | yes |
| Storage | May be on 1 or multiple servers | Always on multiple low cost nodes[commodity hardware] |
| Scaling | Vertical | Horizontal, cheaper, raw data can be pushed:no schema, pro |
| Tech Support | Good, query-writing:simple | Poor, query-writing:complex |
| Schema | fixed | not fixed. defining schema for unstructured data is very tough |
| Examples | Amazon S3, MySQL, postgre | SEMI: Amazon S3, Apache Cassandra, dynamoDB, UNSTRU: Amazon S3, Apache CouchDB, MongoDB |
