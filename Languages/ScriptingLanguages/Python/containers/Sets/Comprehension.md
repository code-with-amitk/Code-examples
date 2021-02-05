## Set Comphrehension
-  make new set where each element is the result of some operation in just 1 line or few lines, rather than writing whole function.

### Example-1
- Create set without a,b,c
```
s = {i for i in 'abcdefghiab' if i not in 'abc'} 
print(s)
```
