## Linker Errors
1. **linker input file unused because linking not done**
```bash
# g++ -Wall -c -I. -I(include-path) -O2 -std=c++11 -fpic -o test.o archive.a main.o
g++: warning: archive.a: linker input file unused because linking not done
```
  - Solution: g++ -c means `compile the source file`. If you meant to link it, remove -c from the command line.
2. **Undefined Reference**
  - *2a.* undefined reference to operator delete(void*, unsigned long)
```bash
Solution-1:
Compiler finds declaration and compiles the code using it. Linker cannot find definition
Do VCOMPILER changes in Tool/build/make/commonrules_gcc
Provide -L/usr/lib64/boost169 in VFLAGS in commonrules_gcc
OR LDLIBS += -lboost_system LDLIBS += -lboost_filesystem inside Tool/build/make/commonrules_gcc
```
  - *2b.* undefined reference to boost::system::generic_category() 
```bash
Solution-1:   {tullib compiles boost in  tullib/common/lib/boost/libs/}
# vim Tuls/apps/console/xSRMB/Makefile
  LDFLAGS += -Ltullib/common/lib/boost/libs/system/dbg/
  LDFLAGS += -Ltullib/common/lib/boost/libs/filesystem/dbg/
  LIBS += -lboost_system
  LIBS += -lboost_filesystem

Solution-2:
# yum install boost* -y
# vim Tuls/apps/console/xSRMB/Makefile
  LIBS += -lboost_system
```
