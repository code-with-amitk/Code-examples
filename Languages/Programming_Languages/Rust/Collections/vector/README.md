- [Create, Initialize](#cin)
  - [2d vector](#2d)
- [Initialize](#init)
- [Update](#update)
- Access
  - [using iterator](#itr)
  - [using index](#ind)
- [length of vector](#len)
- _last element_
  - [1. last() -> Option<&T>](#plast)
  - [2. Pop](#pop)
  - [3. Append push](#push)
- Print
  - [Any Element](#any)
- [Store enum in vector](enumvec)


## [Struct std::vec::Vec](https://doc.rust-lang.org/std/vec/struct.Vec.html#method.push)
- Same as in C++, Storing more than 1 value of same type contigously in memory. Remember All collections are allocated on HEAP.
- Stack is implemented using vector in rust

<a name=cin></a>
### Create, Initialize
#### Allocate Empty vector
```rs
//Both are same//
let mut v:Vec<i32> = Vec::new();
println!("size={:?}", v.len());     //0

let mut v:Vec<i32> = vec![];
println!("size={:?}", v.len());     //0
```
#### Declare
```rs
  let v : Vec<i32>;              
```
#### Initialize
```rs
  let v1: Vec<i32> = [1,2,3].to_vec();  //Initialize
  let v2: Vec<i32> = vec![14,25,35];
  let v3: Vec<String> = vec!["test".to_string(), "test1".to_string()];
  
                  //init_value,size
  let mut v = vec![0; 5];             //Creating vector of size=5 with init value=0  
```

<a name=2d></a>
#### 2d vector
```rs
  let mut v: Vec<Vec<i32>> = Vec::with_capacity(row*col);
  v.push(vec!(0,1));  
  v.push(vec!(1,2));
OR         
  let mut v : Vec<Vec<usize>> = vec![Vec::with_capacity(row); col];
  v[a as usize].push(b as usize);
OR  
  let mut v = vec![vec![0; row]; col];  
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

### Access
<a name=itr></a>
### [Using iterator](/Languages/Programming_Languages/Rust/Iterators)

<a name=ind></a>
#### Using index
```rs
fn main() {
    let mut v : Vec<i32> = vec![1,2,3];
    let mut i : i32 = 0;
    //println("{}", v[i]);        //Complier Error: type `[{integer}]` cannot be indexed by `i32`
    println("{}", v[i as usize]); //Fix: Typecast i to usize.
```
_Complier Error: type `[{integer}]` cannot be indexed by `i32`?_ Means Arrays need to be indexed by a [usize type](/Languages/Programming_Languages/Rust/Data_Types). 
- Solutions:
  - _1._ Typecast          //Not recommended
  - _2._ Keep indexing variable seperate from normal variables.

<a name=len></a>
#### Length
```rs
let v = vec![1,2,3];
v.len();        //3
```

### Last Element
<a name=plast></a>
#### 1. const fn last(&self) -> Option`<&T>`
- Returns the last element of the slice, or None if it is empty.
```rs
if v.last() != None {
  println!("{}", v.last());
}
```

<a name=pop></a>
#### 2. Remove last element
- Removes the last element from a vector and returns it, or None if it is empty.
```rs
pub fn pop(&mut self) -> Option<T>
v.pop()
```

<a name=push></a>
#### 3. Push at end
- Appends an element to the back of a collection
```rs
vec.push(3);
```

### Print
<a name=any></a>
#### 1. Any element
```rs
let mut a = v[v.len()-1];
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
