## Indexing
  - **What?** Indexing is technique to search data in database table faster. This improve search/insert/modify operations time. 
    
## 1. Types of indexing
### 1A. Forward Indexing
  - Mapping of documents to words. What all keywords a document contains.
  
| Document | Keywords |
| --- | --- |
| doc1 | hello, sky, morning |
| doc2 | tea, coffee, hi |
| doc3 | greetings, sky |

### 1B. Reverse/Inverted Indexing
  - Mapping of words to document or set of documents. Indexing is slow as it first checks that word is present or not. Searching is very fast.
  
| Word | Documents |
| --- | --- |
| hello | doc1 |
| sky | doc1, doc3 |
