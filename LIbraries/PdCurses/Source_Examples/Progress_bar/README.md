## Progress Bar
- **What?** This is source code for cross platform progress bar. Same code(without change) will show progress bar on:
  - Linux: Inside CLI
  - Windows: Inside Windows console applications
- **Building with cmake**
  - cmake is Build system generator, that means it generates Makefile(on Linux) and Visual Studio Project files(on Windows) for building same source code.
  
## Steps?
- *1.* Create this directory structure
```c
  # ls -ltr 
    |- libs
        |- 
    |- source
        |- progress_bar.cpp
    |- CMakeLists.txt
```
