## INDEXING
  - Why?
    - Goal of creating an index on a particular table in a database is to make it faster to search through the table and find the row or rows that we want.
  - What?
    - Technique used in DB to improve search/insert/modify operations time. 
    
### 1. Types of indexing:
#### 1A. FORWARD INDEXING? 
  - Mapping of documents to words. What all keywords a document contains.
  
| Document | Keywords |
| --- | --- |
| doc1 | hello, sky, morning |
| doc2 | tea, coffee, hi |
| doc3 | greetings, sky |

#### 1B. REVERSE/INVERTED INDEXING? 
  - Mapping of words to document or set of documents. Indexing is slow as it first checks that word is present or not. Searching is very fast.
  
| Word | Documents |
| --- | --- |
| hello | doc1 |
| sky | doc1, doc3 |
