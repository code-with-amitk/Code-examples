- [class in Rust](#class)
- [Constructors](#ctr)
  - [1. Creating, Calling Constructor](#cctr)
- [Destructors](https://doc.rust-lang.org/nomicon/destructors.html)
- [class Examples](#ex)
  - [1. class having int member variable, constructor](#ex1)

<a name=class></a>
## Classes in Rust
- Rust does not have class keyword but same functionality can be achieved using [struct and associated functions (ie impl)](/Languages/Programming_Languages/Rust/Data_Types/Compound/Struct/
)
- In rust, datatypes are defined inside struct and functions are associated with them using impl.

<a name=ctr></a>
## Constructors
- There are no [Copy, Default, Assignment, Move ctrs as in c++](/Languages/Programming_Languages/c++).
- Also ctrs in rust might not be same named.
- **Assignment, Move constructors** Does not exist because move semantics are the only semantics in Rust.  x = y just moves the bits of y into the x variable
- **Copy Constructor** Using clone() or copy()
- We can consider ctr as normal function defined inside a namespace scope, accessed using namespace::ctr_name()

<a name=cctr></a>
### 1. Creating, Calling Constructor
- Only way to create constructor is this.
```rs
struct Foo {
    a: u8,
    b: u32,
    c: bool,
}
let foo = Foo { a: 0, b: 1, c: false };
```
- **Example-2**
  - _1._ Struct having 1 int
  - _2._ All methods are defined inside impl
    - _2a. Constructor of class:_ Initializing member variable of struct.
    - _2b. update() method:_ Updates the value of object passed to it.
```rs
struct test {                         //1
    a:i32,
}

impl test{                           //2
    fn ctr() -> Self {               //2a 
        test{                        //Creating variable of type struct test
            a:10,
        }
    }
    fn update(&mut self, b:i32)->bool {  //Takes Object as parameter and updates Object's Contents
        self.a = b;
        true
    }
}

fn main() {
    //let mut var = test{a:20,};       //Does not call ctr
    let mut var = test::ctr();         //Calls ctr
    println!("{}",var.a);              //10
    
    var.update(30);
    println!("{}",var.a);              //30
} 
```
