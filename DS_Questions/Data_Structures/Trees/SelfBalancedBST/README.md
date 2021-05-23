## Self Balanced / Height Balanced BST / HBT
- HBT always keeps itself balanced by rotation if its BF is not equal to -1,0,1.
- BF = Right_Height - Left_Height
- **Insert/delete/search in HBT** O(logn) even in worst case
- **Problem with BST?** 
  - BST may not be balanced all times, BF depends on incoming data in Real time.
  - Ex: Let's consider constructing BST on real time data. `[t = 1. data=9] [t=2 data=8] [t=3 data=7]`. Instead of BST linear array is created.
```console
            9
          /
        8
      /
    7
```
- HBT Example:
```console
     3 (bf:-2). Not Balanced. Need rotation at this node              5(bf: -1). HBT 
    /                                                                /  \
   2(bf:-1)                                                 (bf: -1)4      6(bf: 0)
  /                                                                /
 1(bf:0)                                                          3(bf: 0)
```

### Examples of HBT
  - [AVL and left,right rotation](AVL)
  - [RBT](RBT)
  - [B Tree]()
