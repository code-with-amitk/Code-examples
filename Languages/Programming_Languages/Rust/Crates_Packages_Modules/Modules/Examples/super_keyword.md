## super keyword
- With keyword `super`, We can construct relative paths that begin in the parent module. This is like starting a filesystem path with the `..` syntax
```rust
mod module_a {
    fn fun_a(){}
    pub mod module_b {
        fn fun_b(){}
        pub mod module_c {
            pub fn fun_c() {
                print!("fun_c");
            }
            //super::fun_a();     //Will not compile. fun_a() is not in parent module ie module_b.
            super::fun_b();       //fun_b() is in parent module ie module_b its ok!
        }
    }
}

fn main(){
    crate::module_a::module_b::module_c::fun_c();   //Absolute path
    //module_a::module_b::fun();          //Relative path
}
```
