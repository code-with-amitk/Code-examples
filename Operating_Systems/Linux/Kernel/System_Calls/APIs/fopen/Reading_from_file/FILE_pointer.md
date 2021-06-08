## FILE pointer
- FILE is a structure.
```c
struct _IO_FILE {             //Has many other feilds
  char* read_ptr, read_base, read_end;
  char* write_ptr, write_base, write_end;
  int fileno;
  int mode
}FILE;
```
