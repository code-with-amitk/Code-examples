- [1. split() & rsplit()](#split_r)
  - [1.1 split() example](#split)
  - [1.2 rsplit() example](#rsplit)

<a name=split_r></a>
## 1. Split() & rsplit
- **split:** splits into tokens from start to end
- **rsplit()** plits into tokens from end to start
```py
list[] = str.split(seperator = None, maxsplit = -1)
list[] = str.rsplit(seperator = None, maxsplit = -1)

- seperator: if separator is not provide WHITESPACE is taken as separator
- maxsplit:
    - If maxsplit is provided, at most maxsplit splits are done
    - If maxsplit is not provided or -1, there is no limit on the number of splits 
Return: A list of strings.
```
<a name=split></a>
### 1.1 split example
```
word = 'Amit, will, achieve'
li = word.split(', ')
print(li)                    #['Amit', 'will', 'achieve']   //1

l2 = word.split(', ',1)      #['Amit', 'will, achieve']     //2
print(l2)
```
<a name=rsplit></a>
### 1.2 rsplit example
```
word = 'Amit, will, achieve'
li = word.rsplit(', ')
print(li)                    #['Amit', 'will', 'achieve']   //Same as 1

l2 = word.rsplit(', ',1)      #['Amit, will', 'achieve']    //Different from 2
print(l2)
```
