**DocumentDB**
- [Architecture](#ar)

### DocumentDB
Data is stored in form of documents(XML, JSON, binary).
```js
//Example storing: json data
{
  id: "1",
  name: "sue",
  age: 26,
  promotions: ["test", "5%", "great"]
  shopping: [
    {product:"a", quantity:2},
    {product:"b", quantity:3}
  ]
}
```
#### Advantages
- _1. No specilized schema is required, new fields can be added on the fly:_ 
  - Eg: Susan has a user profile like this.
```js
//susan profile (json data)
{
  userid: 992
  username: "susan"
}
```
  - Susan plays a new game tango, now no need to change exisiting fields, data can be added in this table only.
```js
//susan profile (json data)
{
  userid: 992
  username: "susan"
  tango: {
    highest_score: 10
    global_rank: 40
    bonus_level: true
  }
}
```
  - Susan got promotions now that can be added without complete db change.
```js
//susan profile (json data)
{
  userid: 992
  username: "susan"
  tango: {
    highest_score: 10
    global_rank: 40
    bonus_level: true
  }
  promotions: ["lead", "director", "vp"]
}
```

<a name=ar></a>
### Architecture
Whole DocumentDB is divided into 2 layers(compute, Storage). Even they can be scaled seperately.
- _Compute:_ All data intensive work is carried in compute.
- _Storage:_ All storage related work in storage layer.
```c
                     |---------------
                     | API
      Compute Layer -| Query Processing
                     | Caching
                     |--------------
      
                     |-------------
      Storage Layer -| Logging
                     | Storage
                     |----------
```
