- Consider this example    
```
a=[1,2,3,4,5,6,7]
print(a)        #[1,2,3,4,5,6,7]
```

### 1. Concatenate
```
print(a+[8,9])  #[1,2,3,4,5,6,7,8,9]
```

### 2. Indexing [i]
- Getting value at index 
```
print(a[2])     #3
print(a[-1])    #7
```

### 3. Immutable: No
```
a[2]=89
print(a[2])     #89
```

### 4. Nesting of list
- Creating a List contaning other lists
```
a = [1,2,3]
x = ['a','b','c']
y = [a,x]
print(y)        #[[1, 2, 3], ['a', 'b', 'c']]
print(y[0])     #[1, 2, 3]
print(y[0][1])  #[2]
```

### 5. Slicing `[i:j]`
- getting sublist from bigger list. Slice assignment is also possible.
```
print(a[-3:])   #[5,6,7]
print(a[:])     #[1,2,3,4,5,6,7]
a[1:3]=[10,11]  #Slice Assignment
print(a)        #[1, 10, 11, 4, 5, 6, 7]
a[1:3]=[2,3]
```
