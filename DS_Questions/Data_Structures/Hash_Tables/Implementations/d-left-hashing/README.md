## d-left Hashing
- Use d Hash tables(as used [2 hash tables in 2-left hashing](..)) or split 1 hash table into d blocks. Similar to 2-left hashing, left most hashtable should be loaded.
- d buckets, n entries. Each bucket has n/d entries.
- **Inserting:** 
  - Obtain 1 bucket from d buckets, where element to be placed
  - if more than 1 bucket is found, use bucket having less elements.
  - In case of tie, place elements in left most bucket. (ie d-left hashing)
