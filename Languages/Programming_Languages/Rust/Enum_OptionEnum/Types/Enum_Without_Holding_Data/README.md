## Enums same as enum class in C++
  - *1.* To print debugging information, we need to explicitly add annotation `#[derive(Debug)]` for enum.
  - *2.* Declare enum same
  - *3.* Initialize variable with enum value
  - *4.* Print enum after passing to function
```rust
#[derive(Debug)]            //1
enum Color{                 //2
    Red,
    Blue,
    Green
}

fn fun (a:Color) {          //4
    println!("{:#?}",a);
}

fn main() {
    let a:Color = Color::Red; //3
    fun(a);
}
```
