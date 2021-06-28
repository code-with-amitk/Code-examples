- [Hashmap](#what)
- [2. Operations](#opr)
  - [2.1 Create](#create)
  - [2.2 Insert/Update](#insert)
    - [2.2.1 Insert new (key,value) to hashmap](#insertnew)
    - [2.2.2 Overwriting existing value](#overwrite)
    - [2.2.3 Inserting (key,value) only when entry does not exist](#orinsert)
  - [2.3 Search](#search)
  - [2.4 Print](#print)

<a name=what></a>
## Hashmap<Key, Value> 
- stores a mapping of keys of type K to values of type V and created on heap.
- Like vectors, hash maps are homogeneous
  - all of the keys must have the same type, and all of the values must have the same type.

<a name=opr></a>
## 2. Operations

<a name=create></a>
### 2.1 Create
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

<a name=insert></a>
### 2.2 Insert/Update
<a name=insertnew></a>
#### 2.2.1 Insert new (key,value) to hashmap
  - using HashMap::new()
```rust
use std::collections::HashMap;
fn main() {
    let mut color = HashMap::new();
    color.insert(String::from("Red"), 1);
    color.insert(String::from("Green"), 2);
    
    let var = String::from("yellow");
    
    color.insert(var, 3);            //var is moved into hashmap and now hashmap becomes the owner
}   
```
<a name=overwrite></a>
#### 2.2.2 Overwriting existing value
  - if key already exists in map and we insert (key,value) with existing key and new value, then it old value would be updated.
```rust
use std::collections::HashMap;
fn main() {
    let mut color = HashMap::new();
    color.insert(String::from("Green"), 2);
    color.insert(String::from("yellow"), 3);

    color.insert(String::from("yellow"), 4);    //Updating existing (key,value)
    for (a,b) in &color {
        println!("{},{}",a,b);
    }
}   
```
<a name=orinsert></a>
#### 2.2.3 Inserting (key,value) only when entry does not exist
  - Function entry() only inserts into hashmap only when entry is not present in hashtable, if entry is present function does nothing.
```rust
use std::collections::HashMap;
fn main() {
    let mut color = HashMap::new();
    color.insert(String::from("Red"), 1);
    //color.insert(String::from("Green"), 2);
    color.entry(String::from("Green")).or_insert(50);


    for (a,b) in &color {
        println!("{},{}",a,b);
    }
}  
$ test.exe
Red,1
Green,50
```

<a name=search></a>
### 2.3 Search
- Using `pub fn get<Q>(&self, k: &Q) -> Option<&V>`
```rust
use std::string;
use std::collections::HashMap;
fn main() {
    let mut color = HashMap::new();
    color.insert(String::from("Red"), 1);
    color.insert(String::from("Green"), 2);
    color.insert(String::from("yellow"), 3);    
    
    //Hashmap Red:1, Green:2, yellow:3
    
    println!("{:?}",color.get(&String::from("yellow")));    //takes reference bcoz function expects ref
} 
  
$ test.exe
Some(3)                 //if value is not present, return None
```

<a name=print></a>
### 2.4 Print
```rust
use std::string;
use std::collections::HashMap;
fn main() {
    let mut color = HashMap::new();
    color.insert(String::from("Red"), 1);
    color.insert(String::from("Green"), 2);
    color.insert(String::from("yellow"), 3);

    for (a,b) in &color {
        println!("{},{}",a,b);
    }
} 
$ test.ext
Red,1
Green,2
yellow,3
```
