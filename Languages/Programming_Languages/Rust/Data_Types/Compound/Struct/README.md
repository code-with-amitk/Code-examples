**struct**
- [Define, Initialize struct](#d)
- [Mutable struct](#m)
- [Dump struct variables using println](#dump)
- [Associated Function](#a)



<a name=d></a>
### Define, Initiailize
```rs
struct Employee {
  name: String,     //name:type
  email: String,
  salary: f64,
  empID: u32,
}

let amit = Employee {
  name: String::from("Amit"),
  email: String::from("amit@test.com"),
  salary: 12.00
  empID: 52
}
```

<a name=m></a>
## Mutable struct
immutable(which cannot be changed). Mutable struct means whose values can be changed. Entire struct has to be mutable, Rust does not allow only some feilds to be mutable.
```rs
let mut champ = Employee {
  name: String::from("Champ")
  email: String::from("champ@gmail.com")
  salary: 50.00
  empID: 56
};
champ.name = String::from("Big Champ");     //Changing name of struct
```

<a name=dump></a>
### Dumping struct variables using println
A. To print debugging information, we need to explicitly add annotation `#[derive(Debug)]` for particular struct.
```rs
#[derive(Debug)]            //A
struct dimen {
    len:u32,
    width:u32
}

fn main() {
    let a = dimen {
        len:10,
        width:20
    };
    println!("{:?}",a);      //1
    
    println!("{:#?}",a);      //2. # is Trait.
}

# main.exe
dimen { len: 10, width: 20 }    //1

dimen {                         //2
    len: 10,
    width: 20,
}
```

<a name=a></a>
### Associated Function
Defined inside impl block. As name depicts, they are associated with datatype. All datatype associated functionality is done inside these functions.
```rs
use std::{string::String, u32};
#[derive(Debug)]

struct Rectangle{
    length: u32,
    width: u32,   
}
impl Rectangle {
    fn area(&self) -> u32 {                     //Function returning u32
        self.width * self.length
    }
    fn returnObject(len:u32,wid:u32) -> Rectangle {   //Returning Object itself
        Rectangle {
            length : len,
            width : wid,
        }
    }
}

fn main() {
    let a = Rectangle {
        length:10,
        width:20,
    };
    println!("{:#?}",a.area());
    println!("{:#?}",Rectangle::returnObject(10,20));
}    
```
