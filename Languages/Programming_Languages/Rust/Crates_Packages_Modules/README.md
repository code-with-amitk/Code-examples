- **Crates**
  - [1. rand](#rand)
  - [2. Prometheus(Pull based)](#pro)
  - [3. proc macro](#pm)
  - [4. proc macro](#pm2)
- **Packages**
  - [Workspace](#ws)
- **[Modules](https://code-with-amitk.github.io/Languages/Programming/Rust/Modules.html)**


## Crates 
crate is a binary(executable file having main()) or library(shared or static library) in rust.

<a name=rand></a>
### 1. rand
Rust library for random number generation. Using rand crate:
```rs
$ Cargo.toml
[dependencies]
rand = "0.8.0"    //Add rand library as dependency, cargo will download from crates.io
```
[thread_rng()](//https://docs.rs/rand/0.8.4/rand/fn.thread_rng.html): Generate random number
```rsp
thread_rng().gen_range(0..100)    //Generate random no between [0,100)    //pub fn thread_rng() -> ThreadRng
```

<a name=pro></a>
### [2. Prometheus, Pull Based System](/System-Design/Concepts/Logging_and_Monitoring/Prometheus/)
[Prometheus crate](https://github.com/tikv/rust-prometheus) is rust client library for prometheus. [What is Client library?](/System-Design/Concepts/Logging_and_Monitoring/Prometheus/README.md#hl).
#### Using Prometheus Crate
> [Example from here](https://github.com/tikv/rust-prometheus/blob/master/examples/example_custom_registry.rs)
- **1. Create a [Registry](https://docs.rs/prometheus/latest/prometheus/struct.Registry.html) `pub struct Registry { /* fields omitted */ }`**
  - Registry is a structure where [Prometheus collectors](/System-Design/Concepts/Logging_and_Monitoring/Prometheus/README.md#col) will register for collecting metrics.
```rs
impl Registry {
  pub fn new() -> Registry              //Create new Registry.
  pub fn new_custom(                    //Create new registry, with optional custom prefix and labels.
    prefix: Option<String>,
    labels: Option<HashMap<String, String>>
  ) -> Result<Registry>
}
let custom_registry = Registry::new_custom(Some("myprefix".to_string()), Some(labels)).unwrap();
```
- **2. Register Collector to registry, Collector will do metric collection**
  - [Prometheus Metrices](/System-Design/Concepts/Logging_and_Monitoring/Prometheus/README.md#met), [Rust crate Metric]((https://docs.rs/prometheus/latest/prometheus/core/trait.Metric.html)
```rs
impl Registry {
  pub fn register(&self, c: Box<dyn Collector>) -> Result<()>   //Register
}
custom_registry.register(Box::new(CUSTOM_COUNTER.clone())).unwrap();
```
- **3. [Collector/Exporter/End point](/System-Design/Concepts/Logging_and_Monitoring/Prometheus/README.md#int) collects data**
  - End point will call [gather() method](https://docs.rs/prometheus/latest/prometheus/fn.gather.html) which will return [structure of metrices called MetricFamily](https://docs.rs/prometheus/latest/prometheus/proto/struct.MetricFamily.html) using [encoder](https://docs.rs/prometheus/latest/prometheus/trait.Encoder.html)

#### Code 
```rs
     COLLECTOR
  dr = prometheus::default_registry(); 
                            |---------create registry-------> struct RegistryCore {
                                                                                  .. };
  dr.register(static int a)-------add variable to registry--> |a=0|
  a++                                                         |a=1|
  
  Get registry structure as vector ----gather()------------->
         let mf = <--------vec<MetricFamily>-----------------

  let encoder = prometheus::TextEncoder::new();
                  ---------encoder.encode(mf)---------------->
                  <------------String------------------------
  Display the string


$ cat Cargo.toml
..
[dependencies]
prometheus = "0.13.0"
lazy_static = "1.4.0"

$ cat main.rs
use std::collections::HashMap;
use prometheus::{Encoder, IntCounter, Registry};
use lazy_static::lazy_static;

lazy_static! {
    static ref DEFAULT_COUNTER: IntCounter = IntCounter::new("default", "generic counter").unwrap();
    static ref CUSTOM_COUNTER: IntCounter = IntCounter::new("custom", "dedicated counter").unwrap();
}

fn main() {
    let mut buffer = Vec::<u8>::new();
    
    ///////////Default Registry///////////
    //1a. Create default Registry. This is a structure where Prometheus collectors will register for collecting metrics
    let default_registry = prometheus::default_registry();
    
    //1b. Register Collector to registry, Collector will do metric collection
    default_registry.register(Box::new(DEFAULT_COUNTER.clone())).unwrap();
    DEFAULT_COUNTER.inc();
    assert_eq!(DEFAULT_COUNTER.get(), 1);

    //1c. gather(): Will return structure of metrices called MetricFamily
    let metric_family:vec<MetricFamily> = prometheus::gather();

    //1d. encoder: Encodes metric families into an underlying wire protocol using encode()
    let encoder = prometheus::TextEncoder::new();
    encoder.encode(&metric_family, &mut buffer).unwrap();
    println!("## Default registry");
    println!("{}", String::from_utf8(buffer.clone()).unwrap());


    ///////////Custom Registry//////////////////
    //2a. Create a hash_map
    let mut hm = HashMap::new();
    hm.insert("mykey".to_string(), "myvalue".to_string());

    //2b. Create custom registry
    let custom_registry = Registry::new_custom(Some("myprefix".to_string()), Some(hm)).unwrap();

    custom_registry.register(Box::new(CUSTOM_COUNTER.clone())).unwrap();
    CUSTOM_COUNTER.inc_by(42);
    assert_eq!(CUSTOM_COUNTER.get(), 42);

    //2c. Print metrics for the custom registry.
    let mut buffer = Vec::<u8>::new();

    let custom_family = custom_registry.gather();
    encoder
        .encode(&custom_family, &mut buffer)
        .unwrap();
    println!("## Custom registry");
    println!("{}", String::from_utf8(buffer.clone()).unwrap());
}

$ cargo run
## Default registry
# HELP default generic counter
# TYPE defaout counter
default 1

## Custom registry
# HELP custom dedicated counter
# TYPE custom counter
custom{mykey="myvalue"} 42
```

<a name=pm></a>
### 3. [proc_macro crate](https://doc.rust-lang.org/proc_macro/)
- When we write [macros](/Languages/Programming_Languages/Rust/macros) in rust, we need to create a library which exposes macros. This library is provided by proc_macro.
- Due to this library only, we can define `function macros #[proc_macro], attribute macro #[proc_macro_attribute], derive macro#[proc_macro_derive]`.

<a name=pm2></a>
### 4. [proc_macro2 crate](https://doc.rust-lang.org/proc_macro2/)
- Wrapper around [proc_macro crate](#pm).
- Purposes of proc_macro2 crate:
  - _1._ Bring proc_macro functionality to main.rs, build.rs
  - _2. Make procedural macros unit testable:_ proc_macros are not unit testable, proc_macro2 are.

## Packages
1 package is one or more crates that provide a set of functionality. A package contains a [Cargo.toml](../Cargo_BuildSystem) file that describes how to build crates.

<a name=ws></a>
### Workspace
This is set of packages that share the same Cargo.lock and output directory
```rs
$ mkdir add
$ cd add
$ vim Cargo.toml
[workspace]
members = [
    "adder",
]
$ cargo new adder                   //create the adder binary crate by running cargo new within the add directory
  Created binary (application) `adder` package
$ cargo build

Directory structure
├── Cargo.lock
├── Cargo.toml
├── adder
│   ├── Cargo.toml
│   └── src
│       └── main.rs
└── target
```
