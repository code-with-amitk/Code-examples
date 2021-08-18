**Xalan**
  - [Xalan compatiblity with xerces](#comp)
  - **Download, Build**
    - [Linux](#lin)
    - [Windows](#win)

<a name=comp></a>
### Xalan compatiblity with xerces
xalan-1.12 is compatible with xerces-3.23. [Release History](https://apache.github.io/xalan-c/releases.html)

### Download, Build
- Download from [Xalan-C++ Releases Page](https://github.com/apache/xalan-c)

<a name=lin></a>
**Linux**
```c
# cmake .;  make;  sudo make install
```

<a name=win></a>
**Windows** [Build steps apache.github.io](https://apache.github.io/xalan-c/build.html)
```c
- Extract xalan in c:

$ cd xalan; mkdir build; cd build
cmake -G "Visual Studio 16 2019" -DCMAKE_INSTALL_PREFIX:PATH=D:\xalan-c c:\xalan(\path\to\Xalan-c\source)
cmake --build . --config Debug
ctest -V -C Debug -j 4
cmake --build . --config Debug --target install
```
