**match = switch+enum(in c++)**
- [Default Statement](#def)
  - [if let](#iflet)
- [Patterns that Bind to Values](#patval)
- [Matching Option`<T>`](#opt) 

### match
`pattern => code`. This is called _Match Arm_. Pattern is matched and corresponding code is executed. Each arm is seperated by `,`.
```rs
//////Example-1/////
enum Color{
    Red,
    Black,
} 
fn color_value (var : Color) {
    match var {                       //switch (var)
        Color::Red => {               //case 1 =>       //Match Arm
            print!("Red");
        }
        //if we forget to define all match enum variables, Rust gives compile time error
    }
}
fn main() {
    println!("{:#?}", color_value(Color::Red));
}

//////Example-2 (same as switch)////////
                match a[0] {  
                    "a" => println!("a"),
                    "b" => println!("b"),
                    "c" => println!("c"),
                    _ => println!("default"),
                 }
```

<a name=def></a>
### Default Statement
default statement in match in rust is represented by underscore `_`.
```rs
fn main() {
    let a = Some(4);
    match a {
        Some(3) => println!("Something"),   //some=Anything
        _ => (),                       //Default case
    }
}
$ rustc test.rs
$ test.exe
```
<a name=iflet></a>
#### [if let](https://doc.rust-lang.org/book/ch06-03-if-let.html)
- Problem in above code: Lot of unused code(ie We want to do Something with Some(3) but nothing with None or any other value). To satisfy the match expression, we have to add `_ => ()` after processing just one variant, which is a lot of boilerplate code to add.
- Just match one pattern while ignore rest.
```rs
fn main() {
    if let Some(3) = 3 {
        println!("Something")
    }
}
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
