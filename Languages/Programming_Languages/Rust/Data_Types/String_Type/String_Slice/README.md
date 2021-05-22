## String Slice
- **What?** This is a Reference to part of a String taken as `string[starting_index, ending_index)`
- Examples
```rust
  let s = "T11 is Consistency";
  let a = &s[0..3];             //a=T11
  let a = &s[..3];              //empty starting_index means 0
  
  let b = &a[4..6];             //b=is
  
  let c = &a[7..18];            //c=Consistency
  let c = &a[7..a.len()];
  let c = &a[7..];
  
  let d = &a[..];              //d=T11 is Consistency. 
```
