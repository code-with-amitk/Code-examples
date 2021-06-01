## Pseudo Code
- **Insert a element in BF**
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
