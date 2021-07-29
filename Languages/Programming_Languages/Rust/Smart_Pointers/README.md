**Smart Pointers**

## Smart Pointers
- Same as [C++ Smart,shared pointers](/Languages/Programming_Languages/c++/pointers), allocates memory and deallocates when all references to it goes out of scope.
- References are also smart pointers but they only point to 1 value.
- This is provided by `Box<T>` in rust.
```rs
fn main() {
    let x = 5;
    let y = Box::new(x);    //x is allocated on stack. y points to x.
    println ("{}", *y);     //5
}
```
