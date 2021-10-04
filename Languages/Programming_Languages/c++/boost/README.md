**Boost**
- [Installation](#i)
- [Linking Visual Studio to Boost](#l)

## Boost
- Boost is Collection of around 80 libraries for 
  - Linear Alzebra, pseudorandom number generation, multithreading, image processing, regular expressions, and unit testing. 
- Any one can get/modify and provide to 3rd person. Boost makes extensive use of Generic programming/Templates, Boost are templates defined inside namespaces.
- **hpp files(header files):** HPP files may contain variables, constants and functions.
  
### Installation
Uses B2(boost.build) system
#### linux
```c
# git clone --recursive https://github.com/boostorg/boost.git	 //NOTE RECURSIVE is most important. Time taken=45 min
# cd boost
# git checkout <branch-name>    //branch you want to use
# cd tools/build

// Build b2 engine. These commands are executed.
//   ./src/engine/build.sh
//   cp ./src/engine/b2 .
# chmod +x bootstrap.sh; ./bootstrap.sh

//Install
# mkdir ./install-dir
# ./b2 install ./install-dir

OR
# yum    install    -y    boost-devel        //Now just Include header files and start using
```
#### Windows
```cpp
Download latest source. Follow README to complie.
stage/lib -> contain all *.lib
boost -> contain all header files
```

<a name=l></a>
### Linking Visual Studio to boost
```c
Project > Properties > VC++ Directories
Include Directories > Select location of boost
Library Directories > boost\stage\lib
```
