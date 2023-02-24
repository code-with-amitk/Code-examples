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
- This allows to combine an if statement with a pattern matching expression. It is a shorthand way to write a match expression that only handles one specific pattern.
```c
if let pattern = expression {
    // code to run if the pattern matches
}
```
- Here, pattern is a pattern that we want to match against expression. If the pattern matches, the code block inside the curly braces will be executed.
```rs
let a = Some(42);
if let Some(b) = a {
    println!("The b is {}", b);
} else {
    println!("There is no number");
}
```
- In this example, a is an `Option<i32>` that contains the value 42.
- The if let statement checks if a is a Some variant and binds the inner value to number. 
- Since a is a Some variant, the code inside the curly braces will be executed and "The number is 42" will be printed to the console.

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
