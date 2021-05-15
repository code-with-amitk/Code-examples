## Transferring Ownership In Return Value
- Returning values can also transfer ownership
```rust
fn main() {
  let s1 = fun1();                     //fun() moves its return value into s1

  let s2 = String::from("hello");
  
  let s3 = fun2(s2);                  //s2 is moved into fun2() which also moves its return value into s3
}

fn fun1() -> String {            //fun() will move its return value into the function that calls it
  let some_string = String::from("hello");
  some_string                   //some_string is returned ie moved
}

fn fun2(a_string: String) -> String {     
    a_string                  // a_string is returned and moves out to the calling function
}
```
