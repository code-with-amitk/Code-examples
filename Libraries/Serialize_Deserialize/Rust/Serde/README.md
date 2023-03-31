**Serde / Serialize DeSerialize**
- [serde_json](#sj)
- [1. Serialize/Deserialize Structure to/from json using serde_json](#e1)
- [2. Serialize/Deserialize YAML file to/from Structure using serde_yaml](#e2)

## Serde library
Used to Serialize/DeSerialize various data formats(JSON, toml, bson(used in mongodb), rusto_dynamodb and many more) and send.

<a name=sj></a>
### serde_json
- This is rust library for Serialize/Deserialize json data.
- We can encode and decode JSON to and from Rust data structures.

### Examples
<a name=e1></a>
#### 1. Serialize/Deserialize Structure to/from json using serde_json
```rs
$ cargo new serde
$ vim Cargo.toml
[package]
name = "serde"
version = "0.1.0"
authors = ["amitk"]
edition = "2018"
[dependencies]
serde = { version = "1.0", features = ["derive"] }
serde_json = "1.0"

$ vim main.rs
use serde::{Serialize, Deserialize};             
#[derive(Serialize, Deserialize, Debug)]    //Need derive macro to generate implementations of the Serialize and Deserialize traits
struct Point {
    x: i32,
    y: i32,
}
fn main() {
    let point = Point { x: 1, y: 2 };

    let serialized = serde_json::to_string(&point).unwrap();
    println!("serialized = {}", serialized);

    let deserialized: Point = serde_json::from_str(&serialized).unwrap();
    println!("deserialized = {:?}", deserialized);
}
$ cargo run
serialized = {"x":1,"y":2}
deserialized = Point { x: 1, y: 2 }
```

<a name=e2></a>
#### 2. Serialize/Deserialize YAML File to/from Struture using serde_yaml
```rs
$ test.yaml
    log_config:
      log_level: "debug"
      log_to_file: false
      rotate_keep: 20
      rotate_size_mb: 10
    version: 1.5.0

$ vim Cargo.toml
[package]
name = "serde_yaml"
version = "0.1.0"
edition = "2021"
[dependencies]
serde_yaml = {version="0.8"}
serde = {version="1.0"}
serde_derive = {ersion="1.0"}

$ vim src/main.rs
use serde_derive::{Deserialize, Serialize};
use std::thread;
use std::fs;
#[derive(Debug, Serialize, Deserialize, Clone)]
pub struct LogsConfiguration {
    pub rotate_sized_mb: u32,
    pub rotated_keep: usize,
    pub logs_to_file: bool,
    pub log_level: String,
}
#[derive(Debug, Serialize, Deserialize, Clone)]
pub struct Config {
    pub log_config: LogsConfiguration,
    pub version: String,
}
pub fn fun() {
    loop {
        let config_path = "/home/amit/test.yaml";
        
        //1. Read File
        let contents = match fs::read_to_string(config_path) {
            Ok(contents) => contents,
            Err(e) => {
                let k = format! {"failed to read config from {}, {:?}", config_path, e};
                println!("{}", k);
                break;
            }
        };

        println!("contents: {}", contents);
        
        //2. Serialize yaml file to structure
        let new_config: Config = match serde_yaml::from_str(&contents) {
            Ok(config) => config,
            Err(e) => {
                println!(
                    "failed to decode config (YAML) from {}, {:?}",
                    config_path, e
                );
                break;
            }
        };
        println!("config={:?}", new_config);
        break;
    }
}
fn main() {
    let handle1 = thread::spawn(fun);
    handle1.join().unwrap();
}

$ cargo run
contents:     
      log_config:
      log_level: "debug"
      log_to_file: false
      rotate_keep: 20
      rotate_size_mb: 10
    version: 1.5.0

config=Config { log_config: LogConfig { rotate_size: 10, rotated_kept: 20, logs_to_file: false, log_level: "debug" }, version: "1.5.0" }
```
