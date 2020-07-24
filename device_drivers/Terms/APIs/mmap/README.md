## mmap(Memory Map)
### What
- Maps file or device(device file) into Memory.

### Why mmap
a. Multiple Processes Accessing Data from Shared File:    Load/time/memory of opening/closing file is saved. What we do is open file, write file into buffer. So this write into buffer is saved, you can directly work of memory address. 
b. This is advantageous for Big Files:    This may happens file data/structures are much bigger than Buffer taken to read file. That may cause issues.
c. Provides Huge speed Advantage wrt I/O.

### Syntax
```
//void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);

fd = open(/dev/mem, RW|SYNC)
void *map_base = mmap(0, 131072, PROT_READ |PROT_WRITE, MAP_SHARED, fd, 917504)

Parameters:
- addr: This is virtual Address space of calling process. Start copying at this address.
	- if NULL, then the kernel chooses the (page-aligned) address at which to create the mapping; 
		this is the most portable method of creating a new mapping.
- length: copy these many bytes from file(fd).
- port: memory protection of mapping
- flag: Whether this mapping is visible to other processes or not
	  MAP_SHARED: Share this mapping
- fd:file to map
- offset: Start reading file(Or other object) at offset offset.
  
What above API doing?  
- Maps /dev/mem to memory(*map_base)
- Maps (131072 bytes) starting at (offset=917504) from "/dev/mem" to memory (*map_base)
```
