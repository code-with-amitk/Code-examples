**[Apache Xerces](https://xerces.apache.org/xerces-c/index.html)**
- What is Xerces
- **Build, Configure**
  - [Linux](#linux)
  - [Windows](#win)
- **[Source](#src)**

## Xerces
XML parsing/manipulating/validating library written in C++ using the DOM, SAX, and SAX2 APIs.

## Build, Configure
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
- Download xerces.zip from https://xerces.apache.org/xerces-c/download.cgi. Extract in c:\
- Install cmake
cmd> cd c:\xerces; mkdir build; cd build
cmd> cmake -G --help
cmd> cmake -G "Visual Studio 16 2019" -DCMAKE_INSTALL_PREFIX=C:\xerces\libs  (c:\xerces)path_to_xerces-c_source_having_CMakeLists.txt
cmd> cmake --build . --config Debug
cmd> ctest -V -C Debug -j 4
cmd> cmake --build . --config Debug --target install
c:\xerces\libs\xerces-c_3.2.dll
c:\xerces\libs\lib\xerces-c_3D.lib

//Using xerces functionality
Visual-Studio > Console-App(C++) 
  Include Headers as 
```

<a name=src></a>
## Examples
- [Parse element from XML](Parse_Element_From_XML_File.md)
- [Merge 2 XMLs and Write in out.xml](Merge_2_XMLs_and_Write_in_out_xml.md)

