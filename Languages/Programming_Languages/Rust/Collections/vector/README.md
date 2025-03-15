**Vector**
- [Create, Initialize](#cin)
  - [2d vector](#2d)
- Access, Iterate
  - [into_iter()](#itr)
    - [into_iter().enumerate()](#intoe)
- Print
  - [Any Element](#any)
- [Store enum in vector](enumvec)

### [HTML Page](https://code-with-amitk.github.io/Languages/Programming/C++/STL/Containers/Seqeunce_Containers/vector.html)
### [Function in C++,Rust,Python](Languages/Programming_Languages/c++/Standard_Template_Library/container_library/sequence_containers/vectors/README.md)

### [vec or Vec](https://doc.rust-lang.org/std/vec/struct.Vec.html#method.push)
- Same as in C++, Storing more than 1 value of same type contigously in memory. Remember All collections are **allocated on HEAP**.
- Stack is implemented using vector in rust
- **How vector is internally implemented in Rust?**
```rs
- All parts are stored together
struct Vec {
  length: u32,            //Present size of vector
  ptr: RefCell,           //Pointer to allocate Memory on Heap
  capacity: u32,          //Max size vector can hold, after this vector need to be resized/reallocated
}

- In C++: Same but 3 items can be stored seperately
```
- **Copy trait not implemented for vector?**
  - Copy Trait is only implemented for types that copied safely BITWISE. if we create a copy of vector, then there would be 2 owners of same data which voilates [Rust ownership Rule](/Languages/Programming_Languages/Rust#own). But vector implements [Clone Trait](/Languages/Programming_Languages/Rust/Triat_Interface/README.md#clone).

<a name=2d></a>
#### 2d vector
```rs
  let empty_matrix: Vec<Vec<i32>> = vec![vec![0; columns]; rows];
OR         
  let mut v : Vec<Vec<usize>> = vec![Vec::with_capacity(row); col];
```

<a name=update></a>
### Update
Since variables in rust is [immutable by default](/Languages/Programming_Languages/Rust), we need to make them mutable to update.
```rs
    let mut v = Vec::new();
    v.push(5);
    v.push(6);
    v.push(7);
OR 
    let mut v:Vec<i32> = vec![1,2];     //if mut is removed it gives Compilation error
    v = [3,4,5].to_vec();

    for a in v.iter() {
        print!("{} ", a);           //3 4 5
    }
```

### Access, Iterate
<a name=itr></a>
#### [into_iter()](/Languages/Programming_Languages/Rust/Iterators)
- This function consumes the vector and produce an iterator that takes [ownership](../../) of each element in the vector. Taking Ownership means original vector is consumed and can no longer be used.
- That means elements are moved, rather of being copied.
- `into_iter()` returns an iterator that produces each element of the vector in turn.
```rs
let vec = vec![1, 2, 3];
for i in vec.into_iter() {
    // i takes ownership of each element in vec
    println!("{}", i);
}
// vec is consumed and can no longer be used here
```
<a name=intoe></a>
##### into_iter().enumerate()
- enumerate() method is used on iterators to produce an iterator that yields tuples containing the index and the value of each element.
```rs
let v = vec![3,2,4];
for (idx, num) in v.into_iter().enumerate() {
  println("index={}, value={}", idx, num);
}
index=0, value=3
index=1, value=2
index=2, value=4
```

<a name=fls></a>
#### Using for loop syntax
```rs
for i in &vec {
  prinln!("{}", i);
}
```

<a name=enumvec></a>
### Storing enum in vector
- As mentioned above, vector is primarily used to store element of same type but we can store elements of different types in vector by storing enums.
- if we want to store elements of different types in vector, store [enum](/Languages/Programming_Languages/Rust) in vector.
```rust
use std::{string::String, u32};
#[derive(Debug)]
enum Address{
    NoIP,
    IPv4(u8,u8,u8,u8),
    IPv6(String),
}
fn main() {
    let mut v:Vec<Address> = Vec::new();
    v.push(Address::NoIP);
    v.push(Address::IPv4(1,2,3,4));
    
    println!("{:#?}",v[1]);
}    

$ rustc test.rs
$ ./test.exe
IPv4(
    1,
    2,
    3,
    4,
)
```
