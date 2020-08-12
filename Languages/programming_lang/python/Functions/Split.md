## Split functions

| | split() | rsplit() `Reverse Split`|
| --- | --- | --- |
|What|Splits into tokens from start to end|Splits into tokens from end to start|
|Syntax|list[] = str.split(seperator=None, maxsplit=-1)|list[] = str.rsplit(seperator=None, maxsplit=-1) |

- **Arguments**
  - *seperator* if separator is not provide WHITESPACE is taken as separator
  - *maxsplit* 
    - If maxsplit is provided, at most maxsplit splits are done
    - If maxsplit is not provided or -1, there is no limit on the number of splits 
- **Return** A list of strings.

### 1 SPLIT()
```
word = 'Amit, will, achieve'
li = word.split(', ')
print(li)                    #['Amit', 'will', 'achieve']   //1

l2 = word.split(', ',1)      #['Amit', 'will, achieve']     //2
print(l2)
```

### 2 SPLIT()
```
word = 'Amit, will, achieve'
li = word.rsplit(', ')
print(li)                    #['Amit', 'will', 'achieve']   //Same as 1

l2 = word.rsplit(', ',1)      #['Amit, will', 'achieve']    //Different from 2
print(l2)
```
