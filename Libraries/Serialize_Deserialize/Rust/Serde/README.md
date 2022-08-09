**Serde / Serialize DeSerialize**
- [1. Serialize/Deserialize Structure to/from json using serde_json](#e1)
- [2. Serialize/Deserialize yaml file to/from string using serde_yaml](#e2)

### Serde library
Used to Serialize/DeSerialize various data formats(JSON, toml, bson(used in mongodb), rusto_dynamodb and many more) and send.

### Exmples
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
#### 2. Serialize/Deserialize yaml file to/from string using serde_yaml
```rs
```
