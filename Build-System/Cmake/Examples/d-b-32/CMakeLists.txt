
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

source_group ("Header Files" FILES $(varHeaderFiles))   #4. Create this hierarchy in Visual studio
source_group ("Source Files" FILES $(varSourceFiles))
source_group ("Resource Files" FILES $(varResourceFiles))

add_executable (d-b-3-2 ${varHeaderFiles} ${varSourceFiles} ${varResourceFiles})

if (MSVC)                   # For windows
else()
    link_directories(                               #5. Linker will look for libraries inside these directories
        /libs/Common
        /libs/t-ul-lib
        /libs/boost-libs
    )
    
    target_compile_definitions(...)
    target_include_directories(...)
    target_link_libraries(...)
endif()
