## Creating a module & accessing its functions.
- _1._ Complete Hierarchy has to be made expilicitly public ie module_b & fun(). By default everything is private and cannot be accessed.
- _2._ functions can be accessed either using Absolute or relative path.
  - Absoulte path: starts from crate
  - Relative path: starts from scope in which module is called. //Preffered
```rust
mod module_a {
    pub mod module_b {              //1. module_b made public
        pub fn fun1() {              //1. fun() made public
            print!("fun");
        }
        fn fun2(){}
    }
}

fn main(){
    crate::module_a::module_b::fun1();   //2. Absolute path
    module_a::module_b::fun1();          //2. Relative path
    
    module_a::module_b::fun2();         //Error, cannot access private
}

////////Similar to filesystem///////////
crate
 └── module_a
     |── module_b
         ├── fun1
         └── fun2
```
