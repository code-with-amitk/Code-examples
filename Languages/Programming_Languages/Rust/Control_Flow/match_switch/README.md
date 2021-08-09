- [match](#mat)
- [Default Statement](#def)
  - [if let](#iflet)
- [Patterns that Bind to Values](#patval)
- [Matching Option`<T>`](#opt) 

<a name=mat></a>
### match
Similar to (switch + enum class) of c++. Example
  - `pattern => code`. This is called _Match Arm_. Pattern is matched and corresponding code is executed. Each arm is seperated by `,`.
```rust
enum Color{
    Red,
    Black,
} 
fn color_value (var : Color) {
    match var {                       //var is expression to be evaluated
        Color::Red => {               //Match Arm
            print!("Red");
        }
        //if we forget to define all match enum variables, Rust gives compile time error
    }
}
fn main() {
    println!("{:#?}", color_value(Color::Red));
}
```

<a name=def></a>
### Default Statement
default statement in match in rust is represented by underscore `_`.
```rs
fn main() {
    let a = Some(4);
    match a {                           //Match case
        Some(3) => println!("Something"),
        _ => (),                       //Default case
    }
}
$ rustc test.rs
$ test.exe
```
<a name=iflet></a>
#### if let
Problem in above code is We want to do Something with Some(3) but nothing with None or any other value. To satisfy the match expression, we have to add `_ => ()` after processing just one variant, which is a lot of boilerplate code to add.
```rs

```

<a name=patval></a>
### Patterns that Bind to Values
- _1._ Created enum.
- _2._ Binded a value(enum) to enum
- _3._ `pattern => code` pattern is binded to value, which's printed.
```rs
#[derive(Debug)]
enum Food{
    Pizza,
    Pulses,
}
enum Week{                  //1
    Mon,
    Wed,
    Fri(Food),              //2
}

fn find(var:Week) -> u8 {
    match var{
        Week::Mon => {
            print!("Nothing Special");
            1
        }
        Week::Wed => 2,
        Week::Fri(var_food) => {                          //3
            print!("Today's Food {:#?}",var_food);
            3
        },
    }
}
fn main() {
    println!("{:#?} ",find(Week::Fri(Food::Pizza)));
}
```

<a name=opt></a>
### Matching Option`<T>`
[What is Option`<T>`](../../../Enum_OptionEnum/OptionEnum_Null/).
- **Example**
  - _1._ Defined function taking Option`<T>` and returning Option`<T>`.
  - _2._ `pattern => code`. pattern can be some or None only.
```rs
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
