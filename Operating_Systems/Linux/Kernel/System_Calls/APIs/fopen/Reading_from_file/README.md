## Reading from file
```c
$ cat test.txt
Hello World

$ cat test.c
#include <stdio.h>
#include <stdlib.h>
int main() {
  char s;
  FILE* f = fopen("test.txt", "r");
  if (f == NULL) {
    printf("Error!");
    exit(1);
  }
  
  while ((s = fgetc(f)) != EOF)
    printf("%c ",s);
    
  fclose(f);
}
```
- [FILE is a structure & contains following info](FILE_pointer.md)
