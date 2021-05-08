## Integer Overflow
- **What?** Assigning value outside of allowed range. Example:
```rust
  let a:u8 = 256      //This is integer overflow, because u8 0-255 values can be assigned
```  
- **Compiled in debug mode?**
  - When program is compiled in debug mode, Rust includes checks for integer overflow & program will PANIC(exit with error) at runtime.
- **Compiled in release mode(--release flag)**
  - When program is compiled in release mode, Rust DOES NOT include checks for integer overflow.
  - At runtime, overflow occurs Rust performs 2’s complement wrapping. 
  - **2’s complement wrapping?**
    - Values greater than 255 gets wrapped around. 256 becomes 0. 257 becomes 1 and so on. No PANIC happens.
