- **string literal, type, slice (or str)**
  - [String Literal](#sl)
  - [str vs String](#vs)
- **Operations**
  - [Create](#cre)
  - [Concatenate](#con)
  - [Print](#p)
  - [Convert](#convert)
  - [Reverse](#reverse)
  - [Tokenize](#t)
- [How strings are stored internally](#internal)


<a name=lts></a>
## string literal, String, String slice(or str)
- String and string slices are [UTF-8 encoded](/Languages/Programming_Languages/C/Character_Sets/)

<a name=sl></a>
### String literal
- Both have different ownership and mutability characteristics.
- **String literal:** string local variable, stored on stack
```rs
let a:string = "test";
```

<a name=vs></a>
### &str vs String
||&str(String Slice or Reference)|String|
|---|---|---|
|What|Part of string `string[starting_index, ending_index)`||
|Mutable(changable)| no(Cannot grow) | yes(Can grow) |
|How created|<ul><li>1. Using String Literal `let s = "test";`</li><li>or 2. Convert bytes to str</li></ul>|<ul><li>let mut s = String::from("he");</li><li>s.push_str(", world!");</li></ul>|
|Allocated on| Data Segment(String is nothing but bytes) | Heap | 

## Operations
<a name=cre></a>
### Create
from(), new()
```rs
    let s1 = String::new();                   //new()
    s1 = "test".to_string();

    let s2 = String::from("Hello");              //from()
```

<a name=con></a>
### Concatenate
Using push_str(), push() methods
```rs
    let s2 = String::from("Hello");
    s2.push_str(" World");                       //push_str() appends string.
    s2.push(' k');                               //push() appends 1 character
```
Using `+` operator
```rs
    let s1 = String::from("Test");
    let s2 = String::from("Foo");

    let s3 = s1 + &s2;                          //Why reference. Operator + uses add method `fn add(self, s: &str) -> String {..}`
    //println!("{}",s1);                        //Since s1 is moved not copied
```
  - Using format()! function
```rust
    let s1 = String::from("Test");
    let s2 = String::from("Foo");

    let s3 = format!("{} {}",s1,s2);            //Test Foo  
```

<a name=p></a>
### Print
- _chars():_ returns char types
```rs
    let hello = "Здравствуйте";
    for a in hello.chars() {
        println!("{}",a)
    }
```
#### Using index
**as_bytes():** returns raw bytes. Valid Unicode scalar values may be made up of more than 1 byte.
```rs
    let hello = "abcdd";
    let k = hello.as_bytes();
    let i = 0;
    while i < hello.len() {
        println!("{}",k[i]);
        i += 1;
    }
    
$ test.exe
a b c d d
```

<a name=convert></a>
### Convert
**int to string**
```rs
let mut strA = a.to_string();
```
**string to int**
```rust
let a = my_string.parse::<i32>().unwrap();
```

<a name=rev></a>
### Reversing a string
```rs
strA = strA.chars().rev().collect::<String>();
```

<a name=t></a>
### Tokenize
```rs
  let a = "40:20".to_string();
  let vec:Vec<&str> = a.split(':').collect();
```

<a name=internal></a>
## 5. How strings are stored internally
- A String is a wrapper over a `Vec<u8>`
