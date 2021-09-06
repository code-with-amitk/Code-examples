## 1 child of parent
```c
#include<unistd.h>
#include <stdio.h>

int main(){
  int ret;
  ret = fork();
  if (ret == 0){                       //Child
    printf ("Inside Child\n");
    printf ("[Child] Parent's PID=%d\n", getppid());      //175. Parent's PID is always smaller since its created earlier.
    printf ("[Child] Self PID=%d\n", getpid());           //176
  }
  else                                    //Parent
  {
    printf ("Inside Parent\n");
    printf ("[Parent] Parent's PID=%d\n", getppid());     //92
    printf ("[Parent] Self PID=%d\n", getpid());          //175
  }
}
$ ./a.out
Inside Parent
Inside Child
[Parent] Parent's PID=92
[Child] Parent's PID=175
[Parent] Self PID=175
[Child] Self PID=176
```
