## FB Datastructure(Graph)

[Information taken from this Article](https://medium.com/swlh/an-introduction-to-facebooks-system-architecture-47cfcf597101#:~:text=The%20Data%20Model%20For%20Social,a%20single%20giant%20social%20graph.&text=A%20node%20represents%20an%20entity,the%20relationships%20between%20the%20nodes.)

- FB stores all(users, comments, posts, locations) in giant graph. This graph has 5 billion+ entries.
- **Example**
  - 4 Friends(kush,amit,prasad,arpit). Kush created a post "Party", Amit commented "Great party @Prasad"(tagged prasad), Arpit liked comment.
  
### Database schema
- **Object Table**
```c
  |  id(int) |  otype(string) |     data(byte)     |
  |----------|----------------|--------------------|
  |   567    |  user          |     kush           |
  |   444    |  post          |     Party          |
  |   332    |  comment       | Great Party@prasad |
  --------------------------------------------------
```
- **Relation/Association/Edge Table**
```c
  |  Source-id(int) |  Dst-Id(int)  | Edge-Type(string) | key-value(Optional)(byte) |
  |-----------------|---------------|-------------------|---------------------------|
  |       567       |     999       |   friends         |   null                    |
  |       567       |     444       |   authored        |   null                    |  
  |       444       |     332       |   Comment         |   reaction:smily emoji    |
  -----------------------------------------------------------------------------------
```
### How Databases are Accessed
#### 1. TAO(Distributed Data store) 
  - **What?** Database frontend(Developed at FB), which provides APIs to RW data from databases.
  - **API Types?**
    - *1. Object APIs:* Add/delete/query/update objects
    - *2. Association APIs:* Add/delete/query/update associations. Example
```c
struct/class {
  long source-id;
  long dst-id;
  string edge-type;  
  unordered_map <key,value>;
}Edge;

 Edge[] assoc_get(567, friends)    //assoc_get(id1, edge-type)   
  //Returns all edges originating from id1 and having particular edge-type
```
