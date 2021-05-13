## execvp(const char `*file`, char `*const argv[]`)
- v: Variable number of arguments passed in array `argv[]`
- p: name of the program to run will be taken from filename specified or program will be searhed using PATH variable.

### Program-1
```c
#include <unistd.h>
void main() {
    printf ("I am prog1");
}
# gcc prog1.c -o PROG1
```

### Program-2
```c
#include <unistd.h>
void main(){
  char *argv[] = {"./PROG1", NULL};
  execvp(args[0], args);
  printf("\nProg2 Last line");    //This line not executed bcoz as soon as the execvp() function is called, this program is replaced by PROG1
}
# gcc prog2.c -o PROG2
# ./PROG2
    I am prog1
```
