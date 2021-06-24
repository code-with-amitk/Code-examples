## struct

- [Defining struct](#Defining_struct)
- [Initialize struct](#initialize)
- [Mutable struct](#mutable)

<a name=Defining_struct></a>
## Defining struct
- name 1st followed by type
```rust
struct Employee {
  name: String,
  email: String,
  salary: f64,
  empID: u32,
}
```

<a name=initialize></a>
## Initialize struct
```rust
let amit = Employee {
  name: String::from("Amit"),
  email: String::from("amit@test.com"),
  salary: 12.00
  empID: 52
}
```

<a name=mutable></a>
## Mutable struct
- immutable: which cannot be changed.
- Means struct whose values can be changed.
- Entire struct has to be mutable, Rust does not allow only some feilds to be mutable.
```rust
let mut champ = Employee {
  name: String::from("Champ")
  email: String::from("champ@gmail.com")
  salary: 50.00
  empID: 56
};
champ.name = String::from("Big Champ");     //Changing name of struct
```


- [Initializing struct](Initializing_struct.md)
- [Changing struct feild in Mutable struct:](Mutable_Struct)
- [Function returning a struct instance](/Languages/Programming_Languages/Rust/Functions/Return_From_Function)
- [Creating Instance2 from Instance1](Creating_Instance2_from_Instance1.md)
- [Printing struct variables using println](Dumping_Struct_Variables)
