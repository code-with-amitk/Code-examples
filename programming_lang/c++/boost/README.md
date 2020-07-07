# BOOST
- **What** Collection of around 80 libraries for 
  - Linear Alzebra, pseudorandom number generation, multithreading, image processing, regular expressions, and unit testing. 
- Any one can get/modify and provide to 3rd person
- **How it works** Boost makes extensive use of Generic programming/Templates, Boost are templates defined inside namespaces.
- **hpp files** File extension for a header file format used by MarsDigital C++ (previously Zortech C++), Borland C++ and other C++ compilers. HPP files may contain variables, constants and functions.


## A. Installation
### TERMS TO UNDERSTAND
#### **1. (B2 = Boost.Build) Build system**
  - **What** This is compiler & platform-independent build system. B2 supports many compilers.
  - Boost does not know anything by himself, everything is written into jam files.
  - ****.jam file*** Configuration file for b2
    - Create a Configuration file telling where to find source files
    - Every directory can be build with jam file, and b2 keeps looking it upto root.
    - ***jamroot.jam*** b2 climbs up parent directories until it finds this configuration file. This tells b2 not to look for jam files further.
    - ***No jam files?*** If you start b2 from a directory which contains no Jamfiles and start the program you get an error message. However b2 doesn't complain that it can't find a Jamfile. It complains about not finding the build system.
    - ***How it works***
      1. b2 starts. Looks for `boost-build.jam` in pwd. 
      2. Searches `jamroot.jam` until root boost directory.

#### A1. (Linux) From source github
```
# git clone --recursive https://github.com/boostorg/boost.git		    //Please note RECURSIVE is most important. Time taken=45 min
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
```

### A2. (Linux) 
```
# yum    install    -y    boost-devel        //Now just Include header files and start using
```

#### A2. On Windows
```
- Install cygwin    
- unpack boost_1_22_0.7z, install in Windows    
- Include Header files and start using it
```
