**Xalan**
  - [Xalan compatiblity with xerces](#comp)
  - **Download, Build**
    - [Linux](#lin)
    - [Windows](#win)

<a name=comp></a>
### Xalan compatiblity with xerces
xalan-1.12 is compatible with xerces-3.23. [Release History](https://apache.github.io/xalan-c/releases.html)

### Download, Build
[Xalan-C++ Releases Page](https://github.com/apache/xalan-c)

<a name=lin></a>
**Linux**
```c
# cmake .;  make;  sudo make install
```

<a name=win></a>
**Windows** [Build steps apache.github.io](https://apache.github.io/xalan-c/build.html)
- [CMAKE_PREFIX_PATH](https://cmake.org/cmake/help/latest/variable/CMAKE_PREFIX_PATH.html)
```c
- Extract xalan in c:

cmd> c:\xalan_c-1.12; mkdir build; cd build
cmd> cmake -G "Visual Studio 16 2019" -DCMAKE_PREFIX_PATH=C:\xerces-c-3.2.3\libs\ -DCMAKE_INSTALL_PREFIX=c:\xalan_c-1.12\libs c:\xalan_c-1.12(\path\to\Xalan-c\source)
cmd> cmake --build . --config Debug
ctest -V -C Debug -j 4
cmake --build . --config Debug --target install
```
