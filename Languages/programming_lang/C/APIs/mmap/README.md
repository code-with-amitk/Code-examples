## mmap(Memory Map)
- **What**
	- Map file or device(device file) to memory. Usually done for mapping Contents from Physical-Memory to Process's Virtual Memory.
		- *Why can't read from Physical memory directly* 2 or more processes will clash on reading.
	- That means copy contents of file to memory & return pointer to it.
- **Why mmap**
	- Multiple Processes Accessing Data from Shared File/Kernel resource/Physical Memory(controlled by kernel). 
 	- Provides Huge speed Advantage wrt I/O.
- **Syntax**
```diff
- void* mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
```
- **Parameters**

| Parameter | Meaning |
| --- | --- | 
| void `*addr` | <ul><li> This is virtual Address space of calling process. Start copying at this address.</li></ul> <ul><li>if NULL, then the kernel chooses the (page-aligned) address at which to create the mapping</li></ul> <ul><li>value=NULL is the most portable method of creating a new mapping.</li></ul> |
| size_t length | <ul><li>copy these many bytes from file(fd)</li></ul> <ul><li>size_t is unsigned int</li></ul> |
| int prot | memory protection of mapping |
| int flags | <ul><li>Whether this mapping is visible to other processes or not</li></ul> <ul><li>MAP_SHARED: Share this mapping</li></ul> |
| int fd | file to map |
| off_t offset | <ul><li>Start reading file(Or other object) at offset.</li></ul> <ul><li>offset is multiple of **page size** as returned by **sysconf(_SC_PAGE_SIZE) //See below example**</li></ul> <ul><li>offset is actual physical address(Not Page number).</li></ul> <ul><li>offset=917504 means 917504/4*1024=224th page</li></ul>|

- **Pictorial**
![ImgURL](https://i.ibb.co/tznt7b9/mmap.png)
