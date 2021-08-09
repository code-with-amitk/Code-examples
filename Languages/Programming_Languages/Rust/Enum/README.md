**Enum**
- [Enum Not Holding data](#en)
- Enum holding data
  - [1. Enum holding 1 datatype](#e1)
  - [2. Enum Holding Multiple Datatypes](#em)
  - **3. Option Enum = NULL**
    - [Creating NULL was mistake](#null)
    - [Option Enum](#oe)
      - [1. Initializing and using Option`<T>`](#oeuse)
      - [2. Option`<T>` cannot be added to non Option`<T>`](#add)

## Enum
Enums are User defined data type(Similar to other languages) which can be assigned some limited values. In rust enum variable can/cannot hold the data (Eg: String). 

<a name=en></a>
### Enum not Holding data / Same as enum class in C++
```rs
#[derive(Debug)]            //To print debugging information
enum Color{                 //Declare enum
    Red,
    Blue,
    Green
}

fn fun (a:Color) {          //Print enum after passing to function
    println!("{:#?}",a);
}

fn main() {
    let a:Color = Color::Red; //Initialize variable with enum value
    fun(a);
}
```

### Enum Holding the data

<a name=e1></a>
#### 1. Enum holding 1 datatype
```rs
use std::{string::String, u32};

#[derive(Debug)]
enum Address{                     //1. Enum variable storing string data
    IPv4(String),
    IPv6(String),
}

fn fun (addr:&Address) {          //3. Passing enum variable to function and print
    println!("{:#?}",addr);
}

fn main() {
    let router1:Address = 
      Address::IPv4(String::from("192.168.1.1"));   //2. Creating enum variable having string data(192.168.1.1)
    fun(&router1);
}

# rustc test.rs
# ./test.exe
IPv4(
    "192.168.1.1",
)
```

<a name=em></a>
#### 2. Enum Holding Multiple Datatypes
```rs
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
      Address::IPv4(10,11,12,13);                         //2. Router1 variable type=IPv4
    let router2:Address = Address::IPv6(String::from("::1"));   //router2 of IPv6
    let disconnectedDevice:Address = Address::NoIP;             //disconnectedIP of no ip
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

## 3. Option Enum = NULL

<a name=null></a>
### Creating NULL was mistake?
Tony Hoare(inventor of NULL) said invention of NULL is his Billion dollar mistake. Why?
  - Using NULL value as non-NULL value. Eg: derefercing NULL ptr. It will crash. Problem is not in NULL but at places it gets misused.
  - There are multiple situations, where crash is caused due to NULL. Example: NULL References when derefrenced will cause crash
- **C/C++ crashing code**
```cpp
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
**How Rust avoid Null ptr?**
  - _1._ Variable that can have NULL/other value is declared as Option`<T>`
  - _2._ Rust does not allow creating structure object without initializing its members.
    - It can be initialized with Some or None. No crash, None will be printed.
```rs
fn fun (obj : &A) {
    println! ("a:{:#?}", obj.a);    //3
}
struct A{
    a : Option<i32>,              //1
}
fn main() {
    let obj = A{
        a:None                  //2
    };
    fun (&obj);
}
```

<a name=oe></a>
### Option Enum
This is another kind of enum in rust which takes either of 2 values: Some or None
```rs
enum Option <T> {        //T is template which can take any type: i32, i64 etc
    Some (T),
    None,
}
```
<a name=oeuse></a>
#### 1. Initializing and using Option`<T>`
```rs
fn main() {
    let a : Option<i32> = Some(2);
    let b : Option<i32> = None;

    println!("a:{:#?}",a);
    println!("b:{:#?}",b);
}    
$ ./main.exe
a : Some(
    2,
)     
b : None
```
<a name=add></a>
#### 2. Option`<T>` cannot be added to non-Option`<T>`
```rs
fn main() {
    let x: i8 = 5;
    let y: Option<i8> = Some(5);

    let sum = x + y;                //Compliation Error
}    
```
