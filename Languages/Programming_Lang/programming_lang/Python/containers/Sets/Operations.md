## Operations
- Set objects support mathematical operations like union, intersection, difference, and symmetric difference

### 1. Keys are Unique
```
a = {'a', 'b', 'a', 'c', 'd', 'c'}
print(a)                            #{'a', 'c', 'b', 'd'}       #Duplicates not stored
```

### 2. Set Difference
- a1=set(''), b1=set(''). a1-b1 are those letters in a1 but not in b1
```
a1 = set('abcde')
b1 = set('abcdf')
print(a1-b1)                        #{'e'}  B
```

### 3. Union (|)
```
a1 = set('abcde')
b1 = set('abcdf')
print(a1|b1)                        #{'b', 'c', 'f', 'e', 'd', 'a'}
```

### 4. Intersection (&)
- Common elements in set-a, set-b
```
a1 = set('abcde')
b1 = set('abcdf')
print(a1&b1)                        #{'a', 'c', 'b', 'd'}
```

### 5. (^). Letters in set-a or set-b but not both
```
a1 = set('abcde')
b1 = set('abcdf')
print(a1^b1)                        #{'f', 'e'} E
```
