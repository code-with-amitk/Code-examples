**Enum**
- [1. Enum Not Holding data](#enumnotholding)
- [2.  Enum holding data](#enumholding)
    - [2.1 Enum holding 1 datatype](#enumholdingone)
    - [2.2 Enum Holding Multiple Datatypes](#enumholdingmultiple)
  - [3 Option Enum = NULL](#optionenum) 
    - [3.1 Why creating NULL was mistake?](#nullmistake)
    - [3.2 Option Enum](#oe)

## Enum
- Similar to other languages, Enums are User defined data type which can be assigned some limited values. 
- In rust enum variable can or cannot hold the data (Eg: String). 

<a name=enumnotholding></a>
### 1. Enum not Holding data / Same as enum class in C++
```rs
#[derive(Debug)]            //1. To print debugging information, we need to explicitly add annotation `#[derive(Debug)]` for enum.
enum Color{                 //2. Declare enum same
    Red,
    Blue,
    Green
}

fn fun (a:Color) {          //4. Print enum after passing to function
    println!("{:#?}",a);
}

fn main() {
    let a:Color = Color::Red; //3. Initialize variable with enum value
    fun(a);
}
```

<a name=enumholding></a>
### 2. Enum Holding the data

<a name=enumholdingone></a>
#### 2.1 Enum holding 1 datatype
```rust
use std::{string::String, u32};

#[derive(Debug)]
enum Address{                     //1. Enum variable can store string data
    IPv4(String),
    IPv6(String),
}

fn fun (addr:&Address) {          //3. Passing enum variable to function and printing.
    println!("{:#?}",addr);
}

fn main() {
    let router1:Address = 
      Address::IPv4(String::from("192.168.1.1"));   //2. Creating enum variable having string data(192.0.0.1)
    fun(&router1);
}

# rustc test.rs
# .test.exe
IPv4(
    "192.168.1.1",
)
```

<a name=enumholdingmultiple></a>
#### 2.2 Enum Holding Multiple Datatypes
```rust
use std::{string::String, u32};

#[derive(Debug)]                
enum Address{                   //1. Enum data structure holding 3 variables
    NoIP,                       //NoIP does not hold any data
    IPv4(u8,u8,u8,u8),          //IPv4 holding 4 u8 types
    IPv6(String),               //IPv6 holding String type
}

/*THIS IS EQUIVALENT TO:
struct NoIP;
struct IPv4 {
    a: i32,
    b: i32,
    c: i32,
    d: i32,
}
struct IPv6 {
    e:String
}    
*/

fn fun (addr1:&Address,addr2:Address, addr3:Address) {         //3. Printing enum variables
    println!("IPv4 {:#?}",addr1);
    println!("IPv6 {:#?}",addr2);
    println!("Disconnected {:#?}",addr3);
}

fn main() {
    let router1:Address = 
      Address::IPv4(10,11,12,13);               //2. Router1 variable created of type IPv4, router2 of IPv6, disconnectedIP of no ip
    let router2:Address = Address::IPv6(String::from("::1"));
    let disconnectedDevice:Address = Address::NoIP;
    fun(&router1,router2);
}

# rustc test.rs
# .\test.exe
IPv4 IPv4(
    10,
    11,
    12,
    13,
)
IPv6 IPv6(
    "::1",
)
Disconnected NoIP
```

<a name=optionenum></a>
## 3. Option Enum = NULL

<a name=nullmistake></a>
### 3.1 Why creating NULL was mistake?
- Tony Hoare(inventor of NULL) said invention of NULL is his Billion dollar mistake. Why?
  - If we try using NULL value as non-NULL value. Eg: derefercing NULL ptr.
  - Problem is not in NULL but at places this get misused.
  - There are multiple situations, where crash is caused due to NULL. 
- Ex-1. NULL References when derefrenced will cause crash
- **C/C++ crashing code**
```c++
int fun(struct A*& p){              //Funtion taking NULL reference
  if (p == nullptr)
    cout<<"Got Null ptr reference\n";
  cout << p->a;
}
int main(){
  struct A* p = nullptr;
  fun(p);
}
$ ./a.out
Got Null ptr reference
Segmentation Fault
```
- **How Rust avoid Null ptr?**
  - _1._ Whichever variable can have NULL or other value, Rust asks to declare it as `Option<T>`
  - _2._ Rust does not allow creating structure object without initializing its members.
    - It can be initialized with Some or None. This is how rust avoids NULL crashes.
```rust
fn fun(obj:&A){
    println!("a:{:#?}",obj.a);
}
struct A{
    a:Option<i32>,              //1
}
fn main() {
    let obj = A{
        a:None                  //2
    };
    fun(&obj);
}
```

<a name=oe></a>
### 3.2 Option Enum
- This is another kind of enum in rust which takes either of 2 values: Some or None
```rust
enum Option<T> {          //T is template which can take any type: i32, i64 etc
    Some(T),
    None,
}
```
- **Example**
- *1. Initializing and using Option<`T`>*
```
fn main() {
    let a:Option<i32>= Some(2);
    let b:Option<i32>= None;

    println!("a:{:#?}",a);
    println!("b:{:#?}",b);
}    
$ main.exe
a:Some(
    2,
)     
b:None
```
- *2. We cannot add Option<`T`> to non Option<`T`>*
```rust
fn main() {
    let x: i8 = 5;
    let y: Option<i8> = Some(5);

    let sum = x + y;                //Compliation Error
}    
```
