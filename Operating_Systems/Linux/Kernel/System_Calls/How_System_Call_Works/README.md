## How System Call Works
> Example Reading Disk File or socket using [read()](/Networking/OSI-Layers/Layer-4/Socket_Programming/APIs_Structures)

- [Stack](https://sites.google.com/site/amitinterviewpreparation/c-1), [trap()](/Motherboard/CPU/Memory/Virtual_Physical_Memory/Terms.md), [rax](/Motherboard/CPU/Memory/CPU_Registers)
```c
    USER PROCESS
count = read(fd, buffer, nbytes);
1. user process Push parameters on stack in reverse order
    |fd|
    |buffer|
    |nbytes|
2. Place system-call-number on register(rax)
3. Calls Trap instruction(control moves to kernel space)
```
