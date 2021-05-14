## String Type
- [string literals](../../StackHeap_CompileRuntime) are allocated on stack.
```rust
  let s:string = "test";
```
- String is allocated on Heap, ie we can store whatever big string we want in String type.
```rust
  let mut s = String::from("hello");      //Creating String from string literal
  s.push_str(", world!");                 //push_str() appends to string
  println!("{}", s);                      //This will print `hello, world!`
```

### Deep copy, shallow Copy, Move
- For String its always shallow copy. 
- Consider a code where string s2 is created from s1. s1 and s2 both points to same memory.
```rust
  let s1 = String::from("hello");
  let s2 = s1;
  
In Memory
  s1
   |---------->  hello 
                  /\
  s2--------------|
```  
- Now if we want to print s1? This is compile time error.
  - *Why?* Rust invalidates the first variable(s1), ie when 2nd variable is created from 1st. 1st is invalidated. it’s known as a **move**.
  - *How Move is Good?* 
    - *1.* At runtime, copying memory is avoided, which is costly affair.
    - *2.* When s2 goes out of scope, its memory is freed, no tracking needed for s1.
```rust
  println!("{}, world!", s1);
```

#### Doing Deep copy using clone()
- Deep copy is costly operation and explicitly done using `clone()`.
```rust
    let s1 = String::from("hello");
    let s2 = s1.clone();

    println!("s1 = {}, s2 = {}", s1, s2);   //s1 = hello, s2 = hello
```

#### Data on stack is always Deep copied
- The data whose size of known at compile time, Eg: int, float, char. Its 2 copies are created always.
- Or there is no difference in deep and shallow copy here.
```rust
    let x = 5;
    let y = x;
    println!("x = {}, y = {}", x, y);   //x=5, y=5
```
- Some types that implement copy:
  - integer type(u32), bool, float(f64), char, Tuple that contain types that also implement Copy. Example, (i32, i32).
