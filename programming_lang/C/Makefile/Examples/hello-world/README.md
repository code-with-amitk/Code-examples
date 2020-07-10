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

### C. RULES
#### C1. Running make `without argument` hits target `all` in the makefile.
```
# make                  OR                     make all (both same)
gcc -c hello.c
gcc -o hello.exe hello.o
```
