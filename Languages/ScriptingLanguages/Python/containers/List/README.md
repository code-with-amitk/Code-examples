- **Comprehension**
  - Examples
    - [1. List of Squares](#e1)
    - [2. Combining elements of 2 lists if they are not equal](#e2)
    - [3. List of double value](#e3)
- [List as Stack](#ass)
- [List as Queue](#asq)
- [Operations](Operations.md)


### List Comprehension
Create new lists where each element is the result of some operation in just 1 line or few lines, rather than writing whole function. Examples
<a name=e1></a>
#### 1. List of Squares
```py
sq = []
for i in range(5):
    sq.append(i**2)             #** is power operator
print(sq)                       #0 1 4 9 16
sq1 = [i**2 for i in range(5)]  #0 1 4 9 16         #List Comprehension
```
<a name=e2></a>
#### 2. Combining elements of 2 lists if they are not equal
```py
com = []
for x in [1,2,3]:
  for y in [3,1,4]:
    if x != y:
      com.append((x, y))
print([(x, y) for x in [1,2,3] for y in [3,1,4] if x != y])     #List Comprehension
    #[(1, 3), (1, 4), (2, 3), (2, 1), (2, 4), (3, 1), (3, 4)]
```
<a name=e3></a>
#### 3. List of double value
```py
l = [-4, -2, 0, 2, 4]
print([i*2 for i in l])     #[-8.-4.0,4,8]
print([abs(i) for i in l])  #Applying function to all values
```

<a name=ass></a>
### List as Stack(LIFO)
List can be very easily used as a stack. Implementation:
- Consider list's end as top.
- push element at top of stack:    
  - list.append(x) Appends element at end
- pop element: list.pop() removes element from end
```py
stack = [1,2,3]
stack.append(4)     #[1,2,3,4]
stack.append(5)     #[1,2,3,4,5]
print(stack.pop())         #5   //Remaning List[1,2,3,4]
print(stack.pop())         #4   //Remaning List[1,2,3]
```

<a name=asq></a>
### List as Queue(FIFO)
Lists are not efficient as queues. Why lists not good queues?
- **Push=Slow:** Inserts or pops from the beginning of a list is slow, because all of the other elements have to be shifted by one.
- **Pop=Fast:** appends and pops from the end of list are fast

