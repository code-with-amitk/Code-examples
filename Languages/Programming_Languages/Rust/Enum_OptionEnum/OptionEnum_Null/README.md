## Rust does not have NULL 
- Tony Hoare(inventor of NULL) said invention of NULL is his Billion dollar mistake.
  - [Why creating NULL was mistake?](Why_creating_NULL_was_mistake)

### Option Enum?
- This is another kind of enum in rust which takes either of 2 values: Some or None
```rust
enum Option<T> {          //T is template which can take any type: i32, i64 etc
    Some(T),
    None,
}
```
- [Option<`T`> Code Examples](Option_T_Examples)
