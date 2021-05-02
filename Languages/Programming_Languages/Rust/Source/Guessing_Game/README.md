## Guessing Game
- **What?** Program takes a number between 1 and 100. Asks user to guess it.

## Code
- **1. Create project**
  - *1a.* Add rand library as dependency, cargo will download from [crates.io](https://crates.io/crates/rand)
  - *1b.* Ask cargo to fetch library from crates.io
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
rand = "0.8.0"              //1a

$ cargo build               //1b
    Updating crates.io index
  Downloaded rand v0.5.5
  Downloaded libc v0.2.62
  Downloaded rand_core v0.2.2
  Downloaded rand_core v0.3.1
  Downloaded rand_core v0.4.2
   Compiling rand_core v0.4.2
   Compiling libc v0.2.62
   Compiling rand_core v0.3.1
   Compiling rand_core v0.2.2
   Compiling rand v0.5.5
   Compiling guessing_game v0.1.0 (file:///projects/guessing_game)
    Finished dev [unoptimized + debuginfo] target(s) in 2.53s
```
- **2. Create project's source file**
  - *a.* std::io library is used for dumping result on screen. The io library comes from the standard library (which is known as std).
    - *a.* Use rand library for random number generation.
  - *b.* Generate a random number using `gen_range[start..end)`
  - *c.* stdin() returns handle of standard input ie of type std::io::Stdin. read_line(&string) Gets input from stdin and place in mutable string. read_line() also returns a value ie IO result, which is handled by expect().
  - *d.* Print the value entered using `{}` which is same as `%d`.
  - *e.* trim() the entered word for spaces and convert to u32.
  - *f.* compare `secret_number` with a.
```rust
$ vim src/main.rs

use std::io;                              //a
use std::cmp::Ordering;                   //For match expression
use rand::Rng;                            //For gen_range()

fn main() {
    
    let secret_number =  rand::thread_rng().gen_range(0..100);    //b
    println!("The secret number is: {}", secret_number);

    loop{   //infinite loop
        
        let mut a = String::new();                  //c
        io::stdin()
            .read_line(&mut a)
            .expect("Failed to read line");
        println!("You entered: {}", a);             //d
    
        let a: u32 = a.trim().parse().expect("Please type a number!");  //e
    
        match a.cmp(&secret_number) {                         //f
            Ordering::Less => println!("Too small!"),         
            Ordering::Greater => println!("Too big!"),
            Ordering::Equal => {
                println!("You win!");
                break;
            }
        }
        println!("You guessed: {}", a);
    }
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
