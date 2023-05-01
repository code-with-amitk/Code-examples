**Dynamo: Distributed Key, Value Store**
- [Requirements](#r)
- [APIs](#a)
- [HLD](#hld)

<a name=req></a>
### Requirements
- In terms of [CAP Theorem](/System-Design/Concepts/Terms/README.md#cap). Dynamo is AP(Available, Partition Tolerant).
  - Highly Available
  - Partition Tolerant
  - Eventual consistent(it is not Strong Consistency)

### BOE

### APIs
#### get(key)
- Return value=object(s) associated with the given key. Object(s) may exist on multiple nodes.
```c
struct object get(key)

object {
  data,
  context    //metadata about object. Used like a cookie to verify the validity of the object
}
```
#### put(key, context(metadata), value=object)
- Find node where the (Key,value) should be stored and writes the given object to the disk.
- context(Is used like a cookie to verify the validity of the object)

<a name=hld></a>
### HLD
