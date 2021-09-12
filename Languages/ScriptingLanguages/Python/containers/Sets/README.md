**Sets**
- [Comprehension](#com)

## Sets
Unordered collection with no duplicates.

<a name=com></a>
### Set Comprehension
Make new set where each element is the result of some operation in just 1 line or few lines, rather than writing whole function.
- Example-1: Create set without a,b,c
```py
s = {i for i in 'abcdefghiab' if i not in 'abc'} 
print(s)
```
