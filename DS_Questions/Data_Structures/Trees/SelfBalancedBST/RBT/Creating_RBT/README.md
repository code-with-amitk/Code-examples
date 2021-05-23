## Creating RBT
> Create RBT using `1,2,3,4,5,6,7,8`. 
- *a.* Node is inserted based on bst `if (node>root) right else left`. After insertion [Rules to check RBT](Rules_to_Check_RBT_or_not).
- **b. Rules of Insertion**
  - *1.* If tree is empty add a black node.
  - *2.* Insert new leaf node as Red.
    - *2a.* 2 adjacent Red Nodes
```c
Rule-1     Rule-2      Rule-2
1,B   ->    1,B          1,B
             \     ->     \
              2,R          2,R
                            \
                             3,R //Voilates a. Two adjacent
                                   Red not allowed. 
```
