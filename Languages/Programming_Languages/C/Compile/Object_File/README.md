## Object File Types

||Used for|Mandatory Sections|
|---|---|---|
|1.Relocatable Object File|Linking with other object files to create exe, Shared Objects|Code,Data|
|2.Executable Object File|Ready to execute||
|3.Shared Object File|Combined with other `*.o` or relocatable objects||

## Object File Format
- Compiler generates assembly code then assembler generates Object code.
- **Linking View**
```c
|ELF-Header|Program-Header-Table(Optional)|<section_header> Section-1|...|<section_header> Section-n|...|Special-Sections|...|Section-Header-Table|
```
- **Execution View**
```c
|ELF-Header|Program-Header-Table|Segment-1|Segment-2|...|Section-Header-Table(optional)|
```

### 1. ELF(executable and linking format)
- This is Meta data of file to be created processor, encoding etc.
```c
typedef struct {
  unsigned char   e_ident[16]; 
  Elf64_Half      e_type;     //Identifies the object file type. 1:Relocatable, 2:Executable, 3:Shared object, 4:core
  Elf64_Half      e_machine;  //required architecture. 2:SPARC, 3:Intel
  Elf64_Word      e_version;  //
  Elf64_Addr      e_entry;
  Elf64_Off       e_phoff;
  Elf64_Off       e_shoff;
  Elf64_Word      e_flags;
  Elf64_Half      e_ehsize;
  Elf64_Half      e_phentsize;
  Elf64_Half      e_phnum;
  Elf64_Half      e_shentsize;
  Elf64_Half      e_shnum;
  Elf64_Half      e_shstrndx;
} Elf64_Ehdr;
```
### 2. Program-Header-Table
- tells the system how to create a process image.

### 3. Sections
- **3.1 Section Header?** What all sections are present in object file.
```c
typedef struct {
        Elf64_Word      sh_name;
        Elf64_Word      sh_type;
        Elf64_Xword     sh_flags;
        Elf64_Addr      sh_addr;
        Elf64_Off       sh_offset;
        Elf64_Xword     sh_size;
        Elf64_Word      sh_link;
        Elf64_Word      sh_info;
        Elf64_Xword     sh_addralign;
        Elf64_Xword     sh_entsize;
} Elf64_Shdr;
```

### 4. Special Sections
- Have program and control information.
```c
  |.bss|.comment|.data|.data1|.dynamic|...|.relname|.rodata|.rodata1|.symtab|.text|
```
- .bss: Uninitialized data that contribute to the program's memory image. the system initializes the data with zeros when the program begins to run.
- .comment: Comment information, typically contributed by the components of the compilation system.
- .data, .data1: Initialized data that contribute to the program's memory image.
- .dynamic: Dynamic linking information
- .rodata, .rodata1: Read-only data that typically contribute to a non-writable segment in the process image
- .symtab: [Symbol table](Sections/Symbol_Table.md)
- .text: The text or executable instructions of a program.
