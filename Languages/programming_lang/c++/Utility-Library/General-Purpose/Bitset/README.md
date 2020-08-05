## Bitset / Array of Bits
- This is a container in C++ for dealing with data at the bit level.
- A bitset stores bits (elements with only two possible values: 0 or 1)
- **Limitation** Size of bitset is fixed at compile time, ie cannot be changed at run time.
- **Advatages**
  - Space taken is less than that of bool bs[N] and vector bs(N)
  - operation on bitset are faster than that of array and vector.
- **Indexing is backward** Bitset starts its indexing backward that is for `10110`, `a[0] is 0`, `a[3] is 0`, `a[2] is 1`.

### Creating bitset
```C++
#include<bitset>

bitset<12> a;                       //Creating bitset of size 12
```
