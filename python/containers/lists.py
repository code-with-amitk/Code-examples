"""
LISTS:
 - Mutable: ie these can be changed, after initialization
 - Indexing [i]: means getting value at index
 - Slicing [i:j] getting sublist from bigger list
            Slice assignment is also possible
 - Concatenate: +
 - Nesting the list: Creating List contaning other lists
 - Functions:
    list.append(x): Appends elements at end of list
    list.len(): Finds length of list 
    Other functions (https://docs.python.org/3/tutorial/datastructures.html)
 - del statement: Delete a value or complete slice or list
   Return: None, just deletes the value
"""
a=[1,2,3,4,5,6,7]
print(a)        #[1,2,3,4,5,6,7]

##MUTABLE##
a[2]=89
print(a[2])     #89
a[2]=3

####INDEXING####
print(a[2])     #3
print(a[-1])    #7

####SLICING#####
print(a[-3:])   #[5,6,7]
print(a[:])     #[1,2,3,4,5,6,7]
a[1:3]=[10,11]  #Slice Assignment
print(a)        #[1, 10, 11, 4, 5, 6, 7]
a[1:3]=[2,3]

###CONCATENATE###
print(a+[8,9])  #[1,2,3,4,5,6,7,8,9]

###NESTING LISTS###
a = [1,2,3]
x = ['a','b','c']
y = [a,x]
print(y)        #[[1, 2, 3], ['a', 'b', 'c']]
print(y[0])     #[1, 2, 3]
print(y[0][1])  #[2]

###FUNCTIONS###
a.append(21)
print(a)        #[1,2,3,4,5,6,7,21]
print(len(a))   #8

###DEL STATEMENT###
a1 = ['a','b',1,2,5,'p']
del a1[0]               #delete 'a', return None
print(a1)               #['b',1,2,5,'p']
del a1[2:4]             # deletes [1,2]
print(a1)               #b['b',5,'p']
del a1[:]               #delete everything
print(a1)               #[]
del a1                  # Deleting variable, referencing will give error
#print(a1)              #name 'a1' is not defined

"""
LISTS AS STACK(LIFO):
 - list can be very easily used as a stack
 - Consider list's end as top.
 - push element at top of stack:    
    list.append(x) Appends element at end
 - pop element:
    list.pop() removes element from end
"""
stack = [1,2,3]
stack.append(4)     #[1,2,3,4]
stack.append(5)     #[1,2,3,4,5]
print(stack.pop())         #5   //Remaning List[1,2,3,4]
print(stack.pop())         #4   //Remaning List[1,2,3]


"""
LISTS AS QUEUES(FIFO)   //lists are not efficient as queues
Why lists not good queues?
 - Push=Slow: Inserts or pops from the beginning of a list is slow, because all of the other elements 
 have to be shifted by one.
 - Pop=Fast: appends and pops from the end of list are fast
"""


"""
LIST COMPREHENSIONS:
 Usage? Creating lists
 Applications? make new lists where each element is the result of some operation in just 1 line or 
 few lines, rather than writing whole function
 Examples:
    LIST OF SQUARES
    COMBINING ELEMENTS OF TWO LISTS if they are not equal
"""


#####LIST OF SQUARES######
sq = []
for i in range(5):
    sq.append(i**2)             #** is power operator
print(sq)                       #0 1 4 9 16
sq1 = [i**2 for i in range(5)]  #0 1 4 9 16         #List Comprehension


#####COMBINING ELEMENTS OF LISTS#####
com = []
for x in [1,2,3]:
    for y in [3,1,4]:
        if x != y:
            com.append((x, y))
print([(x, y) for x in [1,2,3] for y in [3,1,4] if x != y])     #List Comprehension
    #[(1, 3), (1, 4), (2, 3), (2, 1), (2, 4), (3, 1), (3, 4)]

###LIST OF DOUBLE VALUES###
l = [-4, -2, 0, 2, 4]
print([i*2 for i in l])     #[-8.-4.0,4,8]
print([abs(i) for i in l])  #Applying function to all values


"""
2-D LISTS:
 - Unlike C, 1st row has 2 col, 2nd row has 3 col ...
 - a[0][2]:Index error
"""
a = [[1, 2],
     ['test', 4, 50.2],
     ['play', 1990, 8, 9]
    ]
print(a[0][1])  #2
#print(a[0][2])  #list index out of range
print(a[1][2])  #50.2


"""
3-D LISTS: Packing 2 or more Matrices.
"""
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


"""
4-D LISTS: Packing 2 or more 3-D Matrices.
"""
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
