**Package in Go**
- [Why](#why)
- Packages
  - [main](#main)
- [import statement](#imp)

## Package in Go = [C++(namespace)](Languages/Programming_Languages/c++/namespaces) = [Rust(crates)](Languages/Programming_Languages/Rust/Crates_Packages_Modules)
- The package statement is always the first line in a Go file. It specifies the package name that the file belongs to.

<a name=why></a>
#### Why
- This is unique namespace for (variables, functions, types, etc.) defined within the package.

### Packages
<a name=main></a>
#### main
- main package is a special package in Go. It is the entry point for an executable program.
- When we create a Go program, it must have a main package, and within that package, there must be a main function.

<a name=imp></a>
### import statement
import keyword is used to include external packages/modules in Go program.
```go
import "fmt"
or 
import (              //import multiple packages
    "fmt"
    "math"
)

// Use functions in package using dot statement
fmt.Println("Hello, world!")
```
