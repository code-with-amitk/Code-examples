## [RBT / Red Black Tree](https://www.youtube.com/watch?v=UaLIHuR1t8Q&t=883s)
- Each node have color(red or black). 
- Data structure
```c
  struct node{ 
    int item;  
    enum{red, black}color;
    struct node *parent, *left, *right; 
  };
  
                          |
      |item|color|*left|*parent|*right|
                  /                 \
```
- [Rules to check RBT or Not](Rules_to_Check_RBT_or_not)
- [Insertion_in_RBT](Insertion)
