## Reexporting / pub use
- After bringing a name into scope with the use keyword, the name available in the new scope is private.
- To use it we combine pub and use. 
- This technique is called **re-exporting** because we’re bringing an item into scope but also making that item available for others to bring into their scope.
```rust
mod module_a {
    pub mod module_b {
        pub fn fun() {}
    }
}

pub use crate::module_a::module_b;

pub fn fun2() {
  module_b::fun();
}
```
