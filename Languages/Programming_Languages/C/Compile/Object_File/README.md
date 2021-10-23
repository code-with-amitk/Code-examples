- [Object File](#o)
- [Object File Types](#t)
- **Object File Format**
  - [1. ELF](#elf)

<a name=o></a>
## Object file
This is created during [Compliation process](../).
**Linking View**
```c
|ELF-Header|Program-Header-Table(Optional)|<section_header> Section-1|...|<section_header> Section-n|...|Special-Sections|...|Section-Header-Table|
```
**Execution View**
```c
|ELF-Header|Program-Header-Table|Segment-1|Segment-2|...|Section-Header-Table(optional)|
```

<a name=t></a>
## Object File Types
- **1. Relocatable Object File:** Used for Linking with other object files to create exe, Shared Objects. 
- **2. Executable Object:** File Ready to execute
- _3. Shared Object File:_ Combined with other `*.o` or relocatable objects 

## Object File Formats
<a name=elf></a>
### 1. ELF(executable and linking format)
- All ELF binaries have these 4(.bss,.data,.rodata,.text) sections always present and these makes Memory layout of process when loaded in memory.
```c
  Section   | Contains
------------|------------------
  .bss      | Uninitilized data. Unitialized data segment in (Memory layout of process)
  .data     | Initilized data.   Initialized data segment
  .rodata   | RO data.           Initialized RO DS
  .text     | Code
  .dynamic  | Dynamic linking information
  .comment  | Comment information, typically contributed by the components of the compilation system.
  .symtab:  | [Symbol table](Sections/Symbol_Table.md)
```
