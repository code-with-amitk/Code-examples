**Indexing**
- [How Index works](#h)

## Indexing
Technique to search data in database faster. This improve search/insert/modify operations time. 

<a name=h></a>
### How index works
Index is simply a hash-table which stores key and offset in the file.
```c
key     Value
123456:{name: London, attractions: [Big Ben, London Eye]}\n
42:{name: San Francisco, attractions: [Golden Gate, Bridge]}\n
```
Now to access any `<key, value>` in Database we search key in Indexing Hash map and then go the offset in file.

<img src=indexing.png width=600 />


### Types of indexing
#### 1. Forward Indexing
Above example is fi.

#### 2. Reverse/Inverted/Secondary Indexing
Mapping of words to document or set of documents. Indexing is slow as it first checks that word is present or not. Searching is very fast.
<img src=secondary_indexes.PNG width=700 />


- **Primary vs Clustered vs Secondary Indexing**
  - *a. Primary indexing:* Anchor attribute we use for searching is the primary key(unique value for entry in table.)
  - *b. Clustered indexing:* Main Record file is sorted. Primary or non primary key can be used for searching. 
  - *c. secondary indexing:* Main record file is not sorted. We have to keep every-entry's primary key into index File.
