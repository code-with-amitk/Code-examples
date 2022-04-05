**Elastic File System (EFS)**
- [EFS vs EBS](#vs)

### EFS
- Data is stored as files, file storage is ideal for use cases where large number of services need to access the same data at the same time.
- It is autoscaled, as we add/remove files it grows/shrinks automatically.
- Onpremises EC2 instances can access EFS using AWS Direct Connect.
  
<a name=vs></a>
#### EFS vs EBS
||EFS|EBS|
|---|---|---|
|Data Storage in Availabilty zones|Stores data in multiple Availabilty zones|Stores data in Single Availabilty zone|
