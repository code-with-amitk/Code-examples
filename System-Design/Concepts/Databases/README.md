- [1. Comparisons](#comp)
  - [1.1 Object, Block, File Storage](#obf)
  - [1.2 SQL vs NoSQL](#sn)
  - [1.3 Database vs Datawarehouse](#dd)

<a name=comp></a>
### 1. Comparisons
<a name=obf></a>
#### 1.1 Object vs Block vs File storage

| | Object | Block | File |
| --- | --- | --- | --- |
| Stores | objects{ID,metaData+data} | raw blocks(xfs,ext4 etc) | data in file, with limited meta-data |
| Scaling | Easy | Tough(on high volume becomes unmanagable) |
| Suitable for | Static data(docs,photos,songs,videos) |
| Accessible from internet | yes | no(this is just disk drive) |
| Consistency | Eventual consistent | Strongly consistent|
| Use cases | Not good for transactional data(bcoz of eventual consistency |
| Examples | [Amazon S3](https://github.com/amitkumar50/Code-examples/blob/master/System-Design/Concepts/aws/storage/s3.md), ceph, openstack swift, Google cloud, Microsoft Azure, Blackblaze | [Amazon EBS](https://github.com/amitkumar50/Code-examples/blob/master/System-Design/Concepts/aws/storage/ebs.md), SAN-arrays | [Amazon EFS](https://github.com/amitkumar50/Code-examples/blob/master/System-Design/Concepts/aws/storage/efs.md), Gluster |

<a name=sn></a>
#### 1.2 SQL vs noSQL

| | SQL, Relational, Structured | noSQL, nonRelational, unStructured |
| --- | --- | --- |
| Storage form | Table(Records searched using primary key) | key-value or xml or json or objects |
| Huge data support | no(becomes slow) | yes |
| Storage | May be on 1 or multiple servers | Always on multiple low cost nodes[commodity hardware] |
| Scaling | Vertical | Horizontal, cheaper, raw data can be pushed:no schema, pro |
| Tech Support | Good, query-writing:simple | Poor, query-writing:complex |
| Schema | fixed | not fixed. defining schema for unstructured data is very tough |
| Examples | Amazon S3, MySQL, postgre | <ul><li>**SEMI**: Amazon S3, Apache Cassandra, [dynamoDB](/System-Design/Concepts/Databases/NOSQL/AWS_DynamoDB/README.md)</li></ul> <ul><li>**UNSTRU**: Amazon S3, Apache CouchDB, MongoDB</li></ul> |
| Types | <ul><li>**ORDBMS(Object RDBMS)** RDBMS build on OOD. Eg: PostGreSQL</li></ul> <ul><li>**RDBMS** mySQL</li><ul> | <ul><li>**KEY-VALUE DB** Eg: redis, dynamoDB, Voldemort</li></ul> <ul><li>**WIDE-COLUMN DB:** Stores data as columns instead of rows. Eg: Cassandra, HBase</li></ul> <ul><li>**DOCUMENT DB:** data is stored in documents(XML, JSON, binary) Eg: mongoDB, dynamoDB</li></ul> <ul><li>**GRAPH DB:** Data is stored in form of graph. Eg: Neo4J, HyperGraphDB</li></ul>
  
- Today most organization are using SQL+noSQL DB combinations. 2019 stats:   MySQL + MongoDB: 34.15%,  MySQL + PostgreSQL: 9.76%

<a name=dd></a>
#### 1.3 Database vs Datawarehouse

| | Database | Datawarehouse |
| --- | --- | --- |
| Purpose | Stores customer data | helps analyze data |
| Contians | related data | historical & commutative data |
| Orientation | application-oriented-collection of data | subject-oriented collection of data |
| Uses | Online Transactional Processing (OLTP) |  Online Analytical Processing (OLAP) |
| Modelling Techniques used | ER modeling techniques | data modeling techniques |
