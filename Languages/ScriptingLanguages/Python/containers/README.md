- [List vs Tuple vs Dictionary vs Set vs Deque](#vs)


<a name=vs></a>
## Comparison
Immutable = RO = Unchangable

|---|---|---|
|Test|test|test|
|Test1|test1|test1|

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


