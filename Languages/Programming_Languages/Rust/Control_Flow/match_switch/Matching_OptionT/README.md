## Matching Option`<T>`
- [What is Option`<T>`](../../../Enum_OptionEnum/OptionEnum_Null/) This is called Option Enum which is replacement of NULL in rust.
- **Example**
  - _1._ Defined function taking Option`<T>` and returning Option`<T>`.
  - _2._ `pattern => code`. pattern can be some or None only.
```rust
fn find(var:Option<i32>) -> Option<i32> {         //1
    match var{
        Some(i) => Some(i+1),                     //2
        None => None
    }
}
fn main() {
    println!("{:#?} ",find(Some(5)));
    println!("{:#?} ",find(None));
}

$ .\main.exe
Some(
    6,
)
None  
```
