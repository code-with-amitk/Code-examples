## String
- **string literal, string type, string slice**
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
- **str** str is [Immutable Reference](/Languages/Programming_Languages/Rust/Reference_Borrowing). Immutable means which cannot be changed
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
- string allocated on heap is shallow copy
```rust
  let s1:String = String::from("test");
  //let s2 = s1;                                //Shallow copy, ie s2,s1 both point to same memory. COMPLIER ERROR
  let s2 = s1.clone();                          //Deep Copy. Deep copy is costly operation.
  
  let a:i32 = 5;
  let b = a;                                  //Data on stack is always deep copied
```
