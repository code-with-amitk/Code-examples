- [1. What is Trait](#what)
  - [1.1 Function in trait](#fun)
    - [1.1.1 Function declaration in Trait](#dec)
    - [1.1.2 Function definition in Trait](#def)

<a name=what></a>
## 1. Trait = virtual Function (Not pure virtual)
- Similar to interfaces in other languages, we can declare or define function in trait.
- These functions can be implemented on type, ie overridden.

<a name=fun></a>
### 1.1 Functions in trait

<a name=dec></a>
#### 1.1.1 Function declaration in Trait
- 1st function is declared inside trait, Then function is overridden for different types. Eg: add_to_db() function is overridden for Employee, Contractor Type
```rust
pub trait CompanyDB {                         //1. Declared a function inside trait
    fn add_to_db(&self);
}
pub struct Employee{                          //2. Declared a Type "Employee struct"
    pub name:String,
    pub emp_id:u32,
}
pub struct Contractor{                        //3. Declared Type "Contractor struct".
    pub contractor_name:String,
}

//impl  TRAIT  for   TYPE
impl CompanyDB for Employee{                  //4. Implemented trait/Overridden for Type="Employee struct"
    fn add_to_db(&self) {
        println!("Added {} {}", self.name, self.emp_id);
    }
}
impl CompanyDB for Contractor{                //5. Implemented trait/Overrideen for Type="Contractor struct"
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

<a name=def></a>
#### 1.1.2 Function definition in Trait / Default Implementation
- To use default implementation of trait just implement type as {}
```rust
//Considering Above Example

pub trait CompanyDB {                         //1. Function definition is provided in trait
    fn add_to_db(&self) {
        println!("Default Implementation");
    }
}
struct cleaning_staff {                       //2. Declared Type "cleaning_staff struct"
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
