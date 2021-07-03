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
    fn add_to_db(&self);
}
pub struct Employee{                          //2. Type "Employee struct"
    pub name:String,
    pub emp_id:u32,
}
pub struct Contractor{                        //3. Type "Contractor struct". See datatypes different from Employee
    pub contractor_name:String,
}

//impl  TRAIT  for   TYPE
impl CompanyDB for Employee{                  //4. Implement trait for Type="Employee struct"
    fn add_to_db(&self) {
        println!("Added {} {}", self.name, self.emp_id);
    }
}
impl CompanyDB for Contractor{                //5. Implement trait for Type="Contractor struct"
    fn add_to_db(&self) {
        println!("Added {}", self.contractor_name);
    }
}

fn main() {
    let amit = Employee {                     //6. Created Employee variable
        name:String::from("Amit"),
        emp_id:34,
    };
    amit.add_to_db()                         //7. Called trait's function for type
}
$ ./test.exe
Added Amit 34
```

<a name=default></a>
### 1.2 Default function definition inside Trait
- To use default implementation of trait just implement type as {}
```rust
//Considering Above Example

pub trait CompanyDB {                         //1. Defined  trait with default definition
    fn add_to_db(&self) {
        println!("Default Implementation");
    }
}
struct cleaning_staff {                       //2. Type "cleaning_staff struct"
    pub cleaner_name:String,
}
impl CompanyDB for cleaning_staff {}          //3. Defined impl to use default impl

fn main() {                                   
  let raj = cleaning_staff {                  //4. Created cleaning_staff variable
      cleaner_name:String::from("Raj") 
  };
  raj.add_to_db();                            //5. Called trait's function for type
}
$ ./test.exe
Default Implementation
```
