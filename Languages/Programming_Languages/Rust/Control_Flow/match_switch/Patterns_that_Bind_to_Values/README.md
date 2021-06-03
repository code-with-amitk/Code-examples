## Patterns that Bind to Values
- _1._ Created enum.
- _2._ Binded a value(enum here) to enum
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
