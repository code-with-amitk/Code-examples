## Guessing Game
- **What?** Program takes a number between 1 and 100. Asks user to guess it.

## Code
- **1. Creating project**
```rust
$ cargo new guessing_game
$ cd guessing_game

$ cat cargo.toml
[package]
name = "guessing_game"
version = "0.1.0"
authors = ["amitk"]
edition = "2018"

[dependencies]
```
- **2. Creating project's source file
```rust
$ vim src/main.rs

use std::io;                            //2a. std::io library is used for dumping result on output. The io library comes from the standard library (which is known as std):

fn main() {
    println!("Guess the number!");

    println!("Please input your guess.");

    let mut guess = String::new();

    io::stdin()
        .read_line(&mut guess)
        .expect("Failed to read line");

    println!("You guessed: {}", guess);
}
```
