- [1. if expression](#ifexp)
- [2. Infinite loop = loop](#loop)
- [3. for](#for)
- [4. while](#while)
- [5. match](#match)

<a name=ifexp></a>
## 1. if expression
- This is decide whether to run the code or not based on condition.
- Paranthesis are mandatory in if-else block
- `()` is not required around if block.
- **Example**
```rust
fn main() {
  let a:i32 = 5;
  if a < 7 {
    println!("Yes");
  }else{
    println!("No");
  }
}  
# rustc test.rs
# ./test.exe
Yes
```
- **else if expression**
```rust
fn main() {
    let number = 6;

    if number % 4 == 0 {
        println!("number is divisible by 4");
    } else if number % 3 == 0 {
        println!("number is divisible by 3");
    } else if number % 2 == 0 {
        println!("number is divisible by 2");
    } else {
        println!("number is not divisible by 4, 3, or 2");
    }
}
```
- **Rust does not convert non-bool to bool **
  - This code give compilation error, Since It expects expression to be bool.
  - *Good Thing:* Unlike (C/C++), Rust does not try converting a(non-boolean) to bool
```rust
fn main() {
  let a = 3;                //a should be bool               
  if a {
    println!("Yes");
  }
}
# rustc test.rs
Compilation Error.

////////////This will work/////////////
fn main() {
    let a = 3;
    if a != 0 {
        println!("Yes");
    }
}
```

<a name=loop></a>
## 2. loop
- Loop executes infinitely until we press Control^C.
```rust
fn main() {
    loop {
        println!("again!");
    }
}
# rustc test.rs
# ./test.exe
again!
again!
^Cagain!
```
- **Returning Values from Loops**
```rust
fn main() {
    let mut counter = 0;
    let result = loop {
        counter += 1;
        if counter == 10 {
            break counter * 2;
        }
    };
    println!("The result is {}", result);               //Output=20
}
```

<a name=for></a>
## 3. for
```rust
fn main() {
  let a = [1, 2, 3, 4, 5];
  for b in a.iter() {
    println!("val: {}", b);
  }
}
val: 1
val: 2
val: 3
val: 4
val: 5
```
- **Reversing the range**
```rust
fn main() {
  for b in (1..4).rev(){
    println!("val:{}",b);
  }
}
# rustc test.rs
# ./test.exe
val:3
val:2
val:1
```

<a name=while></a>
## 4. while
```rust
fn main() {
  let mut a = 3;

  while a != 0 {
    println!("a:{}", a);

    a -= 1;
  }
}
# rustc test.rs
# test.exe
a:3
a:2
a:1
```

<a name=match></a>
## [5. match](match)
