## use keyword
- Similar to [type alias/using keyword in c++](/Languages/Programming_Languages/c++/C++11_14_17_20/c++11/)
- **What?** we bring Paths into Scope with the use Keyword.
```rust
mod module_a {
    pub mod module_b {
        pub fn fun() {}
    }
}

use crate::module_a::module_b;

pub fn fun1() {
    module_b::fun();
}
```
