## Operations on Dictionary

### 1. Creating Dictionary
#### 1a. Initialize & Create
```
dic = {'a':10, 'b':20}
dic['c']=30
print(dic)                #{'a': 10, 'b': 20, 'c': 30}
print(dic['a'])           #10
print('a' in dic)         #True
```
#### 1b. Using dict() constructor
```
f = dict([('ab', 4), ('cd', 5), ('ef', 6)])     #A2
print(f)                            #{'ab': 4, 'cd': 5, 'ef': 6}
```

### 2. del(a[key])
```
del(dic['c'])
print(dic)              #{'a': 10, 'b': 20}     B
```

### 3. Printing 
#### 3a. All keys
```
print(list(dic))        #['a', 'b']     
```
#### 3b. In sorted manner
```
print(sorted(dic))      #['a', 'b']     
```

### 4. METHODS
#### 4a. items()
- Used to retrieve (key,value) both from dictionary
```
for i, j in f.items():
    print(i,j)          #ab 4   cd 5    ef 6
```
#### 4b. enumerate()
- To retrieve (index,key) of dictionary
```
for i, j in enumerate(f):
    print(i,j)          #0 ab   1 cd    2 ef
```
#### 4c. zip()
- 2 or more sequneces can be paired
```
questions=['a','b','c']
answers=['x','y','z']
for i, j in zip(questions, answers):
    print(format('Question:{0} Answer:{1}'.format(i,j)))    #Question:a Answer:x
```
