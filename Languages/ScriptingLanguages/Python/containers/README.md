- [List vs Tuple vs Dictionary vs Set vs Deque](#vs)


<a name=vs></a>
## Comparison
Mutable=changable

| List(not linkedlist)=vector(c++) | Tuple |Dictionary{} / MAP(STL) |      SET{}    | DEQUE
|---|---|---|---|---|
|Defined inside  |  `[]`          | With or without `()` |           {}            |         {}    |       |
|What| 1-D/2-D/n-D vector, which can store int,float,char anything| Immutable lists | {key,value} pair. Unique Keys | No duplicates | Double ended queue|
|Mutable/Changable|y|n|
|Comprehension   |      y         |            n         |       y                 |       y        | |
|Hetrogeneous    |       Y        |            Y|

```c
                |   List         |          Tuple       | Dictionary{} / MAP(STL) |      SET{}    | DEQUE
----------------|----------------|----------------------|-------------------------|---------------|------
Defined inside  |  `[]`          | With or without `()` |           {}            |         {}    |       

What            | 1-D/2-D/n-D    | RO/Immutable lists   | {key,value} pair.       | No duplicates | Double ended queue
                  arrays/vectors |                      | Unique keys
                  
Immutable       |      N         |            Y         |   
Comprehension   |      y         |            n         |       y                 |       y        | |
Hetrogeneous    |       Y        |            Y
Data-types
```


