- [What](#What)
- [Complexities](#com)
  - [Time](#time)
  - [Space](#space)
    - [Example-1 Fibonacci Series](#fib)

<a name=What></a>
## Recursion
- The process in which a function calls itself directly or indirectly is called recursion and the corresponding function is called as recursive function. 
- Using recursive algorithm, certain problems can be solved quite easily eg Towers of Hanoi (TOH), Inorder/Preorder/Postorder Tree Traversals, DFS of Graph, etc.
- The idea is to represent a problem in terms of one or more smaller problems, and add one or more base conditions that stop the recursion.

<a name=com></a>
## Complexities
<a name=time></a>
### Time = O(2<sup>n</sup>)
- Total number of nodes in the tree will represent the runtime, since each call only does 0(1) work outside of its recursive calls.
```c
f(int n) {
  if (n==0) return 0
  if (n==1) return 1
  return f(n-1)+f(n-2);
}

1 2 3 
                                      f4
                                       f3+f2
                                     /     \
                                    f3        f2
                                     f2+f1     f1+f0
                                   /     \      /   \
                                  f2      f1    f1  f0
                                   f1+f0
                                 /     \
                                f1      f0
```

<a name=space></a>
### Space = O(n)
- n stacks are created for n function calls.
