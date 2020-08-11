## Creating Tuples

### 1. Create tuple after taking input from user
```
a = input("Input some comma seprated numbers : ")     #1,2,3,4
t = tuple(a)
print('Tuple:',t)                                     #(1,2,3,4)
```

### 2. Created with or without `()`
```
b = (1,3,'f','my')
a = 1,3,'f','my'
print(a)                #(1, 3, 'f', 'my')
```

### 3. Creating Tuples from list
- Tuples can be created from list, and because lists are mutable tuples can be made mutable as well
```
c = ([1, 2, 3])
print(c)        #[1, 2, 3]
c[0]=4
print(c)        #[4, 2, 3]
```
