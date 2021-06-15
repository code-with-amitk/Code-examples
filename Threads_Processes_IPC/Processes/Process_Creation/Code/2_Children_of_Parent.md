## Creating 2 Children of parent
- To create 2 children we need to call fork inside parent.
```c
#include <unistd.h>
#include <stdio.h>
#include <error.h>

void error(char* cString) {
  perror(cString);
  printf("%d", errno);
  exit(0);
}

int main() {
  int ret = -1;
  
  if (ret = fork() < -1)
    error ("fork");
    
  if (ret == 0){                                     //Child1
    printf ("Child1: %d\n", getpid());
  } else {                                           //Parent
    printf ("Parent: %d\n", getpid());
    
    if (ret = fork() < 0)
      error ("fork");
      
    if (ret == 0)                                     //Child2
      printf ("Child2: %d\n", getpid());
    else                                              //Parent
      printf ("Parent: %d\n", getpid());
  }
}

$ a.out
Child1: 1234
Parent: 780
Child2: 1235
Parent: 780
```
