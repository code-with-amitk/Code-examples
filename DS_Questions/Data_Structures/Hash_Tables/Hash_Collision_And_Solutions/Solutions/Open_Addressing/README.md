## Open Addressing  
  - All elements are stored in HT itself. Once same hash is derived, insert element in hash table itself no seperate chains.

![ImgUrl](https://i.ibb.co/b7Qnkh2/oa.png)

### Types of Open addressing
- **B1. Linear/Sequential probing**
  - **INSERTION**: Once same hash is derived, inserts the new item in the next open spot in the table ie next to already existent element with same hash.
  - If the table is not too full, the contiguous runs of items should be fairly small, hence this location should be only a few slots from its intended position
  - **DELETION** 
    - Ugly here removing one element might break a chain of insertions, making some elements inaccessible. 
    - We need to reinsert all the items into new holes.
  
- **B2. Quadratic Probing**
