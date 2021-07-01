- [1. What/Why Rust](#What)
  - [1.1 Rust vs All Languages](#All)
  - [1.2 Rust vs C++](#Rustcpp)
- [2. Ownership](#own)
- [3.Reference = Borrowing](#bow)
  - [3.1 Dangling Reference](#danglingref)
  - [3.2 Mutable Reference](#mutref)
    - [Mutable & immutable References in same scope not allowed](#MutImmutable)
    - [2 Mutable references are not allowed in same scope](#MutMut)
    - [Mutable References are allowed in seperate scope](#MutSep)
- [4. Data Types](#datatypes)
- [5. Control Flow](#controlflow)
- [6. Enum](#enum)
  - [6.1. Enum Not Holding data](#enumnotholding)
  - [6.2  Enum holding data](#enumholding)
    - [6.2.1 Enum holding 1 datatype](#enumholdingone)
    - [6.2.2 Enum Holding Multiple Datatypes](#enumholdingmultiple)
  - [6.3 Option Enum = NULL](#optionenum) 
    - [6.3.1 Why creating NULL was mistake?](#nullmistake)
    - [6.3.2 Option Enum](#oe)
- [7. Error Handling](#eh)

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

<a name="own"></a>
## 2. Ownership
- Means code/variable owns a memory and is allowed to free it.
- **Memory management approaches**
  - _1._ Some languages have garbage collection(java,python,ruby) that constantly looks for no longer used memory as the program runs 
  - _2._ C,C++ the programmer must explicitly allocate and free the memory.
  - _3._ Rust memory is managed through ownership with a set of rules that the compiler checks at compile time.
    - Ownership applies to memory allocated on heap(dynamically), Eg: String(), vector ie those are moved. For variable allocated on Stack (Eg: int, float) variable is copied.
```rust
fn main() {
  let s = String::from("hello");    //Allocated on HEAP
  fun(s);                           //s's value is MOVED into function and no longer valid here
  println!("s: {}", s);             //Complie time error
                                    
  let x = 5;                        //Allocated on STACK
  fun1(x);                          
  println!("x: {}", x);            //Ok, x=5

}
fn fun(some_string: String) { 
    println!("{}", some_string);
} //Here, some_string goes out of scope and `drop()` is called. The backing memory is freed.
```
- **Transferring Ownership In Return Value:** Returning values can also transfer ownership
```rust
fn main() {
  let s1 = fun1();                     //fun() moves its return value into s1
  let s2 = String::from("hello");
  let s3 = fun2(s2);                  //s2 is moved into fun2() which also moves its return value into s3
}

fn fun1() -> String {            //fun() will move its return value into the function that calls it
  let some_string = String::from("hello");
  some_string                   //some_string is returned ie moved
}

fn fun2(a_string: String) -> String {     
    a_string                  // a_string is returned and moves out to the calling function
}
```


<a name="bow"></a> 
## 3. Borrowing = Reference (&var)
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
### 3.1 Dangling Reference
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
### 3.2 Mutable Reference
- We know a borrowed item cannot be changed, but mutable reference can be changed.
```rust
fn print( a : &mut Vec<i32>) {        //3. Accept mutable reference using `some_string: &mut String`
  a.push(2);
}
fn main() {
  let mut v = Vec::new();             //1. Declare mutable variable
  v.push (1);
  print (&mut v);                     //2.Create mutable Reference using `&mut`
  println! ("{}", v[0]);
}
# rustc test.rs
# test.exe
```

<a name="MutImmutable"></a>
### Mutable & immutable References in same scope not allowed
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
### 2 Mutable references are not allowed in same scope
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
### Mutable References are allowed in seperate scope
```rustc
  let mut s = String::from("hello");
  {
    let r1 = &mut s;
  } // r1 goes out of scope here, so we can make a new reference with no problems.
  let r2 = &mut s;
```

<a name=datatypes></a>
## [4. Data Types](Data_Type)
  - Associated Functions

<a name=controlflow></a>
## [5. Control Flow](Control_Flow)
  - for, loop, while, match=switch, if

<a name=enum></a>
## 6. Enum
- Similar to other languages, Enums are User defined data type which can be assigned some limited values. 
- In rust enum variable can or cannot hold the data (Eg: String). 

<a name=enumnotholding></a>
### 6.1. Enum not Holding data / Same as enum class in C++
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
### 6.2. Enum Holding the data

<a name=enumholdingone></a>
#### 6.2.1 Enum holding 1 datatype
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
#### 6.2.2 Enum Holding Multiple Datatypes
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
## 6.3 Option Enum = NULL

<a name=nullmistake></a>
### 6.3.1 Why creating NULL was mistake?
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
### 6.3.2 Option Enum
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

<a name=eh></a>
## 7. [Error Handling](Error_Handling)
