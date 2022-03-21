**Serde / Serialize DeSerialize**
- **Examples**
  - [1. Serializing Structure](#e1)

## Serde
Framework/library to Serialize/DeSerialize various data formats(JSON, toml, bson(used in mongodb), rusto_dynamodb and many more) and send.

### Examples
<a name=e1></a>
#### 1. Serializing Structure
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
#### 2. Json Object
```rs
````
```
