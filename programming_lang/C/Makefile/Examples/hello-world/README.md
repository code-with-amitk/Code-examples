## HELLO WORLD EXAMPLE

### A. Source
```
// hello.c
#include <stdio.h>
 
int main() {
    printf("Hello, world!\n");
    return 0;
}
```

### B. Makefile (Must be tab stopped not spaces)
```
all: hello.exe                                //Running make without target hits `all`

hello.exe: hello.o
	 gcc -o hello.exe hello.o

hello.o: hello.c
	 gcc -c hello.c
     
clean:
	 rm hello.o hello.exe
```

### Steps Involved
#### `# make`
1. `make` command reaches `Rule = all`.
   - `Rule = all` has pre-requisite `hello.exe`(does not exist), so it looks for a rule to create it.
2. Reaches `Rule = hello.exe` 
   - Pre-requisite `hello.o`(does not exist) so it looks for a rule to create it.
3. Reaches `Rule = hello.o` 
   - Pre-requisite `hello.c`(exists)
   - Runs the command `gcc -c hello.c`
   - Rule finishes, goes back to `Rule = hello.exe`
4. Reaches `Rule = hello.exe` 
   - Pre-requisite `hello.o`(exists)
   - Run its command `gcc -o hello.exe hello.o`.
5. Finally, `Rule = all` does nothing.

#### `# make clean`
> Specifying the `target` to be build with make.
