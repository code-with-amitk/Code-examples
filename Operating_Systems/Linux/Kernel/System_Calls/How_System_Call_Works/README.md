## How System Call Works
> Example Reading Disk File or socket using [read()](/Networking/OSI-Layers/Layer-4/Socket_Programming/APIs_Structures)

- [Stack](https://sites.google.com/site/amitinterviewpreparation/c-1), [trap()](/Motherboard/CPU/Memory/Virtual_Physical_Memory/Terms.md), [rax](https://code-with-amitk.github.io/Motherboard/Memory/Memory_Types.html), [ISR](https://github.com/code-with-amitk/Code-examples/tree/master/Operating_Systems/Linux/Kernel/Interrupts#isr), [Device Driver](/Device_Drivers), [file_operations](/Device_Drivers/Linux), [Interrupt Controller](/Operating_Systems/Linux/Kernel/Interrupts), [Hard Disk](/Motherboard/CPU/Memory/Hard_Disk)
```c
    USER PROCESS
count = read(fd, buffer, nbytes);
1. user process Push parameters on stack in reverse order
    |fd|
    |buffer|
    |nbytes|
2. Place system-call-number on register(rax)
3. Calls Trap instruction(control moves to kernel space)

                                    KERNEL
                      4. Kernel starts at specific address, Read system-call-number from register
                      5. Find address of system-call-handler/ISR
                      6. Device Drivers already registered & kernel has file_operations 
                            (register_chrdev, struct file_operations)
                            
                                    ------> System-call-handler()
                                           7.Calls file_operations {read()}
                                             
                                                      ----------> DEVICE DRIVER
                                                                8. Generates Interrupt & sends to IC(Interrupt Controller)
                                                                
                                            INTERRUPT CONTROLLER <-----------------------------------------
                                            9. Decides interrupt priority
                                            10. Forwards to disk/socket
                                            
                                                    -----------------------> HARD DISK
                                                    <----------data-------------
                                     <- Copied on Pvt Buffer-               
User process cleans stack                                     
```
