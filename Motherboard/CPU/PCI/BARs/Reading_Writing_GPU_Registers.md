## Reading/Writing GPU Registers
```c
   -> Read/Write on 
   //Map 1MB from start of registerBaseAddress to virtual Memory
   void* mmap(=0, length=131072(1MB), prot=READ|WRITE, flags=SHARED, fd='/dev/mem', offset=registerBaseAddress=d0a0_0000)
   logical_address = 0x7fff19239100
   
How we know 1MB is to be mapped?
   Program                          BAR1
           -----write ffff_ffff--->
	   <---Read BAR back------
    fff0_0000
    Last 20 bits are zeros. 2^20=1MB
           ---Restore value to BAR--->
	   
   //Reading dword(32 bytes) from offset=16 in GPU Register
   > readdword offset=16
   if (logical_address and offset < 1MB) {
     char *p = logical_address=0x7fff19239100 + offset=16;
   if (p != 0)
     cout << *((uint32 *)p);

   //Writing dword=4 at offset=16 in GPU Register
   > regwrite offset=16 value=4
   if (logical_address and offset < 1MB) {
     char *p = logical_address=0x7fff19239100 + offset16;
   if (p != 0)
     *((uint32 *)ptr) = (uint32)val=4;
```
