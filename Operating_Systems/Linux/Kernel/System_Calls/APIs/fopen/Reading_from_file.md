## Reading from file
```c
$ cat test.txt
Hello World

$ cat test.c
#include <stdio.h>
#include <stdlib.h>
int main() {
  char s;
  FILE* fptr = fopen("test.txt", "r");
  if (fptr == NULL) {
    printf("Error!");
    exit(1);
  }
  
  while ((s = fgetc(fptr)) != EOF)
    printf("%c ",s);
    
  fclose(fptr);
}
```
