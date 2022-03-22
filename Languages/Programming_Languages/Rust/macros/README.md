**macros**
- Types of macros
  - [1. Declarative macros](#dm)
  - [2. Procedural macros](#pm)

## macros
Expanded during [compile time](/Languages/Programming_Languages/C/Compile/).

||Rust Macro|C Macro|
|---|---|---|
|How applied|Applied to the token tree|These are text substitution|

## Types of macros in Rust
<a name=dm></a>
### 1. Declarative macros (similar to a match expression)
#### a. Add string
```rs
pub const LR: &str = "# Learn ";
macro_rules! mac{                              //declared using macro_rules!
       ($a:expr, $b:expr)=>{
        LR.to_string() + $a + $b
       }
       ($a:expr)=>{                           //if macro takes 1 argument, we can define match for it as well
            $a
       }
   }

fn main() {
  let h = help! (&"All".to_string(), &" Times".to_string());
  println!("{}", h);      //# Learn All Times
}
```
#### b. Convert types before addition
```rs
macro_rules! add_as{
    ($a:expr,$b:expr,$typ:ty)=>{
        $a as $typ + $b as $typ
    }
}
fn main(){
    println!("{}",add_as!(0,2,u8));
}
```
#### c. Variable number of arguments
##### 0 or more arguments
token type that repeats is enclosed in `$()`
```rs
macro_rules! add_as{
    ($($a:expr), *) =>{        //Variable no of argumens
        500         // if no arguments, return 500
        $(+$a)*     // When arguments are present. +$a is a repeating code.
    }
}
fn main(){
    println!("{}",add_as!(1,2,3,4));        //510
    println!("{}",add_as!());               //500
}
```
##### [TT Muncher](https://danielkeep.github.io/tlborm/book/pat-incremental-tt-munchers.html) / Recursive Parsing of Arguments
A "TT muncher" is a recursive macro that works by incrementally processing its input one step at a time.
```rs
macro_rules! add{
       ($a:expr)=>{     //1 argument
           $a
       };
       ($a:expr,$b:expr)=>{     //2 arguments
               $a+$b
       };
       ($a:expr, $($b:tt)*)=>{       //more arguments
              $a + add!($($b)*)      //$($b)* is TT Muncher calling next argument incrementally
       }
   }
   fn main(){
       println!("{}",add!(1,2,3,4));    //10
       println!("{}",add!(1));          //1
   }
```
<a name=pm></a>
### 2. Procedural macros
- operate on the abstract syntax tree (AST)
