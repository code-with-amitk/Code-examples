- [Hashmap](#what)
- Operations
  - [Create](#create)
  - Insert
    - [1. New <key,value>](#insertnew)
    - [2. Overwrite](#overwrite)
    - [3. Insert only when entry does not exist](#orinsert)
  - Search / Find
    - [1. get(key)](#get)
    - [2. get_mut(key)](#getm)
  - [Print](#print)
  - [Remove / Delete / Erase](#remove)
- [HashMap,vector inside Struct](#struct)

<a name=what></a>
## Hashmap<Key, Value> //https://doc.rust-lang.org/std/collections/struct.HashMap.html
- stores a mapping of keys of type K to values of type V and created on heap.
- Like vectors, hash maps are homogeneous
  - all of the keys must have the same type, and all of the values must have the same type.

## Operations

<a name=create></a>
### Create
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

### Insert 
<a name=insertnew></a>
#### 1. New (key,value) to hashmap
```rs
use std::collections::HashMap;
fn main() {
    let mut var = HashMap::new();                 //Allocates HashMap on Heap
    var.insert(String::from("Red"), 1);           //Call insert() on HashMap
}   
```

<a name=overwrite></a>
#### 2. Overwriting existing value
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
#### 3. Insert (key,value) only when entry does not exist
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

### Search
<a name=get></a>
#### 1. pub fn get`<Q>`(&self, k: &Q) -> Option`<&V>`
```rs
{
  let mut var = HashMap::new();
  var.insert(String::from("Red"), 1);  var.insert(String::from("Green"), 2);   //Hashmap Red:1, Green:2
    
  println!("{:?}",var.get(&String::from("yellow")));    //takes reference bcoz function expects ref
} 
$ test.exe
Some(3)                 //if value is not present, return None

///////
let mut um = HashMap <i32, i32>::new();
if um.get(&3) == None {
  
}
```

<a name=getm></a>
#### 2. fn get_mut`<Q: ?Sized>`(&mut self, k: &Q) -> Option`<&mut V>`
- Returns a mutable reference to the value corresponding to the key
```rs
let mut map = HashMap::new();
map.insert(1, "a");
if let Some(x) = map.get_mut(&1) {
    *x = "b";
}
```

<a name=print></a>
### Print
```rs
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

<a name=remove></a>
### Remove


<a name=struct></a>
## HashMap inside Struct
- _1._ struct containing HashMap, vector variable.
- _2._ functions to operate on struct are defined inside impl.
  - _2a._ [Constructor in Rust](/Languages/Programming_Languages/Rust). Inside ctr memory for HashMap, vector allocated on heap.
  - _2b._ For inserting into struct{HashMap}, self is passed because we allocate object 1st then call functions on object.
- _3._ Object of class is created by calling ctr of class. This allocates HashMap inside struct Test on Heap.
- _4._ Using class object function is called.
```rs
struct Test               //On Heap
| HashMap allocated ... | 


using std::{collections::HashMap, hash::Hash};
struct Test {                                     //1
    v: Vec<i32>,
    um : HashMap <String, i32>,
}

impl Test {                                       //2
    fn ctr() -> Self {                            //2a
        v: vec![],
        um: HashMap::new()
    }
    
    fn insert (&mut self, key:String, val:i32) -> bool {      //2b
        match self.um.get (&key) {
            Some(_) => false,                       //if key is present donot insert
            None => {
              self.um.insert (key, val);
              self.v.push(val);
              true
            }
        }
    }

fn main() {
  let mut obj = Test::ctr();                    //3
  obj.insert (String::from("Red"), 1);          //4
}
```
