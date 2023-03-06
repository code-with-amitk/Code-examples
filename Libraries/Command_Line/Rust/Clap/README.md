**Clap / Command Line Argument Parser**
- [Parsing file name from cmd line](#f1)
- [Option](#f2)


<a name=f1></a>
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

<a name=f2></a>
### Optional cmdline
if variable is not None, then display cmdline argument, else donot.
```rs
use clap::{Arg, App};
const DUMMY:&str = "dummy";
fn main() {        
    let app = App::new("My Program")    //call new() from App crate
    .version("1.0")
    .author("Amit Kumar")
    .about("Does awesome things");
    let a:Option<bool> = None;
    let mut a_val = "".to_string();
    
    let app = app
            .arg(Arg::with_name("test2")
                .long("test2")
                .value_name("test2")
                .help("test2")
                .required(false)
                .takes_value(true)
                .default_value(&"test2")
            )
            .arg(if let Some(_a) = a {
                Arg::with_name("test3")
                    .short("t")
                    .long("test3")
                    .alias("test3")
                    .value_name("BOOL")
                    .help("test3")
                    .required(false)
                    .takes_value(true)
                    .default_value(&a_val)
            } else {
                Arg::with_name(DUMMY).hidden(true)
            });

    let matches = app.get_matches();

    if let Some(c) = matches.value_of("var_file_name") {
        println!("Value for config: {}", c);
    } else {
        println!("No value for config provided");
    }
}

$ cargo build   
$ ./clap --help         //test3 not shown
USAGE:
    clap [OPTIONS]
FLAGS:
    -h, --help       Prints help information
    -V, --version    Prints version information
OPTIONS:
        --test2 <test2>    test2 [default: test2]
```
