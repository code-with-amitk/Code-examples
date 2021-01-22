## Progress Bar
- **What?** This is source code for cross platform progress bar. Same code(without change) will show progress bar on:
  - Linux: Inside CLI
  - Windows: Inside Windows console applications
- **Building with cmake**
  - cmake is Build system generator, that means it generates Makefile(on Linux) and Visual Studio Project files(on Windows) for building same source code.
  
## Steps?
### 1. Create Directory structure
```c
  # ls -ltr 
    |- libs
        |- include/pdcurses
                    |- curses.h
                    |- curspriv.h
                    |- panel.h
                    |- term.h       
        |- windows/pdcurses
                    |- pdcurses.lib
    |- source
        |- progress_bar.cpp
    |- CMakeLists.txt
```
### 2. Build on Linux and Windows
- **A. Linux**
```c
  # cmake .   //it generates Makefile
  # make
```
- **B. Windows**
  - *1.* Get VCProject files
```c
  # cmake -G "Visual Studio 16 2019" .
```  
  - *2.* Build source using VCProject files.
