- Operations
  - [1. Create](#create)
  - [2. Initialize](#init)
  - [3. Create & Initialize](#ci)
  - [4. Update](#update)
  - [5. Accessing the vector](#access)
  - [6. length of vector](#len)
  - _7. last element_
    - [7a. Print](#plast)
    - [7b. Pop](#pop)
    - [7c. Append push](#push)
- [Store enum in vector](enumvec)


## [Struct std::vec::Vec](https://doc.rust-lang.org/std/vec/struct.Vec.html#method.push)
- Same as in C++, Storing more than 1 value of same type contigously in memory.

<a name=create></a>
#### 1. Create
```rs
  let v:Vec<i32>;               //vector to hold values of type i32
OR  
  let mut v1 = Vec::new();      //Allocating vector on heap
OR
  let v = vec![1,2,3,4];
```

<a name=init></a>
#### 2. Initiale
```rs
    let v:Vec<i32> = [1,2,3].to_vec();
OR
    let v2:Vec<i32> = vec![14,25,35];
    for a in v2.iter() {
        println!("{} ", a);         //14 25 35
    }    
```

<a name=ci></a>
#### 3. Create & Initialize
```rs
                  //init_value,size
  let mut v = vec![0; 5];             //Creating vector of size=5 with init value=0
```

<a name=update></a>
#### 4. Update
- Since variables in rust is [immutable by default](/Languages/Programming_Languages/Rust), we need to make them mutable to update.
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

<a name=access></a>
#### 5. Accessing a vector
- **A. Sequential access**
```rs
fn main() {
    let mut v:Vec<i32> = vec![1,2,3];
    for a in v.iter() {
        print!("{} ", a);             //1 2 3
    }
    print!("{} ", v[0]);              //1
    print!("{:#?}",v.get(1));         //Some(4,)
    print!("{:#?}",v.get(10));        //None. Does not crash
```
- **B. Accessing vector using i32**
  - _Complier Error: type `[{integer}]` cannot be indexed by `i32`?_
    - Means Arrays need to be indexed by a [usize type](/Languages/Programming_Languages/Rust/Data_Types). 
    - _Solutions:_ 
      - _1._ Typecast          //Not recommended
      - _2._ Keep indexing variable seperate from normal variables.
```rust
fn main() {
    let mut v:Vec<i32> = vec![1,2,3];
    let mut i:i32 = 0;
    //println("{}", v[i]);        //Complier Error: type `[{integer}]` cannot be indexed by `i32`
    println("{}", v[i as usize]); //Fix: Typecast i to usize.
```

<a name=len></a>
#### 6. Length
```rs
let v = vec![1,2,3];
v.len();        //3
```

<a name=plast></a>
#### 7a. Print Last element of vector
- Returns the last element of the slice, or None if it is empty.
```rs
pub const fn last(&self) -> Option<&T>
if v.last() > Some(&0) {
  println!("{}", v.last());
}
```

<a name=pop></a>
#### 7b. Remove last element
- Removes the last element from a vector and returns it, or None if it is empty.
```rs
pub fn pop(&mut self) -> Option<T>
v.pop()
```

<a name=push></a>
#### 7c. Push at end
- Appends an element to the back of a collection
```rs
vec.push(3);
```

<a name=enumvec></a>
## Storing enum in vector
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
