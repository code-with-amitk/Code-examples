## enum inside module
- Unlike [structure in module](..), if [enum](/Languages/Programming_Languages/Rust) is public all its variants are also public. We need to explicitly make every enum variant as public as in struct.
```rust
mod module_a {
    pub enum color {
        red,          //all enum variants are public if enum is public
        yellow,
    }
}

pub fn fun() {
    let var = module_a::color::red;
}
```
