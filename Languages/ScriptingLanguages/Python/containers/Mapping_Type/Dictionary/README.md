- [Functions in C++, Rust, Python](/Languages/Programming_Languages/c++/Standard_Template_Library/container_library/associative_containers/unsorted_unordered/README.md#fun_hm)
- [Comprehension](#dc)
- [Create](#cr)
- [Enumerate](#e)
- **Remove**
  - [Remove keys from dict](#r)
- **[zip](#z)**



### Dictionaries / {Key, value} / Hashmap / Represented by {}
- Keys are **immutable(non changable)**. If we try entering value of existant key, the old value associated with that key is overwritten.
- Example of keys: 
  - strings, numbers
  - Tuples if they contain only strings, numbers, or tuple
  - Lists cannot be used as keys as lists can be modified in place using index assignment


<a name=dc></a>
### Comprehension
Make new dictionary where each element is the result of some operation in just 1 line or few lines, rather than writing whole function. Example-1: Squaring
```py
print({i: i**2 for i in (2, 3, 4)})     #{2:4, 3:9, 4:16} 
```

<a name=e></a>
### enumerate()
retrieve (index,key) from dictionary
```py
d = {5: 'e', 1: 'a', 2: 'b', 3: 'c', 4: 'd'}
for i, j in enumerate(d):
  print(i,j)                        #0 5    1 1   2 2   3 4
```

### Removal
<a name=r></a>
#### 2A. Remove odd keys from Dictionary
We cannot iterate and remove elements from dictionary at same time. What we will do?  1st iterate over the dictionary and create a list of keys that need to be deleted from dictionary.   2nd iterate over this list of keys and delete their entries from dictionary
```py
d = {1:'a', 2:'b', 3:'c', 4:'d', 5:'e'}
print(d)                                  #{1: 'a', 2: 'b', 3: 'c', 4: 'd', 5: 'e'}
tempList = list()
for i,j in d.items() :                    //2 Create list of odd keys
    if i % 2 != 0:
        tempList.append(i)

for i in tempList:                        //3 Iterate over list and delete from dictionary
    if i in d :
        del d[i]

print(d)                                #{2: 'b', 4: 'd'}
```

<a name=z></a>
### zip(iteratable)
Take iterables(zero or more), pack them in a tuple, and return it. iterables like: list, string, dict
```py
questions=['a','b','c']
answers=['x','y','z']
for i, j in zip(questions, answers):
  print(format('Question:{0} Answer:{1}'.format(i,j)))    #Question:a Answer:x
```
