**[SodiumOxide / NaCl](#s)**
- [Program: Encrypt, Decrypt with sodium](#ed)

<a name=s></a>
## Sodium
This is high-speed library for encryption, decryption, signatures derived from [C sodium library](https://github.com/jedisct1/libsodium)
```rs
$ git clone https://github.com/sodiumoxide/sodiumoxide.git    //Download source
$ cd sodiumoxide; git submodule update --init --recursive
$ cargo build                                                 //Build
$ cargo test
$ cargo doc                                                   //Generates documentation in target/doc/
  
```

<a name=ed></a>
### Program: Encrypt, Decrypt with sodium
```
$ cargo new encryption
$ cat Cargo.toml
[package]
name = "encryption"
version = "0.1.0"
authors = ["amitk"]
edition = "2018"

[dependencies]
sodiumoxide = {version="0.2.7"}
$ main.rs
use sodiumoxide::crypto::secretbox;
fn main() {
    let key = secretbox::gen_key();
    let nonce = secretbox::gen_nonce();
    let plaintext = b"some data";
    let ciphertext = secretbox::seal(plaintext, &nonce, &key);
    let their_plaintext = secretbox::open(&ciphertext, &nonce, &key).unwrap();
    assert!(plaintext == &their_plaintext[..]);

    println!("Hello, world!");
}
$ cargo run
```
