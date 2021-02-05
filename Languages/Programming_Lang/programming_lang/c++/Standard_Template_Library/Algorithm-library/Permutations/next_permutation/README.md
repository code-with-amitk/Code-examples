## What
- Transforms the range [first, last) into the next permutation from the set of all permutations.
- *Condition:* Permutation is lexicographically ordered with respect to operator< or comp
- *Return* 
  - Returns true if such permutation exists, else transforms the range into the first permutation (as if by std::sort(first, last)) and returns false
- *Complexity*
  - At most N/2 swaps, where N = std::distance(first, last)

## Syntax
```
template< class bidirectionalIterator >
constexpr bool next_permutation( bidirectionalIterator first, bidirectionalIterator last );

template< class bidirectionalIterator, class Compare >
constexpr bool next_permutation( bidirectionalIterator first, bidirectionalIterator last, Compare comp );
```



## Example
```
See find-all-permutations.md in ds-questions/strings
```
