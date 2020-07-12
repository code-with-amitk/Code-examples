## 1. linker input file unused because linking not done
```
# g++ -Wall -c -I. -I(include-path) -O2 -std=c++11 -fpic -o test.o archive.a main.o
g++: warning: archive.a: linker input file unused because linking not done
```
- Solution
  - g++ -c means `compile the source file`. If you meant to link it, remove -c from the command line.
