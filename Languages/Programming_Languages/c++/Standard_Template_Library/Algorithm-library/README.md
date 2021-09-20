**Algorithms**
- [Next Permutations](#np)
- [sort](#s)

## Algorithms
These are Collection of functions to be used on containers. **NOTE:** These will not affects size of the container, but can modify a value.

<a name=np></a>
## next_permutation
- Transforms the range `[first, last)` into the next permutation from the set of all permutations. Permutation is lexicographically ordered with respect to `operator<` or comp.
- Returns true if such permutation exists, else transforms the range into the first permutation (as if by std::sort(first, last)) and returns false
- *Complexity:* At most N/2 swaps, where N = std::distance(first, last)
```cpp
template< class bidirectionalIterator >
constexpr bool next_permutation( bidirectionalIterator first, bidirectionalIterator last );

template< class bidirectionalIterator, class Compare >
constexpr bool next_permutation( bidirectionalIterator first, bidirectionalIterator last, Compare comp );
```
**example**: See find-all-permutations.md in ds-questions/strings

<a name=s></a>
## sort
`sort()` uses [IntroSort](/DS_Questions/Sorting/Hybrid_Sorting_Algo).
