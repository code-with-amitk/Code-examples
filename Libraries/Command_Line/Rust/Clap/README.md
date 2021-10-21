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
const SERVER = "server";
fn main() {
    let matches = App::new("My Program")    //call new() from App crate
        .version("1.0")
        .author("Amit Kumar")
        .about("Does awesome things")
        .arg(
            Arg::with_name("SERVER")                         //Argument-1
            .short("s")                                     //shortname
            .long("SERVER")
            .value_name("ADDRESS")                           //Value is of type "Address"
            .help("Server Address")
            .required(false)
            .takes_value(true)
            .default_value("10.0.0.1")
        )
        .get_matches();

    if let Some(c) = matches.value_of("var_file_name") {   //its stored as matches.valueof_("var_file_name")
        println!("Value for config: {}", c);               //test.txt
    }
}

$ cargo build
$ command_line_args.exe -c test.txt
```
