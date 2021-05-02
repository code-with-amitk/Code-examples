## Guessing Game
- **What?** Program takes a number between 1 and 100. Asks user to guess it.

## Code
- **1. Create project**
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
- **2. Create project's source file**
  - *2a.* std::io library is used for dumping result on screen. The io library comes from the standard library (which is known as std).
  - *2b.* Entry point into program
  - *2c.* Cerate a multable variable using `let` statement.
  - *2d.* stdin() returns handle of standard input ie of type std::io::Stdin.
  - *2e.* read_line(&string) Gets input from stdin and place in mutable string.
  - *2f.* read_line() also returns a value ie IO result, which is handled by expect()
  - *2g.* Print the value entered using `{}` which is same as `%d`.
```rust
$ vim src/main.rs

use std::io;                            //2a
fn main() {                             //2b

    println!("Please input your guess.");
    
    let mut a = String::new();           //2c

    io::stdin()                          //2d
        .read_line(&mut a)               //2e
        .expect("Failed to read line");  //2f

    println!("You guessed: {}", a);      //2g
}
```
- **3. Compiling & Running the Program**
```rust
> cargo run
   Compiling guessing_game v0.1.0 (C:\Users\amitk\.rustup\source\guessing_game)
    Finished dev [unoptimized + debuginfo] target(s) in 2.02s
     Running `target\debug\guessing_game.exe`
Please input your guess.
1
You guessed: 1
```
