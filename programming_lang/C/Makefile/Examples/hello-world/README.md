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
1. `make` command reaches `rule = all`.
2. `Rule = all` has pre-requisite `hello.exe`, so it looks for a rule to create it.
3. `Rule = hello.exe` has a pre-requisite `hello.o`, so it looks for a rule to create it.
4. `Rule = hello.o` has a pre-requisite `hello.c`. 
	 - Pre-requisite exists.
	 - Runs the command `gcc -c hello.c`
	 - Rule finishes, goes back to `Rule = hello.exe`
5. Comes to `Rule = hello.exe` 
	 - Pre-requisite(hello.o) created.
	 - Run its command `gcc -o hello.exe hello.o`.
6. Finally, `Rule = all` does nothing.
