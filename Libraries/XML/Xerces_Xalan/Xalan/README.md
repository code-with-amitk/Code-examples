**Xalan**
  - [Xalan compatiblity with xerces](#comp)
  - **Build**
    - [Linux](#lin)
    - [Windows](#win)

<a name=comp></a>
### Xalan compatiblity with xerces
xalan-1.12 is compatible with xerces-3.23. [Release History](https://apache.github.io/xalan-c/releases.html)

### Build
<a name=lin></a>
**Linux**
```c
# cmake .;  make;  sudo make install
```

<a name=win></a>
**Windows** [Build steps apache.github.io](https://apache.github.io/xalan-c/build.html)
- [CMAKE_PREFIX_PATH](https://cmake.org/cmake/help/latest/variable/CMAKE_PREFIX_PATH.html)
```c
//Get latest xalan from github    //Release pages https://github.com/apache/xalan-c
- Extract xalan in c:

cmd> c:\xalan_c; mkdir build
cmd> cd build
cmd> cmake -G "Visual Studio 16 2019" -DCMAKE_PREFIX_PATH=C:\xerces-c\libs\ -DCMAKE_INSTALL_PREFIX=c:\xalan_c\libs c:\xalan_c(\path\to\Xalan-c\source)
cmd> cmake --build . --config Debug
Issue-1: error MSB8066: Custom build for "C:\xalan-c\build\CMakeFiles\54721b435eedbbf1c365bb7e2edfcd61\inmemory-dependencies.rule" exited with code -1073741515
Sol: https://github.com/apache/xalan-c/pull/37

cmd> ctest -V -C Debug -j 4
cmd> cmake --build . --config Debug --target install
```
