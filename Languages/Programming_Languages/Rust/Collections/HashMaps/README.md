- [Hashmap](#what)
- [2. Operations](#opr)
  - [2.1 Create](#create)
  - [2.2 Insert new (key,value) to hashmap](#insertnew)
  - [2.3 Overwrite existing value](#overwrite)
  - [2.4 Insert (key,value) only when entry does not exist](#orinsert)
  - [2.5 Search](#search)
  - [2.6 Print](#print)
- [HashMap inside Struct](#struct)

<a name=what></a>
## Hashmap<Key, Value> 
- stores a mapping of keys of type K to values of type V and created on heap.
- Like vectors, hash maps are homogeneous
  - all of the keys must have the same type, and all of the values must have the same type.

<a name=opr></a>
## 2. Operations

<a name=create></a>
#### 2.1 Create
- _1._ using iterators and collect() method
  - `HashMap<_, _>` is needed type annotation.
```rust
use std::collections::HashMap;
fn main() {
    let color = vec![String::from("Red"), String::from("Blue")];
    let value = vec![1,2];
    let mut hm:HashMap<_, _>  = 
    color.into_iter().zip(value.into_iter()).collect();
} 
```

<a name=insertnew></a>
#### 2.2 Insert new (key,value) to hashmap
```rs
use std::collections::HashMap;
fn main() {
    let mut var = HashMap::new();                 //Allocates HashMap on Heap
    var.insert(String::from("Red"), 1);           //Call insert() on HashMap
}   
```
<a name=overwrite></a>
#### 2.3 Overwriting existing value
  - if key already exists in map and we insert (key,value) with existing key and new value, then it old value would be updated.
```rust
use std::collections::HashMap;
fn main() {
    let mut var = HashMap::new();
    var.insert(String::from("Red"), 1);

    var.insert(String::from("White"), 1);    //Updating existing (key,value)
    for (a,b) in &var {
        println!("{},{}",a,b);
    }
}   
```
<a name=orinsert></a>
#### 2.4 Insert (key,value) only when entry does not exist
  - Function entry() only inserts into hashmap only when entry is not present in hashtable, if entry is present function does nothing.
  - or_insert() method returns a [mutable reference](/Languages/Programming_Languages/Rust) to the value of key if that key exists, and if not, inserts (key,value) & returns a mutable reference to the new value. 
```rust
use std::collections::HashMap;
fn main() {
    let mut var = HashMap::new();
    var.insert(String::from("Red"), 1);
    //var.insert(String::from("Green"), 2);
    var.entry(String::from("Green")).or_insert(50);


    for (a,b) in &var {
        println!("{},{}",a,b);
    }
}  
$ test.exe
Red,1
Green,50
```

<a name=search></a>
#### 2.5 Search
- Using `pub fn get<Q>(&self, k: &Q) -> Option<&V>`
```rust
use std::string;
use std::collections::HashMap;
fn main() {
    let mut var = HashMap::new();
    var.insert(String::from("Red"), 1);
    var.insert(String::from("Green"), 2);   
    //Hashmap Red:1, Green:2
    
    println!("{:?}",var.get(&String::from("yellow")));    //takes reference bcoz function expects ref
} 
  
$ test.exe
Some(3)                 //if value is not present, return None
```

<a name=print></a>
#### 2.6 Print
```rust
use std::string;
use std::collections::HashMap;
fn main() {
    let mut var = HashMap::new();
    var.insert(String::from("Red"), 1);
    var.insert(String::from("Green"), 2);

    for (a,b) in &var {
        println!("{},{}",a,b);
    }
} 
$ test.ext
Red,1
Green,2
```

<a name=struct></a>
## HashMap inside Struct
- _1._ struct containing HashMap variable
- _2._ functions to operate on struct are defined inside impl.
  - _2a._ [Constructor in Rust](/Languages/Programming_Languages/Rust). Inside ctr memory for HashMap is allocated.
  - _2b._ For inserting into struct{HashMap}, self is passed ie insert into obj which calls the function.
- _3._ Object of class is created by calling ctr of class. This allocates HashMap inside struct Test on Heap.
- _4._ Using class object function is called.
```rs
struct Test               //On Heap
| HashMap allocated ... | 
```
- **Code**
```rs
using std::{collections::HashMap, hash::Hash};

struct Test {                                   //1
  a : HashMap <String, i32>,
}

impl Test {                                     //2
  fn ctr() -> Self {                            //2a
    h : HashMap::<String, i32>::new()
  }
  fn insert (&mut self, a:String, b:i32) {      //2b
    self.h.insert (a, b);
  }
}

fn main() {
  let mut obj = Test::ctr();                    //3
  obj.insert (String::from("Red"), 1);          //4
}
```
