match
- [Default Statement in match](#def)
- [Patterns that Bind to Values](#patval)
- [Matching Option`<T>`](#opt) 

### match
Similar to (switch + enum class) of c++. **Rules**
  - _1._ match is followed by expression to be evaluated (same as switch)
  - _2._ `pattern => code`. This is called _match arm_. Pattern is matched and corresponding code is executed. Each arm is seperated by `,`.
```rust
enum Color{
    Red,
    Black,
}
fn color_value(var:Color) -> u8 {
    match var {                       //1
        Color::Red => {               //2
            print!("Red");
            1
        }
        //if we forget to define all match enum variables, Rust gives compile time error
    }
}
fn main() {
    println!("{:#?}",color_value(Color::Red));
}
```

<a name=def></a>
### Default Statement in match
default statement in rust is represented by underscore `_`.
  - _a._ match = switch
  - _b._ Default case
```rust
//#[derive(Debug)]
fn find(var:u8) -> u8 {
    match var{                          //a
        1 => {println!("one");
            1
        },
        _ => {println!("default");        //b
            255
        }
    }
}
fn main() {
    println!("{:#?} ",find(3));
}
$ rustc test.rs
$ test.exe
default
255
```

<a name=patval></a>
### Patterns that Bind to Values
- _1._ Created enum.
- _2._ Binded a value(enum) to enum
- _3._ `pattern => code` pattern is binded to value, which's printed.
```rust
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
