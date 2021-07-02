- [1. What is Generic Type](#gen)
  - [1.1 Generic Structure](#genst)

<a name=gen></a>
## 1. Generic Type
- Same as templates, used to handle the duplicate data types,code.

<a name=genst></a>
### 1.1 Generic Structure
```rust
struct  point<T,U> {
    x:T,
    y:U,
}
fn main() {
    let test = point  {
        x:10,
        y:'c',
    };
}
```
