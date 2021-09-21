**Algorithms**
- [next permutations](#np)
- **sort, stable_sort**
  - [sort(first, last)](#s1)
  - [sort (first, last, Compare comp)](#s2)

## What
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

## sort, stable_sort
Sorts the elements in the range `[first,last)` into ascending order. `sort()` uses [IntroSort](/DS_Questions/Sorting/Hybrid_Sorting_Algo).
```c
                                         sort()                                       |       stable_sort()
------|-------------------------------------------------------------------------------|-----------------------------------
What  | elements are not guranteed to keep original relative order                    | Preserves relative order of the elements
Types | 1. Default: void sort(RandomAccessIterator first, RandomAccessIterator last)  | 1. same
        2. Custom: void sort (RandomAccessIterator first, RandomAccessIterator last,  | 2. same
                              Compare comp);
Complexity| nlogn                                                                     | nlogn                              
```
<a name=s1></a>
#### void sort (RandomAccessIterator first, RandomAccessIterator last)
Uses comparison operator `<`
```c
  std::vector<int> vec = {32,71,12,45,26,80,53,33};

  // using default comparison (operator <):
  std::sort (v.begin(), v.begin()+4);                 //(12 32 45 71)26 80 53 33
```

<a name=s2></a>
#### void sort (RandomAccessIterator first, RandomAccessIterator last, Compare comp)
**comp:** This can be: 
  - _1. Binary function:_ that accepts two elements in the range as arguments, and returns a value convertible to bool. The value returned indicates whether the element passed as first argument is considered to go before the second.  OR
  - _2. Function pointer or Function Object_ 
```c
bool comp (int i, int j) {              //Comparator as Binary Function
  return (i<j); 
}
struct A {                              //Comparator as Object
  bool operator() (int i,int j) {
    return (i<j);
  }
} obj;

  // using function as comp
  std::sort (v.begin()+4, v.end(), comp);   //12 32 45 71(26 33 53 80)

 // using object as comp
  std::sort (v.begin(), v.end(), obj);     //(12 26 32 33 45 53 71 80)
```
