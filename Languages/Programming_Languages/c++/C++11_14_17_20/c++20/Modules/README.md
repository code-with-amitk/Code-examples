- [What is Module](#what)
- [Comparison](#comp)
  - [1. Modules vs Header files](#modh)
  - [2. Modules vs Libraries](#modl)

<a name=what></a>
## Module
- This is File containing functions, class, variables etc. Same as [python module](/Languages/ScriptingLanguages/Python/Modules). Modules can be used side-by-side of header files, see difference below.
- **Why?** Modules help divide large amounts of code into logical parts.

<a name=comp></a>
## Comparisons

<a name=modh></a>
### 1. Modules vs Header Files
- Modules include: import modules in any order without concern for macro redefinitions
- Header includes: provide header guards so that its not included again

<a name=modl></a>
### 2. Modules vs Libraries
- Modules: 
  - Write `fun()` compile it, import test.cpp
  - Compilation Time: Hugely reduced
- Libraries: 
  - Write `fun()` compile. create library. include header
  - Compilation Time: High wrt modules



