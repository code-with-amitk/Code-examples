## Heap
- Memory area for dynamic Memory allocation
- **Max heap allocated**=Virtual memory size. [What is max VM Size](/Motherboard/CPU/Memory/Virtual_Physical_Memory)
- **Heap Overflow / Memory leak:** When process keeps on allocating more and more memory without freeing it causes Heap overflow. 
  - Aftermaths: System shutdown, Crash, System becoming dead-slow. 
```c
  Example:    
    while(1){ 
      char *p = (char *) malloc(12); 
    }
```
