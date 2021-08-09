- [if expression](#if)
  - [else if](#elseif)
- [Infinite loop = loop](#loop)
  - [Returning Values from Loop](#ret)
- [for](#for)
  - [Reversing the range](#rev)
- [while](#while)
- [match_switch](#match)

<a name=if></a>
### if expression
This is decide whether to run the code or not based on condition. Paranthesis are mandatory in if-else block. `()` is not required.
```rs
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
<a name=elseif></a>
**else if**
```rs
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
**Rust does not convert non-bool to bool: Good Thing:** This code give compilation error, Since It expects expression to be bool.
```rs
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
### loop
Executes infinitely until we press Control^C.
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
<a name=ret></a>
**Returning Values from Loops**
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
### for
```rs
  let a = [1, 2];
  for b in a.iter() {
    println!("{}", b);      //1,2 
  }
  
OR 

  for i in 0..3 {         //for (i=0; i<3; ++i)
    println!("{}", i);    //0, 1, 2
  }  
```
<a name=rev></a>
**Reversing the range**
```rs
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
### while
```rs
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
### [match_switch](match_switch)
