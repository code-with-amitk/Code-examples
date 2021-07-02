- [1. What](#what)
- [2. Operations](#opr)
  - [2.1 Creating](#create)
  - [2.2 Initialize](#init)
  - [2.3 Update](#update)
  - [2.4 Accessing the vector](#access)
- [3. Storing enum in vector](enumvec)


<a name=what></a>
## 1. Vector
- Same as in C++, Storing more than 1 value of same type contigously in memory.

<a name=opr></a>
## 2. Operations

<a name=create></a>
### 2.1 Creating a Vector
```rust
  let v:Vec<i32>;               //vector to hold values of type i32
OR  
  let mut v1 = Vec::new();      //Allocating vector on heap
OR
  let v = vec![1,2,3,4];
```

<a name=init></a>
### 2.2 Initializing a vector
```rust
    let v:Vec<i32> = [1,2,3].to_vec();
OR
    let v2:Vec<i32> = vec![14,25,35];

    for a in v2.iter() {
        println!("{} ", a);         //14 25 35
    }
```

<a name=update></a>
### 2.3 Updating a vector
- Since variables in rust is [immutable by default](/Languages/Programming_Languages/Rust), we need to make them mutable to update.
```rust
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
### 2.4 Accessing a vector
```rust
fn main() {
    let mut v:Vec<i32> = vec![1,2,3];

    for a in v.iter() {
        print!("{} ", a);             //1 2 3
    }
    
    print!("{} ", v[0]);              //1
    //print!("{} ", v[10]);           //Seg Fault on runtime. Since Collections are stored on heap

    print!("{:#?}",v.get(1));         //Some(4,)

    print!("{:#?}",v.get(10));        //None. Does not crash
```

<a name=enumvec></a>
## 3. Storing enum in vector
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
