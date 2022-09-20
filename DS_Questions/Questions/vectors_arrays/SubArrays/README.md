- [Subarray](#sa)
- [Sequence](#seq)
- [Sub-sequence](#subs)

<a name=sa></a>
### Subarray
- Contigous, maintains relative order

<a name=seq></a>
### Sequence
- Elements in the subsequence are consecutive integers, the consecutive numbers can be in any order(ie does not need to be ascending or decending). Examples
```
{1, 9, 3, 10, 4, 20, 2}       //Sequence that can be formed {1, 3, 4, 2}. => {1,2,3,4}
{-100, 9, 7, 5, 8, 6, 100}    //Sequence that can be formed {5,6,7,8,9}
```

<a name=subs></a>
### Sub-sequence
- A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. Example
```c
[0,3,1,6,2,2,7]         //[3,6,2,7] is Subsequence but not increasing
[0,1,0,3,2,3]           //[0,1,2,3] is Longest increasing Subsequence
```
