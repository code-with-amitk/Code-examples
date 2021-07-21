- [minigrep](#minigrep)

<a name=minigrep></a>
## minigrep
- **What?** Small grep like program which find a string inside a file
```rs
  $ cargo run string_str a.txt            //Search string_str inside a.txt
```
- **Program Steps**
  - _1._ Declare a structure containing 2 strings. 1st: searchstring, 2nd filename in which string to be searched
  - _2._ Define function which can work on struct using impl block.
    - _2a._ new() [constructor function](..) 
      - Will take vector as input, fill structure members and return structure.
      - Returns [enum Result`<T,E>`](Languages/Programming_Languages/Rust/Error_Handling).
  - _3._ Read command line arguments and collect values into a vector.
  - _4._ Call new() function on struct Config, read Result`<T,E>` and call [unwrap_or_else](Languages/Programming_Languages/Rust/Error_Handling) on the returned result.
```rs
//Note that std::env::args will panic if any argument contains invalid Unicode. 
//If your program needs to accept arguments containing invalid Unicode, use std::env::args_os instead
use std::env;

use std::fs;
use std::process;

struct Config {                                             //1
    search_string: String,      //searchstring
    filename: String,           //filename in which to search
}

impl Config {                                               //2
    fn new(v: &[String]) -> Result<Config, &str> {       //2a
        if v.len() < 3 {
            return Err("not enough arguments");          //Err will be filled in str
        }
        let search_string = v[1].clone();
        let filename      = v[2].clone();
        Ok(Config { query, filename })
    }
}

fn main() {
    let v: Vec<String> = env::args().collect();              //3
    let config = Config::new(&v).unwrap_or_else(|err| {
        println!("Problem parsing arguments: {}", err);
        process::exit(1);
    });
                                                        
    //3. Read contents from file into contents.
    run(config);
}
```
