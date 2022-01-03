**Commands**
- [find_package](#fp)
- [target_link_libraries](#tll)


**--build**
```c
$ cmake --build <dir>
```
**--config** For multi-configuration tools
```c
$ cmake --config Debug
```
<a name=fp></a>
#### find_package
Finds and loads settings from an external project
```c
find_package(<package> [version] [EXACT] [QUIET] [MODULE]
             [REQUIRED] [[COMPONENTS] [components...]]
             [OPTIONAL_COMPONENTS components...]
             [NO_POLICY_SCOPE])
```

**list:** Does list operations
```c
list subcommands: APPEND, FIND ..
```
- **set_property:** Set named property on given scope
```c
GLOBAL: global scope
USE_FOLDERS: organize targets into folders.
```
- **source_group:** Define a grouping for source files in IDE project generation
```c
source_group ("Header Files" FILES $(varHeaderFiles))
source_group ("Source Files" FILES $(varSourceFiles))
source_group ("Resource Files" FILES $(varResourceFiles))
```
**--target** Build tgt instead of default targets.

<a name=tll></a>
### target_link_libraries
Specify libraries or flags to use when linking a given target and/or its dependents.
```c
target_link_libraries(<target> ... <item>... ...)
```

```c
$ cmake --target <tgt>
```
- **add_executable:** Add an executable to the project using the specified source files.
- **link_directories:** Add directories in which the linker will look for libraries
