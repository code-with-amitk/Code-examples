**Amazon S3**

### S3(Simple Storage Service)
- S3 stores everything in buckets. each bucket can have 100's of objects
- Example: There is 1 large Video, We will store Video chunks on S3.
```c
  <key=bucket-id, Value=Video_url(or video)>
      11, xyz
      12, abc
      ..
```

- **S3 Storage classes**

|Class|What|
|---|---|
|1. S3|Durable, immediately available and frequently accessed|
|2. S3-IA(Infrequently accessed)|For data that is accessed less frequently|
|3. S3 – RRS (Reduced Redundancy Storage)| Less durable with availabilty. Used for data that is easily reproducible, such thumbnails|
      
![ImgUrl](https://i.ibb.co/q0xNcyW/s3.png)
