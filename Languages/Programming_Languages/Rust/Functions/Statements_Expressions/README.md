## Statements & Expressions
### Statements
- These are instructions that perform some action and do not return a value. 
- **Examples**
```rust
  let y = 6;
```

### Expressions 
- Returns a value.
- **Examples**
```rust
fn main(){
  let x = fun();
}
fn fun() -> i32 {
  let y = 5;
  y + 1                   //Expression returning a value.
  //y + 1;                   //When ; is placed it becomes statement and will not return a value
}
```
