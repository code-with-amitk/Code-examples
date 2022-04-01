**Derive Macro**
- Code
  - [A. Annotate struct](#as)
  - [B. Convert Struct into String](#ex2)

## Derive proc Macro / Custom Derive macros   //Used as decorator in python
- ONLY works on structs, enums
- struct is annotated using `#[derive(MyMacro)]` and function is preceded by `#[proc_macro_derive]`

### Code
<a name=as></a>
#### A. Annotate struct
```rs
NOTE THE PATH CORRECTLY

///////Create main////////////////
> pwd
C:\Users\kumara\source\repos\
> cargo new main
src\main.rs
use test_lib::TestTriat;
use test_lib_derive::TestTriat;

#[derive(TestTriat)]			//Implement TestTrait TRAIT for struct structA
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

use syn;            				// syntax crate. Rust Code -> [syn] -> syntax Tree Datastructure

use quote::quote;				// syntax Tree Datastructure -> [quote] -> Rust Code

#[proc_macro_derive(TestTriat)]			//proc_macro_derive tells this is Custom derived macro with name HelloMacro
pub fn fun_derive(input: TokenStream) -> TokenStream {

    let ast = syn::parse(input).unwrap();	//Parses Rust stream into Abstract Syntax Tree using syn crate
    impl_fun(&ast)				//Convert syntax tree to Rust code
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
    ge.into()					//Convert ge into TokenString
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

<a name=ex2></a>
#### B. Convert Struct into String
```rs
$ pwd
C:/test
$ dir
03/24/2022  11:30 AM               261 Cargo.toml
03/24/2022  12:47 PM    <DIR>          into_map
03/24/2022  12:47 PM    <DIR>          into_map_derive
03/24/2022  12:47 PM    <DIR>          src

$ cat Cargo.toml
[package]
name = "into_map_demo"
version = "0.1.0"
edition = "2018"

[dependencies]
into_map = { path = "into_map" }
into_map_derive = { path = "into_map_derive" }

$ cat src/main.rs
use into_map_derive::IntoMap;

#[derive(IntoMap)]
struct Metrics {
    help: String,
    typed: String,
    val: String,
}
fn main() {
    let mut out = "".to_string();
    let req = 4;
    out.push_str(
        &Metrics {
            help: "api_requests Stats API Requests".to_string(),
            typed: "api_requests counter".to_string(),
            val: "api_requests ".to_string() + &req.to_string(),
        }
        .into_map(),
    );
    println!("string={:?}", out);
}
$ cargo run
string="# HELP api_requests CommonGlobalStats API Requests\n# TYPE api_requests counter\napi_requests 4\n\n

///cd into_map////
$ more Cargo.toml
[package]
name = "into_map"
version = "0.1.0"
edition = "2018"

$ more src\lib.rs
pub trait IntoMap {
    fn into_map(&self) -> String;
}

////cd into_map_derive//////
$ more Cargo.toml
[package]
name = "into_map_derive"
version = "0.1.0"
edition = "2018"

[lib]
proc-macro = true

[dependencies]
#syn = { version = "0.15.22, features = ["extra-traits"] }
syn = { version = "0.15.22" }
quote = "0.6.10"
into_map = { path="../into_map" }

$ more src\lib.rs
extern crate proc_macro;
use proc_macro::TokenStream;
use quote::quote;
use syn::{export::Span, parse_macro_input, Data, DeriveInput, Fields, Ident};

#[proc_macro_derive(IntoMap)]
pub fn into_map_derive(input: TokenStream) -> TokenStream {
    let mut insert_tokens = vec![];
    let parsed_input: DeriveInput = parse_macro_input!(input);
    let struct_name = parsed_input.ident;
    match parsed_input.data {
        Data::Struct(s) => {
            if let Fields::Named(named_fields) = s.fields {
                let a = named_fields.named;

                for i in a {
                    let field = match i.ident {
                        Some(a) => a,
                        None => {
                            println!("None");
                            Ident::new(&"".to_string(), Span::call_site())
                        }
                    };

                    let insert_token = quote! {

                        match stringify!(#field) {
                            "help" => {
                                s.push_str("# HELP ");
                                s.push_str(&self.#field.to_string());
                            },
                            "typed" => {
                                s.push_str("# TYPE ");
                                s.push_str(&self.#field.to_string());
                            },
                            _ => {
                                s.push_str(&self.#field.to_string());
                                s.push_str("\n");
                            }
                        }
                        s.push_str("\n");

                    };
                    insert_tokens.push(insert_token);
                }
            }
        }
        _other => {
            panic!("IntoMap is not yet implemented")
        }
    }
    let tokens = quote! {
        use into_map::IntoMap;

        impl IntoMap for #struct_name {
            /// Converts the given struct into a string
            fn into_map(&self) -> String {
                let mut s = "".to_string();
                #(#insert_tokens)*
                s
            }
        }
    };

    proc_macro::TokenStream::from(tokens)
}
```
