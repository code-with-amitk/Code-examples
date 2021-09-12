- **Create List**
  - [1-D List](#1d)
  - [2-D List](#2d)
  - [3-D List](#3d)
  - [4-D List](#4d)
  - [Nesting](#nes)
- [Append / Concatenate](#con)
- [Slice](#sl)

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

- Consider this example    
```
a=[1,2,3,4,5,6,7]
print(a)        #[1,2,3,4,5,6,7]
```

<a name=nes></a>
#### Nesting of list
Creating a List contaning other lists
```py
a = [1,2,3]
x = ['a','b','c']
y = [a,x]
print(y)        #[[1, 2, 3], ['a', 'b', 'c']]
print(y[0])     #[1, 2, 3]
print(y[0][1])  #[2]
```

<a name=con></a>
### Append / Concatenate
```py
print(a+[8,9])  #[1,2,3,4,5,6,7,8,9]
```

<a name=sl></a>
### Slicing `[i:j]`
Getting sublist from bigger list. Slice assignment is also possible.
```py
print(a[-3:])   #[5,6,7]
print(a[:])     #[1,2,3,4,5,6,7]
a[1:3]=[10,11]  #Slice Assignment
print(a)        #[1, 10, 11, 4, 5, 6, 7]
a[1:3]=[2,3]
```
