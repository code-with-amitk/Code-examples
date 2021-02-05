## MEMCPY
- **What**
  - copies **n bytes** from memory area src to memory area dest.
  - The memory areas must not overlap.  Use `memmove` if the memory areas overlap.
- **Remember**
  - On `void *` pointer arithematic `+ -` cannot be applied, Use `char *` in that situation.
  - memcpy() can copy from anywhere(Physical,Virtual Memory) to userspace(heap,stack).
  - We need to pass address as 1st,2nd arguments to memcpy.
  - if we have pointers we need to typecast.
## SYNTAX
```
void *memcpy(void *dest, const void * src, size_t n)
```
