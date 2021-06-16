## Stack
- **Stores:** Local variables, Registers, Stack Frame pointer, return address, stack-based parameters, stack frame as LL
- When on shell `# cp a.txt b.txt` is typed complete string `cp,a.txt,b.txt` is stored on stack.
- **[Stack frame/Allocation records](Stack_Frame)**
- **Stack Overflow?** 
  - When program overflows stack based local variable or when process uses all its stack. At end of process's stack there is a GUARD PAGE, when process goes into it. Its a Segmentation Fault.
  - Code causing stack overflow:
```c
    fun() {
        fun();
    }
```    
- **Stack Smashing?** Stack overflow caused deliberately as part of an attack.
- **MAX STACK SIZE / Maximum stack allocated to process at start**
  - Why 8MB of stack? In a single-threaded process, the address space reserved for the stack can be large and difficult to overflow
  - Why Stack size != Virtual Memory size (As Heap size = Virtual Memory size)? 
    - Every thread has its own Stack.if thread-1 consumes all virtual memory and thread-2 also, nothing left.
```c
 8 MB(Default)  #cat /proc/pid/limits     //Linux
 1 MB(Default)                            //Windows
```
- **Changing stack size?** ulimit -u unlimited
