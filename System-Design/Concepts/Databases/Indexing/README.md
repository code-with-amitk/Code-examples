**Indexing**
- [How Index works](#h)

## Indexing
Technique to search data in database faster. This improve search/insert/modify operations time. 

<a name=h></a>
### How index works
#### 1. <Key, value> Database
- Index is simply a hash-table which stores key and offset in the file.
- Example: Suppose we want to store this in `key,value` Database store
```c
key     Value
123456:{name: London, attractions: [Big Ben, London Eye]}\n
42:{name: San Francisco, attractions: [Golden Gate, Bridge]}\n
```
Now to access any `<key, value>` in Database we search key in Indexing Hash map and then go the offset in file.

<img src=indexing.png width=600 />


### Types of indexing
- **1. Forward Indexing**
  - Mapping of documents to words. What all keywords a document contains.
  
| Document | Keywords |
| --- | --- |
| doc1 | hello, sky, morning |
| doc2 | tea, coffee, hi |
| doc3 | greetings, sky |

- **2. Reverse/Inverted Indexing**
  - Mapping of words to document or set of documents. Indexing is slow as it first checks that word is present or not. Searching is very fast.
  
| Word | Documents |
| --- | --- |
| hello | doc1 |
| sky | doc1, doc3 |

- **Primary vs Clustered vs Secondary Indexing**
  - *a. Primary indexing:* Anchor attribute we use for searching is the primary key(unique value for entry in table.)
  - *b. Clustered indexing:* Main Record file is sorted. Primary or non primary key can be used for searching. 
  - *c. secondary indexing:* Main record file is not sorted. We have to keep every-entry's primary key into index File.
