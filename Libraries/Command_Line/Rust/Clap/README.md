**Clap / Command Line Argument Parser**
- **Source**

## Source
### 1. Parsing file name from cmd line
```rs
$ cargo new command_line_args
$ cat Cargo.toml
[package]
name = "command_line_args"
version = "0.1.0"
authors = ["amitk"]
edition = "2018"

[dependencies]
clap = "2.33.3"

$ cat main.rs
use clap::{Arg, App};
fn main() {
    let matches = App::new("My Super Program")    //call new() from App crate
        .version("1.0")
        .author("Amit Kumar")
        .about("Does awesome things")
        .arg(
            Arg::with_name("config")
            .short("c")
            .long("config")
            .value_name("FILE")
            .help("Sets a custom config file")
            .takes_value(true)
        )
        .get_matches();

    if let Some(c) = matches.value_of("config") {   //its stored as matches.valueof_("arg_name")
        println!("Value for config: {}", c);        //test.txt
    }
}

$ cargo build
$ command_line_args.exe -c test.txt
```
