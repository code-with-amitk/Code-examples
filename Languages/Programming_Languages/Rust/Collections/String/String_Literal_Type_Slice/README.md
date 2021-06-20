## string literal, type, slice
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
