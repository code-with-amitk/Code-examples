## Bloom Filter
- **Terms**
  - _1. False Positive:_ A test result wrongly indicating particular condition is set/present.
  - _2. False Negative:_ A test result wrongly indicating particular condition is absent.
- **What?** 
  - BF is bit array of size n.
  - _To Insert element:_ Provide element to hash Function, get array index place 1.
  - _To search a element:_ Provide element to hash function, get index. _ELEMENT CAN BE AT INDEX._
```c
Bit array:  0 1 0 0 1 0 1 ... 1
Index:      0 1 2 3 4 5 6     n-1
  
Insert(x).   x ->|Hash Function|-> 3(array index)
BF:         0 1 0 1 1 0 1 ... 1
```

- **[Characteristics of BF](Characteristics_of_BF)**
