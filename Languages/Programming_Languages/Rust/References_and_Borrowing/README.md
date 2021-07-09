- [1. Reference = Borrowing](#bow)
- [2. Dangling Reference](#danglingref)
- [3. Mutable Reference](#mutref)
  - [3.1 Mutable & immutable References in same scope not allowed](#MutImmutable)
  - [3.2 Two Mutable references are not allowed in same scope](#MutMut)
  - [3.3 Mutable References are allowed in seperate scope](#MutSep)


<a name="bow"></a> 
## 1. Borrowing = Reference (&var)
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
## 2. Dangling Reference
- **Dangling pointer?** Pointer points to memory, memory is freed and pointer is used.
- **Dangling reference?** Similar to Dangling pointer, when reference to a value is used, value is freed and reference is used after that.
- **C++ Problem:** Since b is local variable and is freed as fun() goes out of scope.
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
## 3. Mutable Reference
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
### 3.1 Mutable & immutable References in same scope not allowed
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
### 3.2 Two Mutable references are not allowed in same scope
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
### 3.3 Mutable References are allowed in seperate scope
```rustc
  let mut s = String::from("hello");
  {
    let r1 = &mut s;
  } // r1 goes out of scope here, so we can make a new reference with no problems.
  let r2 = &mut s;
```
