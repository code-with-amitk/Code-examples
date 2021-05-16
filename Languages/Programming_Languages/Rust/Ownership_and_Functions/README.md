## Ownership
- **Ownership** is similar to *Call By Value*.
- For variable allocated on Heap ([Datatype String](../Data_Types/String_Type)) variable is moved.
- For variable allocated on Stack (Eg: int, float) variable is copied.
```rust
fn main() {
  let s = String::from("hello");    //Allocated on HEAP
  fun(s);                           //s's value is MOVED into function and no longer valid here
  println!("s: {}", s);             //Complie time error
                                    
  let x = 5;                        //Allocated on STACK
  fun1(x);                          
  println!("x: {}", x);            //Ok, x=5

}

fn fun(some_string: String) { 
    println!("{}", some_string);
} //Here, some_string goes out of scope and `drop()` is called. The backing memory is freed.

fn fun1(some_integer: i32) {
    println!("{}", some_integer);
}
```

### [Transferring ownership in return value](Ownership_In_Return_Value.md)
