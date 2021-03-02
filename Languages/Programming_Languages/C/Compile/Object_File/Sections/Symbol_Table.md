## Symbol Table Section
- Array of structures(Elf64_Sym) containing information needed to locate program's symbolic definitions and references.
```c
typedef struct {
        Elf64_Word      st_name;
        unsigned char   st_info;
        unsigned char   st_other;
        Elf64_Half      st_shndx;
        Elf64_Addr      st_value;
        Elf64_Xword     st_size;
} Elf64_Sym;
```
- Each Identifier in source code is assocaited with: type, scope
```c
Example code:
double foo(int count) {
    double  sum = 0.0;
 
    for (int i = 1;  i <= count;  i++)
        sum += bar((double) i);
    return sum;
}

SYMBOL TABLE
Symbol-name      Type      Scope
bar_function     double	  extern
x_double     	  function  parameter
foo             function  	   global
sum	             double	   block
i	               int	    for-loop statement
 ```
