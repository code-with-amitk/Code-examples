MongoDB
- [Tools](#t)
- [Create MongoDB & load data](#c)


## MongoDB
- This is noSQL/nonRelational/unStructured DB. It uses uses JSON-like documents with optional schemas.
- Developed by MongoDB Inc. and licensed under the Server Side Public License (SSPL).
    - SSPL means use MongoDB as a service if you modify source you need to make it open source. This is not applicable to customers who purchased a commercial license from MongoDB.

<a name=t></a>
### Tools
- **ATLAS:** MongoDB cloud database. No need to install instance on machine.
- **COMPASS:** GUI for MongoDB

<a name=c></a>
#### Create/Load data on MongoDB Cloud Cluster(for Free)
- Create instance, Visit [https://cloud.mongodb.com/](https://cloud.mongodb.com/). Create cluster:
  - Service Provider(AWS), Region(Mumbai), Shared RAM(512 MB)
- Connect to DB
  - Enter IP Address(current IP), create admin username and password
  - Choose connection Method: **AND IT CONNECTS**
    - Install compass, enter connection string {mongodb+srv://amit:<password>@sandbox-no-backup.r0etc.mongodb.net/test}
- Load sample data:
  - [Sample data sets](https://docs.atlas.mongodb.com/sample-data/available-sample-datasets/#available-sample-datasets)
