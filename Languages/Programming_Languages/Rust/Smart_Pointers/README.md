**Smart Pointers**
- **Most Common Smart Pointers**
  - [Box`<T>`](#box)

## Smart Pointers
Same as [C++ Smart,shared pointers](/Languages/Programming_Languages/c++/pointers), allocates memory and deallocates when all references to it goes out of scope. References are also smart pointers but they only point to 1 value. Examples: `vec<T>`, String.
- Smart pointers are usually implemented using structs. The characteristic that distinguishes a smart pointer from an ordinary struct is that smart pointers implement the **[Deref and Drop traits](/Languages/Programming_Languages/Rust)**

### Most Common Smart Pointers
#### `Box<T>`
This is smart pointer allocated on heap and variable to store pointer lies on stack.
```rs
fn main() {
    let y = Box::new(5);    //5 is allocated on stack. y points to 5
    println ("{}", *y);     //5
}   //box deallocated here
```
