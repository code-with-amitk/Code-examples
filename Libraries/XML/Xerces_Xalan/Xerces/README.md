**[Apache Xerces](https://xerces.apache.org/xerces-c/index.html)**
- **Build**
  - [Linux](#linux)
  - [Windows](#win)
- **[Source](#src)**

## Xerces
XML parsing/manipulating/validating library written in C++ using the DOM, SAX, and SAX2 APIs.

## Build
<a name=linux></a>
**Linux**
```c
# git clone https://github.com/apache/xerces-c.git
# ./configure; make; make install
```
<a name=win></a>
**Windows**
Create new Console-App(C++). Include [headers,xerces_3.2.lib as mentioned here.](/Libraries/Static_Dynamic). Also place xerces-c_3.2.dll in exe's folder.
```c
///////////Method-1 (Working)//////////////////////
Download latest xerces from github. //Release page: https://xerces.apache.org/xerces-c/download.cgi. Extract in c:\
Install cmake
cmd> cd xerces-c; mkdir build; cd build
cmd> cmake -G --help
cmd> cmake -G "Visual Studio 16 2019" -DCMAKE_INSTALL_PREFIX=c:\xerces-c\libs c:\xerces-c//path_to_xerces-c_source_having_CMakeLists.txt
cmd> cmake --build . --config Debug
cmd> ctest -V -C Debug -j 4
cmd> cmake --build . --config Debug --target install
c:\xerces\libs\bin\xerces-c_4_0D.dll
c:\xerces\libs\lib\xerces-c_4D.lib

/////////////Method-2 vcpkg(Working)////////////////////////
cmd> git clone https://github.com/Microsoft/vcpkg.git         //in C:      //https://vcpkg.io/en/getting-started.html
cmd> bootstrap-vcpkg.bat
cmd> vcpkg install xerces-c:x64-windows             //Install all dependencies, compiles and xerces libs in C:\vcpkg\packages

//Using xerces functionality
Visual-Studio > Console-App(C++) 
  Include Headers as 
```

<a name=src></a>
## Examples
- [Parse element from XML](Parse_Element_From_XML_File.md)
- [Merge 2 XMLs and Write in out.xml](Merge_2_XMLs_and_Write_in_out_xml.md)

