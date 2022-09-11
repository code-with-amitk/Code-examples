- [CTest](#ct)
- [Using CTest](#u)


<a name=ct></a>
## CTest
- Cmake provided test framework. 
- Uses the return type of a unit test program to decide whether the test worked correctly.

<a name=u></a>
## Using CTest
**[Code having CTest](/DS_Questions/Questions/FileHandling/ParseFile_DumpInJsonXML_boost/)**
```c
1. Create Tests directory

2. Add following lines in CMakeLists file
$ cat CMakeLists.txt
  enable_testing()
  add_subdirectory(Tests)
  ADD_EXECUTABLE( test1 src/test1.cc )
  ADD_TEST( test1 test1 )  
  
3. Create file containing functions containing tests with int main().  
```
