## How FILE pointer moves with reading
```c
$ cat test.txt
Hello

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

### How contents of FILE structure change while reading the file?
- [FILE structure](FILE_pointer.md)
```c
//FILE* f = fopen("test.txt", "r");
  read_ptr=0, read_base=0, read_end=0;    
  write_ptr=0, write_base=0, write_end=0;
  
  test.txt
              "Hello\n"
               |     | 
              0x20  0x25
             Start
              
//s = fgetc(f)          //read 1st character 'H'
  read_ptr=0x21, read_base=0x20, read_end=0x26;       //read_ptr points to 'H'. read_end points after '\n'
  write_ptr=0x20, write_base=0x20, write_end="";      //No write operation, nothing moves
  iobuffer_base=0x20, iobuffer_end="";                //Always same
  
//s = fgetc(f)                                        //read 2nd character 'e'
  read_ptr=0x22, read_base=0x20, read_end="";         //read_ptr keeps on moving until becomes equal to read_end.
                                                      //write, iobuffer remains same.

//fclose(f)                                           //Frees structure
```
