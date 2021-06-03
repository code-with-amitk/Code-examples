## Pseudo Code
- BF is bit array contaning 0 and 1s.
- All [hash functions](/Networking/OSI-Layers/Layer-3/Security) should be member of same class so that range can be defined and all hash functions generate key within that range.

### Insert a element in BF
```c
Element to be inserted: x

insert(x) {
  for (int i=0; i<k; ++i) {    /* Loop all hash functions k */
    index = hash(x);

    if (BF[index] == 0)           /*Bloom filter had zero bit at position i*/
      BF[index] = 1;
  }
}  
```
- **Search element in BF**
```c
Element to be searched: x

bool search(x) {
  bool isElementPresent = true;

  for (int i=0; i<k; ++i) {    /* Loop all hash functions k */
    index = hash(x);
  
    if (BF[index] == 0)
      isElementPresent = false;
  }
  return isElementPresent;
}  
```
