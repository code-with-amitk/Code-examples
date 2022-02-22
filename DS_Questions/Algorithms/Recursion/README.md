- [What](#w)
- [Complexities](#com)
- Examples using recursion
  - [1. Reverse string inplace](#rev)
- [Converting Recursion to Iterative](#ci)

<a name=w></a>
## Recursion
- The process in which a function calls itself and the corresponding function is called as recursive function. The trick is each time a recursive function calls itself, it reduces the given problem into subproblems. The recursion call continues until it reaches a point where subproblem can be solved without further recursion.
- Recursive function should have a base case(a terminating scenario) so that it does not result in an infinite loop.
- Using recursive algorithm, certain problems can be solved quite easily eg Towers of Hanoi (TOH), Inorder/Preorder/Postorder Tree Traversals, DFS of Graph, etc.

<a name=com></a>
## Complexities
**Time = O(2<sup>n</sup>):** Total number of nodes in the recursion tree will represent the runtime.
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
**Space = O(n)** n stacks are created for n function calls.

## Examples using recursion
#### 1. Reverse string inplace
```c
class Solution {
public:
    void reverseString(vector<char>& s) {
        fun (s, 0, s.size()-1);
    }
    void fun(vector<char>& s, int pos1, int pos2){
        if (pos1 >= pos2)
            return;
        fun(s, pos1+1, pos2-1);
        swap(s[pos1], s[pos2]);
    }
};
```

<a name=ci></a>
### Convert Recursive to Iterative
- Use stack or queue data structure to replace the role of the system call stack.
- At each occurrence of recursion, we simply push the parameters as a new element into the data structure that we created, instead of invoking a recursion.
