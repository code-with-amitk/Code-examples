## Function returning struct
- [How Struct is defined, initialized in rust](../../../Data_Types/Compound/Struct)
- **Function returning a struct**
```rust
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
