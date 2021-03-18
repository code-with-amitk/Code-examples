
varSrcDir = /path/
list (APPEND varSourceFiles               #1. Create list "varSourceFiles" containing all source files
    ${varSrcDir}/main.cpp
    ${varSrcDir}/Command.cpp
    ...

varHdrDir = /path                           #2. Create list "varHeaderFiles" containing all header files
list (APPEND varHeaderFiles
    ${varHdrDir}/main.h
    ${varHdrcDir}/Command.h
    ...
    
set_property (GLOBAL PROPERTY USE_FOLDERS ON)   #3. Create folders to organize .vcproj on WINDOWS

source_group ("Header Files" FILES $(varHeaderFiles))   #4. 
source_group ("Source Files" FILES $(varSourceFiles))
source_group ("Resource Files" FILES $(varResourceFiles))
