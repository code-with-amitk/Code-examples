- value_of()

### [value_of()](https://docs.rs/clap/2.31.2/clap/struct.ArgMatches.html#method.value_of)
Get value of positional argument (i.e. an argument that takes an additional value at runtime). If the option wasn't present at runtime it returns None.
```rs
let m = App::new("myapp").arg(Arg::with_name("output").takes_value(true))
    .get_matches_from(vec!["myapp", "something"]);

assert_eq!(m.value_of("output"), Some("something"));
```
