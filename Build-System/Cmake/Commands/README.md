## Commands
- **a. list:** Does list operations
```c
list subcommands: APPEND, FIND ..
```
- **b. set_property:** Set named property on given scope
```c
GLOBAL: global scope
USE_FOLDERS: organize targets into folders.
```
- **c. source_group:** Define a grouping for source files in IDE project generation
```c
source_group ("Header Files" FILES $(varHeaderFiles))
source_group ("Source Files" FILES $(varSourceFiles))
source_group ("Resource Files" FILES $(varResourceFiles))
```
- **d. add_executable:** Add an executable to the project using the specified source files.
- **e. link_directories:** Add directories in which the linker will look for libraries
