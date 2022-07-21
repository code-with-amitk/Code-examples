## Meaning
- if we call fork() n number of times. Common code is executed 2<sup>n</sup> times.

## Code
```c
#include<unistd.h>  //fork
#include<iostream>
#include<cstring>
using namespace std;

int main(){
  fork();
  fork();
  fork();
  
  cout << "Out\n";    //called 8 times
}

# ./a.out
Out
Out
Out
Out
Out
Out
Out
Out
                          fork()
                        /       \
              ---------fork()   fork()-----------
             |         fork()   fork()          |
            / \        / \        /\            /\
                                                                        
```
