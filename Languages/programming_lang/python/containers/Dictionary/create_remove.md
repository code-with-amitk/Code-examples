## 1. Creation
### 1A. Using Initialization
```
dic = {'a':1, 'b':2}
dic['c']=3
print(dic)                #{'a': 1, 'b': 2, 'c': 3}
print(dic['a'])           #1
print('a' in dic)         #True
```

### 1B. Dictionary with mixed/hetrogeneous keys
```
d = {'name': 'John', 1: [2, 4, 3]}
```

### 1B. Using dict() constructor
```
f = dict([('ab', 4), ('cd', 5), ('ef', 6)])
print(f)                            #{'ab': 4, 'cd': 5, 'ef': 6}
```

## 2. Removal
### 2A. Remove odd keys from Dictionary
- We cannot iterate and remove elements from dictionary at same time. What we will do?
  - 1st iterate over the dictionary and create a list of keys that need to be deleted from dictionary.  
  - 2nd iterate over this list of keys and delete their entries from dictionary
```
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
