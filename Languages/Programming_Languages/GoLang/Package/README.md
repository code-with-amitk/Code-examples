**Package in Go**
- [Why](#why)
- Packages
  - [main](#main)


## Package in Go = [namespace in C++](Languages/Programming_Languages/c++/namespaces) = [crates in Rust](Languages/Programming_Languages/Rust/Crates_Packages_Modules)
- The package statement is always the first line in a Go file. It specifies the package name that the file belongs to.

<a name=why></a>
#### Why
- This is unique namespace for (variables, functions, types, etc.) defined within the package.

### Packages
<a name=main></a>
#### main
- main package is a special package in Go. It is the entry point for an executable program.
- When we create a Go program, it must have a main package, and within that package, there must be a main function.
