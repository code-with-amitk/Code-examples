## int execv(const char `*path`, char `*const argv[]`)
- v: Varaible number argument array `argv[]` is used to pass.
- **What?** wrt execvp, execv does not search the PATH. Instead, the full path to the new executable must be specified.

### Code
```c
#include <unistd.h> // execv()

int main() {
  char *const argv[] = {"/bin/ls", "-l", NULL};   //Full path is specified
  
  execv(argv[0], argv);

  printf("This line will not execute\n");
}
```
