## MEMCPY
### What 
- copies **n bytes** from memory area src to memory area dest.
- The memory areas must not overlap.  Use `memmove` if the memory areas overlap.

## SYNTAX
```
void *memcpy(void *dest, const void * src, size_t n)
```
