- [What is Function](#what)
- [Returning from Function](#return)
  - [1. Function returning a value](#return_val)
  - [2. Function returning struct](#return_struct)
  - [3. Function Taking struct as argument](#take_struct)

<a name=what></a>
## Functions
- Function definition starts with fn. Coding convention followed in Rust is snake case ie underscores.
- See another_fun() is defined after main() that means only function definition is required, place(above or below main()) does not matter.
- **Parameters in function:** Type Annotation is mandatory in function parameters.
```rs
fn main() {
  println!("Main\n");
  another_fun (5, 6);
}
fn another_fun(x:i32, y:i32){               //Type annotation mandatory
  println!("Another_fun x: {}", x);
  println!("Another_fun y: {}", y);
}
```

<a name=return></a>
## Returning from Function
- _a._ Type of return value is specified with `->`
- _b._ Last statement in function(without semicolon) is the return value.

<a name=return_val></a>
### 1. Function returning a value
```rs
fn main() {
  let y:i32 = fun (5);
  println!("fun y: {}", y);
}
fn fun(x:i32) -> i32{              //a 
  println!("fun x: {}", x);
  6                                 //b
}
```

<a name=return_struct></a>
### 2. Function returning struct
- [How Struct is defined, initialized in rust](/Languages/Programming_Languages/Rust)
```rs
struct User {
    name: String,
    id:i32,
    active:bool
}

fn main() {
    let u = fun(String::from("Amit"),32);
    println!("{}",u.name);
}

fn fun(name:String, id:i32) -> User {
    User {
        name:name,
        id:id,
        active:true
    }
}
```
- **Writing struct in shorthand:** When function's parameter and struct name are same. We can skip rewriting the name.
```rust
fn fun(name:String, id:i32) -> User {
    User {
        name,                             //Rewriting of name, id is skipped
        id,
        active:true
    }
}
```

<a name=take_struct></a>
### 3. Function Taking struct as argument
- *1.* Passing Structure as Reference ie [BORROWING not taking ownership](/Languages/Programming_Languages/Rust)
- *2.* Accepting function as Reference
```rust
struct dimen {
    len:u32,
    width:u32
}

fn main() {
    let a = dimen {
        len:10,
        width:20
    };
    println!("{}",area(&a));    //1
}

fn area(b:&dimen) -> u32 {      //2
    b.len*b.width
}
```
