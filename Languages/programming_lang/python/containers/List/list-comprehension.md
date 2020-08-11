## LIST COMPREHENSIONS:
- **What** Create new lists where each element is the result of some operation in just 1 line or few lines, rather than writing whole function 

### Examples of List comprehension
#### 1. LIST OF SQUARES
```
sq = []
for i in range(5):
    sq.append(i**2)             #** is power operator
print(sq)                       #0 1 4 9 16
sq1 = [i**2 for i in range(5)]  #0 1 4 9 16         #List Comprehension
```

#### 2. Combining elements of 2 lists if they are not equal
```
com = []
for x in [1,2,3]:
  for y in [3,1,4]:
    if x != y:
      com.append((x, y))
print([(x, y) for x in [1,2,3] for y in [3,1,4] if x != y])     #List Comprehension
    #[(1, 3), (1, 4), (2, 3), (2, 1), (2, 4), (3, 1), (3, 4)]
```

#### 3. List of double value
```
l = [-4, -2, 0, 2, 4]
print([i*2 for i in l])     #[-8.-4.0,4,8]
print([abs(i) for i in l])  #Applying function to all values
```
