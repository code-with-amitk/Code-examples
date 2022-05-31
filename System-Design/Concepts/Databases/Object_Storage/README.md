- [Terms: OOL, OQL, ODMG](#t)
- [How Object Store (should) be storing data?](#h)

<a name=t></a>
### Terms
#### Object Definition Language (ODL)
ODL is Independent of any programming language and helps to create classes and interfaces and also Specify a database schema.
#### Object Query Language (OQL)
This is similar to SQL with additional features (object identity, complex objects, operations, inheritance, polymorphism, relationships) 
#### ODMG (Object Data Management Group)


<a name=h></a>
### How Object Store (should) be storing data?
### 1. Storing Videos
```c
  1. Object-Store-1(Video)   //uses Storage-Hash-Table
  
  |Shortened URL|Virtual Address of Video File in Memory|
  |-------------|---------------------------------------|
  | 2412as      |           0x004                       |
  | aw1as2      |           0x505                       |       
  
  |meta-data|video|       |meta-data|video|
  0x004                    0x505
```
### 2. Storing Photos
```c
  User-Hash-table
  | User-Id | Hash-Table-of-Photos |
  |---------|----------------------|
  | userId1 | |photo1|2412as| 
              |photo2|aw1as2|

  | userId2 | |photo1|xuyyaa| 
              |photo1|xyoaos|
```
