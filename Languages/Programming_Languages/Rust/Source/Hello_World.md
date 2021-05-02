## Hello World
- *1.* As in c,C++ rust starts at main() function.
- *2.* Rust Macro. Anything followed by `!` is called rust macro Not function.
- *3.* rustc Compiler. Compile the program using rustc compiler.
- *4.* Three files are created. rs:Containing source code. exe:Executable file. pdb:file containing debugging information
```rust
# vim helloworld.rs
fn main() {                         //1
    println!("Hello, world!");      //2
}

> rustc helloworld.rs               //3
> dir
helloworld.exe
helloworld.pdb
helloworld.rs
> helloworld.exe
Hello World!
```
