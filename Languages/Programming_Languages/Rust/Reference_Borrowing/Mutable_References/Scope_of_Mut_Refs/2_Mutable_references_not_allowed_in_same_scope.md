## 2 Mutable references are not allowed in same scope
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
  - *Mutable References are allowed in seperate scope*
```rustc
  let mut s = String::from("hello");
  {
    let r1 = &mut s;
  } // r1 goes out of scope here, so we can make a new reference with no problems.
  let r2 = &mut s;
```
