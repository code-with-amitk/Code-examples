- [1. What is Trait](#what)
  - [1.1 Function declared in trait](#declare)
  - [1.2 1.2 Default function definition inside Trait](#default)

<a name=what></a>
## 1. Trait = virtual Function (Not pure virtual)
- Similar to interfaces in other languages, we can declare or define function in trait.
- These functions can be implemented on type, ie overridden.

<a name=declare></a>
### 1.1 Function declared in trait
- Function is declared in trait, for different types function is overridden
```rust
pub trait CompanyDB {                         //1. Trait declaring a function taking self, returning bool
    fn add_to_db(&self) -> bool;
}
pub struct Employee{                          //2. Type "Employee struct"
    pub name:String,
    pub emp_id:u32,
}
pub struct Contractor{                        //3. Type "Contractor struct"
    pub name:String,
    pub contract_id:u32,
}

//impl  TRAIT  for   TYPE
impl CompanyDB for Employee{                 //4. Implement trait for Type="Employee struct"
    fn add_to_db(&self) -> bool {
        println!("{} {}", self.name, self.emp_id);
        true
    }
}
impl CompanyDB for Contractor{               //5. Implement trait for Type="Contractor struct"
    fn add_to_db(&self) -> bool {
        println!("{} {}", self.name, self.contract_id);
        true
    }
}

fn main() {
    let amit = Employee {                    //6. Created Employee variable
        name:String::from("Amit"),
        emp_id:34,
    };
    if amit.add_to_db() == true{             //7. Called trait's function for type
        println!("Added")
    }
    else{
        println!("Failed")
    }
}
$ ./test.exe
Amit 34
Added
```

<a name=default></a>
### 1.2 Default function definition inside Trait
- To use default implementation of trait just implement type as {}
```rust
pub trait CompanyDB {
    fn add_to_db(&self) -> bool {
        println!("Default");
        false
    }
}
impl CompanyDB for CleaningStaff {
}
```
