- [Create](#c)
- **[List Comprehension](#lc)**
  - [1. List of Squares](#e1)
  - [2. Combining elements of 2 lists if they are not equal](#e2)
  - [3. List of double value](#e3)
  - [4. Create List containing all combinations of Cubiod sides not equal to n](#e4)
- [Declartion](#d)
- [insert](#i)
- [Remove element](#r)
- [sort](#sort)
- [Slice](#s)
- [List as Stack](#ass)
- [List as Queue](#asq)

<a name=c></a>
### Create
```py
a = []                           //1D list
listofzeros = [0] * n            //1D list of zeros of size=n

a = [[1, 2],                            //2-D List.Every row can different no of coloumns. `a[0][2]:Index error`
     ['test', 4, 50.2],
     ['play', 1990, 8, 9]
    ]

a = [                                         //3-D List. Packing 2 or more Matrices.
        [
            [1,2,3],
            [4,5,6],
        ],
        [
            [7,8,9],
            [10,11,12],
        ]
   ]

a  =   [                                  //4-D List. Packing 2 or more 3-D Matrices.
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


<a name=a></a>
### Append / Concatenate
```py
///////Append List//////////
a = [1,2]
a = a + [4,5]
print(a)        #[1,2,3,4]

///////Function///////////
a.append(6)
```

<a name=lc></a>
## List Comprehension
- Create new lists where each element is the result of some operation in just 1 line or few lines, rather than writing whole function. Examples
- A list comprehension consists of:
```py
  - Brackets containing an expression 
  - followed by a for clause, then zero or more for or if clauses. 
  - The result will be a new list resulting from evaluating the expression in the context of the for and if clauses which follow it.
```  
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
<a name=e4></a>
#### 4. Create List containing all combinations of Cubiod sides not equal to n
```py
Question: Given 3 sides of cubiod(x,y,z) and n. Print all combinations where (x+y+z != n)
Input: x=1,y=1,z=1,n=2
Output:[[0, 0, 0], [0, 0, 1], [0, 1, 0], [1, 0, 0], [1, 1, 1]]

if __name__ == '__main__':
    x = int(input())    #length
    y = int(input())    #breadth
    z = int(input())    #height
    n = int(input())
    print (
            [
                [a,b,c]                   #Expression
                for a in range(x+1)       #for clause
                for b in range(y+1) 
                for c in range(z+1) 
                if a + b + c != n        #if clause
            ]
        )
```


<a name=d></a>
### list Declaration
```py
if __name__ == '__main__':
  l = []                      //Declares empty list, same as vector
```

<a name=c2></a>
### Nesting of list
Creating a List contaning other lists
```py
a = [1,2,3]
x = ['a','b','c']
y = [a,x]
print(y)        #[[1, 2, 3], ['a', 'b', 'c']]
print(y[0])     #[1, 2, 3]
print(y[0][1])  #[2]
```

<a name=i></a>
### insert in list
```c
if __name__ == '__main__':
    l = []                  //declare list
    index = 1
    element = 2
    l.insert(index, element)
```

<a name=sort></a>
### sort 
```py
# Example list of lists
list_of_lists = [[3, 1, 2], [7, 4, 5], [6, 9, 8]]

# Sort the list of lists based on the first element of each sublist (ascending order)
list_of_lists.sort()    # [[3, 1, 2], [6, 9, 8], [7, 4, 5]]
```

<a name=cs></a>
#### custom sort
```py
# Example list of lists
list_of_lists = [[3, 1, 2], [7, 4, 5], [6, 9, 8]]

# Define a custom comparator function to sort based on the second element of each sublist (ascending order)
def custom_comparator(s):
    return s[1]

list_of_lists = sorted(list_of_lists, key=custom_comparator)
# [[3, 1, 2], [7, 4, 5], [6, 9, 8]]    # sorted based on 2nd element
```
<a name=r></a>
### remove element from list
```py

if __name__ == '__main__':
  l = [1,2,3,3]
  l.remove(3)             //remove 1st 1st occurence of element
  l.pop()                 //remove last element
```

<a name=s></a>
### Slicing `[i:j]`
Getting sublist from bigger list. Slice assignment is also possible.
```py
print(a[-3:])   #[5,6,7]
print(a[:])     #[1,2,3,4,5,6,7]
a[1:3]=[10,11]  #Slice Assignment
print(a)        #[1, 10, 11, 4, 5, 6, 7]
a[1:3]=[2,3]
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

