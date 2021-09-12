- **Comprehension**
  - Examples
    - [1. List of Squares](#e1)
    - [2. Combining elements of 2 lists if they are not equal](#e2)
    - [3. List of double value](#e3)
- **Create List**
  - [1-D List](#1d)
  - [2-D List](#2d)
  - [3-D List](#3d)
  - [4-D List](#4d)
- [List as Stack](#ass)
- [List as Queue](#asq)


## List Comprehension:
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

## Create List
<a name=1d></a>
#### 1-D List
```py
a = input("Input some comma seprated numbers : ")     #1,2,3,4
l = a.split(",")
print('List',l)                                       #[1,2,3,4]
```

<a name=2d></a>
#### 2-D List
Every row can different no of coloumns. `a[0][2]:Index error`
```py
a = [[1, 2],
     ['test', 4, 50.2],
     ['play', 1990, 8, 9]
    ]
print(a[0][1])  #2
#print(a[0][2])  #list index out of range
print(a[1][2])  #50.2
```
<a name=3d></a>
#### 3-D Lis
Packing 2 or more Matrices.
```
a = [
        [
            [1,2,3],
            [4,5,6],
        ],
        [
            [7,8,9],
            [10,11,12],
        ]
   ]
```
<a name=4d></a>
#### 4-D List
Packing 2 or more 3-D Matrices.
```
a  =   [
            [
                [
                    [1,2,3],
                    [4,5,6],
                ],
                [
                    [7,8,9],
                    [10,11,12],
                ],
            ],
            [
                [
                    [13,14,15],
                    [16,17,18],
                ],
                [
                    [19,20,21],
                    [22,23,24],
                ]
            ]
       ]
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

