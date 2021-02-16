## Linker Errors
1. **linker input file unused because linking not done**
```bash
# g++ -Wall -c -I. -I(include-path) -O2 -std=c++11 -fpic -o test.o archive.a main.o
g++: warning: archive.a: linker input file unused because linking not done
```
  - Solution: g++ -c means `compile the source file`. If you meant to link it, remove -c from the command line.
2. **Undefined Reference**
  - *2a.* operator delete(void*, unsigned long)
```bash
undefined reference to operator delete(void*, unsigned long)

Solution:
Compiler finds declaration and compiles the code using it. Linker cannot find definition
Do VCOMPILER changes in Tool/build/make/commonrules_gcc
Provide -L/usr/lib64/boost169 in VFLAGS in commonrules_gcc
OR LDLIBS += -lboost_system LDLIBS += -lboost_filesystem inside Tool/build/make/commonrules_gcc
```
  - *2b.*
