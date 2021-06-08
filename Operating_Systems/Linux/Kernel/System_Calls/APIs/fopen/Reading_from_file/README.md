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
- FILE is defined as:
```c
struct _IO_FILE {             //Has many other feilds
  char* read_ptr, read_base, read_end;
  char* write_ptr, write_base, write_end;
  int fileno;
  int mode
}FILE;
```
