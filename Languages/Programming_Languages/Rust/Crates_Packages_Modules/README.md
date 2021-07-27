- [Crates](#crate)
  - [1. rand](#rand)
- [Packages](#Packages)
- [Modules](#Modules)
  - [Creating a module & accessing its function](#create)
  - [super keyword](#super)
  - [struct inside module](#struct)
  - [enum inside module](#enum)
  - [1. use keyword](#use)
    - [1. use as](#use_as)
    - [2. pub use / Reexporting](#pub_use)

<a name=crates></a>
## Crates 
crate is a binary(executable file having main()) or library(shared or static library) in rust.

<a name=rand></a>
### 1. rand
Rust library for random number generation.
- **Using rand crate**
```rs
$ Cargo.toml
[dependencies]
rand = "0.8.0"    //Add rand library as dependency, cargo will download from crates.io
```
- [thread_rng()](//https://docs.rs/rand/0.8.4/rand/fn.thread_rng.html): Generate random number
```rsp
thread_rng().gen_range(0..100)    //Generate random no between [0,100)    //pub fn thread_rng() -> ThreadRng
```

<a name=Packages></a>
## Packages
1 package is one or more crates that provide a set of functionality. A package contains a [Cargo.toml](../Cargo_BuildSystem) file that describes how to build crates.

<a name=Modules></a>
## Modules
- Similar to [namespaces, modules in c++](/Languages/Programming_Languages/c++) & [modules in python](/Languages/ScriptingLanguages/Python/).
- Modules organizes code within a crate into groups for ease of use. Code inside module can be functions, enums, structs etc.
- By default Functions within modules are private ie to access function and we need to make it public by placing `pub` in front of it.

<a name=create></a>
### Creating a module & accessing its function
- _1._ Complete Hierarchy has to be made expilicitly public ie module_b & fun(). By default everything is private and cannot be accessed.
- _2._ functions can be accessed either using Absolute or relative path.
  - Absoulte path: starts from crate
  - Relative path: starts from scope in which module is called. //Preffered
```rs
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

<a name=super></a>
### super keyword
- With keyword `super`, We can construct relative paths that begin in the parent module. This is like starting a filesystem path with the `..` syntax
```rs
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

////////Similar to filesystem///////////
crate
 └── module_a
     ├── fun_a
     └── module_b      <-------
         ├── fun_b              |
         └── module_c          super can reach parent (../)
             └── fun_c          |
             └── super ---------
```

<a name=struct></a>
### struct inside module
- _1._ To access structure has to declared public, but still all feilds of struct remains private.
- _2._ To access any field, that feild has to be made public.
- _3._ We need to define a implementation fo access fields in `module_a::st` since there is a private member.
- _4._ Then we can access members using dotted notation.
```rs
mod module_a {
    pub struct st{           //1
        pub a:u32,          //2
        b:u16,              //This remains pvt
    }

    impl test {                         //3
        pub fn fun(x: u32) -> st {
            st {
                a: x,
                b: 10,
            }
        }//fun
    }//test
}//module_a

pub fn fun1 {
  let mut var = crate::test::fun(30);         //4
  println!("{}", var.st.a);               //30
  println!("{}", var.st.b);               //10
}
```

<a name=enum></a>
### enum inside module
- Unlike structure in module, if [enum](/Languages/Programming_Languages/Rust) is public all its variants are also public. We need to explicitly make every enum variant as public as in struct.
```rs
mod module_a {
    pub enum color {
        red,          //all enum variants are public if enum is public
        yellow,
    }
}

pub fn fun() {
    let var = module_a::color::red;
}
```

<a name=use></a>
### use keyword
- Similar to [type alias/using keyword in c++](/Languages/Programming_Languages/c++/C++11_14_17_20/c++11/), use is used to bring Paths into Scope.
```rs
mod module_a {
    pub mod module_b {
        pub fn fun() {}
    }
}

use crate::module_a::module_b;

pub fn fun1() {
    module_b::fun();                        //Now module_b becomes a valid Name(as defined in crate scope)
}
```

<a name=use_as></a>
#### 1. use as
- Defining shorter name for path.
```rs
use std::fmt::Result as FmtResult;
use std::io::Result as IoResult;

fn function1() -> FmtResult {
    // --snip--
}

fn function2() -> IoResult<()> {
    // --snip--
}
```

<a name=pub_use></a>
#### 2. pub use / Reexporting
- After bringing a name into scope with the use keyword, the name available in the new scope is private, To use it we combine pub and use. 
- This technique is called **re-exporting** because we’re bringing an item into scope but also making that item available for others to bring into their scope.
```rs
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
