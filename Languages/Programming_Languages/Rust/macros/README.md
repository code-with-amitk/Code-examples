**macros / Metaprogramming**
- [C Macro vs Rust Macro](#vs1)
- [macro vs functions](#vs2)
- Types of macros
  - [1. Declarative macros / macros by Example / macro_rules!](#dm)
  - [2. Procedural / Proc macros](#pm)
    - [2a. Function Like](#a1) 
    - [2b. Attribute Like](#a2)
    - [2c. Derive / custom derive](#a3)

## macros / Metaprogramming
**What is metaprogamming?**
- Any program contains two entities: data and instructions(that manipulate the data). Metaprogramming treats instructions as data and generate new instructions using code.
- _Runtime Metaprogramming languages:_ Python, Javascript, and Lisp.
- _compiletime Metaprogramming languages:_ C, C++, Rust (using macros). macros are expanded at [compile time](/Languages/Programming_Languages/C/Compile/).
- Examples of macros: println!, vec!

<a name=vs1></a>
### Rust macro vs C Macro
||Rust Macro|C Macro|
|---|---|---|
|How applied|Applied to the token tree|These are text substitution|
|Hygenic, Context Aware|Yes|No|

- **C Macro is UnHygenic, Not Context Aware?** original x variable in main() is modified by the expansion of the TEST macro. 
```c
#include <stdio.h> 
#define TEST(a) {
  x = a;
} 
int main() { 
    int x = 3;
    TEST(5);
    printf("x=%d",x);		//5 
}
```
- **Rust Macro is Hygenic & Context Aware?** original x variable in main() is modified by the expansion of the TEST macro. 
```rs
macro_rules! test {
    ($a:expr) => {
        temp = $a;
    };
}
fn main() { 
    let x = 3;
    test!(x);
}
$ cargo build
Compilation failed
```

<a name=vs2></a>
### macro vs functions
||Rust Function|Rust Macro|
|---|---|---|
|No & type of arguments|Must be declared early|can take a variable number of parameters|
|Implement Trait on given type.|can't(because called on runtime)|macro can do it(because expanded on compile time)|
>Note TRAIT needs to be implemented at compile time.



# Types of macros in Rust
<a name=dm></a>
## 1. Declarative macros / Macro by example / macro_rules! (similar to a match expression)
- **Disadv**
  - _1._ Debugging is difficult
  - _2._ Limited modification capabilities
  - _3._ Larger binaries
  - _4._ Longer compile time (this applies to both declarative and procedural macros)
#### a. Add string
```rs
pub const LR: &str = "# Learn ";
macro_rules! mac{                              //declared using macro_rules!
       ($a:expr, $b:expr)=>{
        LR.to_string() + $a + $b
       };
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
## 2. Procedural macros (More advanced than declarative)
- operate on the abstract syntax tree (AST)
- Procedural macros are functions that TAKE CODE as input, and returns Code. Similar to Decorators in Python.
```c
  Code as input(TokenStream) --> | Procedural Macro |
                                 | operator on code | --> Code as output(TokenStream)
```

**Types of Procedural macros:** Note all are same just annotations differ.
- _2a. function-like_
```rs
#[proc_macro]						<<<<<<<<<<< proc_macro
pub fn fun(input: TokenStream) -> TokenStream {
    TokenStream::new()
}

test() {                 //Usage
	fun!(be quick; time is mana);
}
```
- _2b. attribute_
```rs
#[proc_macro_attribute]					<<<<<<<<<<< extra _attribute
pub fn fun(input: TokenStream, annotated_item: TokenStream) -> TokenStream {
    TokenStream::new()
}
```
- _2c. derive macro_
```rs
#[proc_macro_derive(MyDerive)]				<<<<<<<<<<<< extra _derive
pub fn fun(annotated_item: TokenStream) -> TokenStream {
    TokenStream::new()
}
```
<a name=a1></a>
### 2a. Function-like macros
```rs
```
<a name=a2></a>
### 2b. Attribute Like Macros
Works on functions also with structs, enums.
```rs
```
<a name=a3></a>
### 2c. Derive proc Macro / Custom Derive macros   //Used as decorator in python
- ONLY works on structs, enums
- Annotated using `#[derive(MyMacro)]`. They can also declare helper attributes, which can be attached to members of the items.
```rs
NOTE THE PATH CORRECTLY

///////Create main////////////////
> pwd
C:\Users\kumara\source\repos\
> cargo new main
src\main.rs
use test_lib::TestTriat;
use test_lib_derive::TestTriat;

//Implement TestTrait TRAIT for struct structA
#[derive(TestTriat)]
struct StructA;

fn main() {
	StructA::fun();
}

> Cargo.toml
[package]
name = "main"
version = "0.1.0"
edition = "2018"

[dependencies]
test_lib = { path = "../test_lib" }
test_lib_derive = { path = "../test_lib/test_lib_derive" }

////////////////Create lib test_lib/////////////////////////
> pwd
C:\Users\kumara\source\repos\

> cargo new test_lib --lib
src/lib.rs
pub trait TestTriat {
    fn fun();
}

Cargo.toml
[package]
name = "test_lib"
version = "0.1.0"
edition = "2018"

> cargo run
Name: StructA

///////////////////////Create test_lib_derive inside test_lib////////////
> pwd
C:\Users\kumara\source\repos\test_lib

> cargo new test_lib_derive --lib
src\lib.rs
extern crate proc_macro;
use proc_macro::TokenStream;

// syntax crate. Rust Code -> [syn] -> syntax Tree Datastructure
use syn;            

// syntax Tree Datastructure -> [quote] -> Rust Code
use quote::quote;

//proc_macro_derive tells this is Custom derived macro with name HelloMacro
#[proc_macro_derive(TestTriat)]
pub fn fun_derive(input: TokenStream) -> TokenStream {

    //Parses Rust stream into Abstract Syntax Tree using syn crate
    let ast = syn::parse(input).unwrap();

    //Convert syntax tree to Rust code
    impl_fun(&ast)
}

fn impl_fun(ast: &syn::DeriveInput) -> TokenStream {
    let name = &ast.ident;
    let ge = quote! {
        impl TestTriat for #name {
            fn fun() {
                println!("Name: {}", stringify!(#name));
            }
        }
    };
    //Convert ge into TokenString
    ge.into()
}

> Cargo.toml
[package]
name = "test_lib_derive"
version = "0.1.0"
edition = "2018"

[lib]
proc-macro = true

[dependencies]
syn = "1.0"
quote = "1.0"
```