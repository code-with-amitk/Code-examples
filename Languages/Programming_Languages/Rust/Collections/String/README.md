- [1. string literal, type, slice](#lts)
- [2. str](#str)
- [3. String](#string)
- [4. Operations](#operations)
  - [4.1 Create](#create)
  - [4.2 Concatenate](#concatenate)
  - [4.3 Print](#print)
  - [4.4 Convert](#convert)
  - [4.5 Reverse](#reverse)
- [5. How strings are stored internally](#internal)


<a name=lts></a>
## 1. string literal, String type, String slice
- *1. string literal:* Are stored in the program’s exe(ie stack), these are also string slices.
- *2. String type:* **Allocated on heap and can grow**. String and string slices are [UTF-8 encoded](/Languages/Programming_Languages/C/Character_Sets/)
- *3. string slice:* Reference to part of a String taken as `string[starting_index, ending_index)`
```rust
  let lit:string = "test";                //1. STRING LITERAL
  
  let mut s = String::from("hello");      //2. STRING TYPE. 
  s.push_str(", world!");                 //push_str() appends to string
  println!("{}", s);                      //hello, world!
  
  let s = "T11 is Consistency";           //3. STRING SLICE
  let a = &s[0..3];             //a=T11
  let a = &s[..3];              //empty starting_index means 0
  
  let b = &a[4..6];             //b=is
  
  let c = &a[7..18];            //c=Consistency
  let c = &a[7..a.len()];
  let c = &a[7..];
  
  let d = &a[..];              //d=T11 is Consistency.   
```

<a name=lts></a>
## 2. str
- str is [Immutable Reference](/Languages/Programming_Languages/Rust). Immutable means which cannot be changed.
```rust
    let a = "T11 is Consistency";
    let b:&str = &a[0..4];            //Type of string slice is immutable reference.
    println!("{}",b);                 //T11
    
//Function returning string slice
fn main() {
    let mut a = String::from("T11 is Consistency");
    let b = fun(&a);                                      //Function taking string reference
    println!("{}",c);
}

fn fun(s:&String) -> &str {                               //Function returning String Slice
    &s[0..4]
}
```

<a name=string></a>
## 3. String
- string is growable, mutable, owned, UTF-8 encoded string type. string allocated on heap is shallow copy
```rust
  let s1:String = String::from("test");
  //let s2 = s1;                              //Shallow copy, ie s2,s1 both point to same memory. COMPLIER ERROR
  let s2 = s1.clone();                        //Deep Copy. Deep copy is costly operation.
  
  let a:i32 = 5;
  let b = a;                                  //Data on stack is always deep copied
```
- Its not allow to index into a String to get a character is that indexing operations because some [UTF-8](/Languages/Programming_Languages/C/Character_Sets/) characters are formed more than 1 byte. Eg: characters from 127-159 are used for creating characters using shift,cntrl keys. With string rust cannot determine exact sizeof string.
```rust
  let hello = "Здравствуйте";                 
  let answer = &hello[0];                   //Complilation error
  
  let answer = &hello[0..4];                //Allowed
```

<a name=operations></a>
## 4. Operations

<a name=create></a>
### 4.1 Create
  - from(), new()
```rust
    let s1 = String::new();                   //new()
    s1 = "test".to_string();

    let s2 = String::from("Hello");              //from()
```

<a name=concatenate></a>
### 4.2 Concatenate
  - Using push_str(), push() methods
```rust
    let s2 = String::from("Hello");
    s2.push_str(" World");                       //push_str() appends string.
    s2.push(' k');                               //push() appends 1 character
```
  - Using `+` operator
```rust
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

<a name=print></a>
### 4.3 Printing
- _chars():_ returns char types
```rust
    let hello = "Здравствуйте";
    for a in hello.chars() {
        println!("{}",a)
    }
```
- _bytes():_ returns raw bytes. Remember valid Unicode scalar values may be made up of more than 1 byte.
```rust
    let hello = "Здрав";
    for a in hello.bytes() {
        println!("{}",a)
    }
    
$ test.exe    
208
151
208
180
209
128
208
176
208
178
```

<a name=convert></a>
### 4.4 Convert
- **int to string**
```rust
let mut strA = a.to_string();
```
- **string to int**
```rust
let a = my_string.parse::<i32>().unwrap()
```

<a name=rev></a>
### 4.5 Reversing a string
```rust
strA = strA.chars().rev().collect::<String>();
```


<a name=internal></a>
## 5. How strings are stored internally
- A String is a wrapper over a `Vec<u8>`
