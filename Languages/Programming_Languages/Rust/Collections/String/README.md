- **string literal, type, slice (or str)**
  - [Compared](#vs)
  - [str](#s1)
  - [String](#s2)
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

<a name=vs></a>
### str vs String
- Both have different ownership and mutability characteristics.
- **String literal:** string local variable, stored on stack
```rs
let a:string = "test";
```

||str(String Slice or Reference)|String|
|---|---|---|
|What|Part of string `string[starting_index, ending_index)`||
|Mutable(changable)| no(Cannot grow) | yes(Can grow) |
|How created|<ul><li>1. Using String Literal `let s = "test";`</li><li>or 2. Convert bytes to str</li></ul>|<ul><li>let mut s = String::from("he");</li><li>s.push_str(", world!");</li></ul>|
|Allocated on| Data Segment(String is nothing but bytes) | Heap | 

```c
               |          What                         |        Example                 |   Stored on  |
---------------|---------------------------------------|--------------------------------|--------------|--
string slice   | Reference to part of a String         | let s = "T11 is Consistency";  |
(or str)         string[starting_index, ending_index)  | let a = &s[0..3];  //T11
                 
String         | Allocated on heap and can grow        | let mut s = String::from("he");
                                                       | s.push_str(", world!");
                                                       | println!("{}", s);                 
```
<a name=s1></a>
### str
- str is [Immutable Reference](/Languages/Programming_Languages/Rust). Immutable means which cannot be changed.

<a name=s2></a>
### String
string is growable, mutable, owned, UTF-8 encoded string type. string allocated on heap is shallow copy
```rs
  let s1:String = String::from("test");
  //let s2 = s1;                              //Shallow copy, ie s2,s1 both point to same memory. COMPLIER ERROR
  let s2 = s1.clone();                        //Deep Copy. Deep copy is costly operation.
  
  let a:i32 = 5;
  let b = a;                                  //Data on stack is always deep copied
```
Its not allow to index into a String to get a character is that indexing operations because some [UTF-8](/Languages/Programming_Languages/C/Character_Sets/) characters are formed more than 1 byte. Eg: characters from 127-159 are used for creating characters using shift,cntrl keys. With string rust cannot determine exact sizeof string.
```rust
  let hello = "Здравствуйте";                 
  let answer = &hello[0];                   //Complilation error
  
  let answer = &hello[0..4];                //Allowed
```

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
