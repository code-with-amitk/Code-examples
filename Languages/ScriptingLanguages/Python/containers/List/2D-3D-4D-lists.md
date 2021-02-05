
## 1. 2-D LISTS:
- Unlike C, 1st row has 2 col, 2nd row has 3 col ...
- a[0][2]:Index error
```
a = [[1, 2],
     ['test', 4, 50.2],
     ['play', 1990, 8, 9]
    ]
print(a[0][1])  #2
#print(a[0][2])  #list index out of range
print(a[1][2])  #50.2
```

## 2. 3-D LISTS
- Packing 2 or more Matrices.
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

## 2. 4-D LISTS
- Packing 2 or more 3-D Matrices.
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
