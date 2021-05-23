## Struct
- Defining struct
```rust
struct Employee {
  name: String,
  email: String,
  salary: f64,
  empID: u32,
}
```
- Initializing struct
```rust
let amit = Employee {
  name: String::from("Amit"),
  email: String::from("amit@test.com"),
  salary: 12.00
  empID: 52
}
```
- Changing value in Mutable struct. Entire struct has to be mutable, Rust does not allow only some feilds to be mutable. Immutable means cannot change.
```rust
let mut champ = Employee {
  name: String::from("Champ")
  email: String::from("champ@gmail.com")
  salary: 50.00
  empID: 56
};
champ.name = String::from("Big Champ");
```
