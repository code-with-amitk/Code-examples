## FILE pointer
- FILE is a structure.
```c
- read_ptr: Points to present position of reading in file
- read_base: Points to 1st position from where to start reading
- read_end: Points to "\n", ie last character of file
Similar for write

struct _IO_FILE {             //Has many other feilds
  char* read_ptr;
  char* read_base;
  char* read_end;
  
  char* write_ptr;
  char* write_base
  char* write_end;
  
  char* iobuffer_base;
  char* iobuffer_end;
  
  int fileno;
  int mode
}FILE;
```
