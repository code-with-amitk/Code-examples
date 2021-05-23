## Mutable Struct
- Means struct whose values can be changed.
- Entire struct has to be mutable, Rust does not allow only some feilds to be mutable. Immutable means cannot change.
```rust
let mut champ = Employee {
  name: String::from("Champ")
  email: String::from("champ@gmail.com")
  salary: 50.00
  empID: 56
};
champ.name = String::from("Big Champ");     //Changing name of struct
```
