- [1. What/Why Rust](#What)
  - [1.1 Rust vs All Languages](#All)
  - [1.2 Rust vs C++](#Rustcpp)
- [2. Ownership & Borrowing](#owbo)
  - [2.1 Ownership](#own)
  - [2.2 Reference = Borrowing](#bow)
    - [2.2.a Dangling Reference](#danglingref)
    - [2.2.b Mutable Reference](#mutref)
      - [Mutable & immutable References in same scope not allowed](#MutImmutable)
      - [2 Mutable references are not allowed in same scope](#MutMut)
      - [Mutable References are allowed in seperate scope](#MutSep)
- [3. Data Types](Data_Types)
  - Associated Functions
- [4. Enum](#enum)
  - [4.1. Enum Not Holding data](#enumnotholding)
  - [4.2  Enum holding data](#enumholding)
    - [4.2.1 Enum holding 1 datatype](#enumholdingone)
    - [4.2.2 Enum Holding Multiple Datatypes](#enumholdingmultiple)



<a name="What"></a>
## 1. What/Why Rust
<a name="All"></a>
### 1.1 Rust vs All Languages
- No Garbage collector               //Garbage collector is runtime heavy
- No monolithic runtime.
- Statically typed(with type inference), Catching the bugs at compile time reduces runtime crashes. Compiler does lot of heavy lifting.
  - No Type confusion
    - Pointer to int cannot be assigned to pointer to float
  - improves code quality, security, no runtime errors
- Thread safety
  - No data races: No 2 threads doing same thing to shared resource Wow!!
- Memory and ownership checking     //Borrow checker
- No need to call delete(),free(). Compiler will insert free()/delete() knows when memory is not used.

<a name="Rustcpp"></a>
### 1.2 Rust vs C++
- No implicit copies as in C++
- No invisible copy constructors, move operators etc (as in c++). Whatever is runtime cost that's visible in code.
- Safe parallelism wrt C++
- Pacakge Repository (crates) better
- Compiler Errors are more informative
- Memory safety                    
  - No segfaults(no segfault reported in last 5 years)
  - No Memory leaks
  - No out of bounds read/writes
  - No double frees
  - No dangling pointers
  - No uninitialized variables
- Default in rust is move not copy
```rust
fn print(a:Vec<i32>) {
  println!("{}"a.len());
}
fn main() {
  let mut v = Vec::new();
  v.push(1);
  print(v);                               //Now v is moved not copied.
  //println!("{}", v[0]);                 //Compiler error
}
```

<a name="owbo"></a>
## 2. Ownership & Borrowing

<a name="owo"></a>
### 2.1 Ownership
- **What?** Means code/variable owns a memory and is allowed to free it.
- How Rust Handles it? Rust keeps track of things, who owns what and you cannot free a memory which you donot own.
  
<a name="bow"></a> 
### 2.2 Borrowing = Reference (&var)
- **What?** Means passing the reference of a variable. Borrowing means that needed to be returned(we cannot change).
```rust
fn print( a : &Vec<i32>) {
  println!("{}"a.len());            //1
  //a.push(2);                      //Compilation error. We cannot change borrowed. Changing immutable
}
fn main() {
  let mut v = Vec::new();
  v.push(1);
  print(&v);                         //Borrowed not moved
  println!("{}", v[0]);              //1
}
```

<a name="danglingref"></a>
#### 2.2.a Dangling Reference
- **Dangling pointer?** Pointer points to memory, memory is freed and pointer is used.
- **Dangling reference?** Similar to Dangling pointer, when reference to a value is used, value is freed and reference is used after that.
- **C++:**
  - Problem: Since b is local variable and is freed as fun() goes out of scope.
```c++
int& fun() {    //Function returning reference
  int b = 10;
  return b;
}

int main() {
  int &a = fun();       //a is reference variable pointing to b, which does not exist
  cout << a;            
}
# g++ test.cpp        //No compile error
# ./a.out
  Segmentation Fault
```
- **Rust:** Complier does not allow DR.
```rust
fn fun() -> &i32 {
  let b = 10;
  &b                        //Reference is returned
}
fn main() {
  let a = fun();
}
# rustc test.rs
Compilation error

Solution: Return by value = Transfer ownership
fn fun() -> i32 {
  let b = 10;
  b                        
}
```

<a name="mutref"></a>
#### 2.2.b Mutable Reference
- We know a borrowed item cannot be changed, but mutable reference can be changed.
  - *1.* Declare mutable variable
  - *2.* Create mutable Reference using `&mut`
  - *3.* Accept mutable reference using `some_string: &mut String`
```rust
fn print( a : &mut Vec<i32>) {        //3
  a.push(2);
}
fn main() {
  let mut v = Vec::new();             //1
  v.push (1);
  print (&mut v);                     //2
  println! ("{}", v[0]);
}
# rustc test.rs
# test.exe
```

<a name="MutImmutable"></a>
#### Mutable & immutable References in same scope not allowed
```rust
    let mut v = vec![1, 2, 3, 4, 5];
    let first = &v[0];
    v.push(6);                                    //Compilation Error
    println!("first:{}", first);
```
*Compilation Error Why?*
  - The code might look like should work. 
  - This error is due to the way vectors work. adding a new element onto the end of the vector might require allocating new memory and copying the old elements to the new space. 
  - if there isn’t enough room to put all the elements next to each other where the vector currently is. In that case, the reference to the first element would be pointing to deallocated memory. 
  - The borrowing rules prevent programs from ending up in that situation.

<a name="MutMut"></a>
#### 2 Mutable references are not allowed in same scope
- *Why?* To avoid data race conditions. Race condition occurs when any of 3 behaviours happen:
    - Two or more pointers access the same data at the same time.
    - At least one of the pointers is being used to write to the data.
    - There’s no mechanism being used to synchronize access to the data.
```rust
  let mut s = String::from("hello");
  let r1 = &mut s;
  let r2 = &mut s;                            //Compilation Error
  println!("{}, {}", r1, r2);
```
<a name="MutSep"></a>
#### Mutable References are allowed in seperate scope
```rustc
  let mut s = String::from("hello");
  {
    let r1 = &mut s;
  } // r1 goes out of scope here, so we can make a new reference with no problems.
  let r2 = &mut s;
```

<a name=enum></a>
## 4. Enum
- Similar to other languages, Enums are User defined data type which can be assigned some limited values. 
- In rust enum variable can or cannot hold the data (Eg: String). 

<a name=enumnotholding></a>
### 4.1. Enum not Holding data / Same as enum class in C++
```rust
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
### 4.2. Enum Holding the data

<a name=enumholdingone></a>
#### 4.2.1 Enum holding 1 datatype
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
#### 4.2.2 Enum Holding Multiple Datatypes
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
