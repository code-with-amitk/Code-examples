**Trait**
- Functions in trait
  - [Function Declaration in Trait](#dec)
  - [Function Definition in Trait](#def)
- [Passing Triat as argument to function](#arg)
- **Trait Bound**
  - _1._ Multiple Trait Bounds //Friend Function
      - [1.1 Using +](#usingplus)
      - [1.2 Using where clause](#usingplus)
- **Returning Triats from Function**
  - [1. Function returning trait](#ret-t)
  - [2. Function cannot implement 2 traits internally](#invalid-t)


## Trait
Abstract interface/class having Virtual Functions(not pure Virtual). We declare or define function in trait. These functions are implemented(overridden) on type.

## Functions in trait
<a name=dec></a>
#### Function declaration in Trait
1st function is declared inside trait, Then function is overridden for different types. Eg: add_to_db() function is overridden for Employee, Contractor Type
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
#### Function definition in Trait / Default Implementation
To use default implementation of trait just implement type as {}
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

<a name=arg></a>
## Passing Triat as argument to function
Above we have implemented a Trait(called CompanyDB), we can pass trait as parameter to function.
```rs
pub fn test (param: &impl CompanyDB) {          //1. Function taking trait as parameter          //1.2.A
  println!("{}", param.add_to_db());            //2. Using parameter we can call function declared/defined in trait
}

fn main() {
  let amit = Employee {                         //3. Created "Employee struct" Type object.
    name:String::from("Amit"),
    emp_id:34,  
  };
  test (&amit);                                 //4. Called Function, passed instance of Type implementing triat
}
```

## Trait Bound
Above function(1.2.A) can be written as below, also called Trait bound.
```rs
         //<T: Trait> (parameter: &T)
pub fn test<T: CompanyDB> (param: &T) {         //Trait Bound
  ..
}
```

### 1. Multiple Trait Bounds 
<a name=usingplus></a>
#### 1.1 Using +   //Friend Function
There can be a function which takes 2 or more traits(virtual function).
```rs
pub fn test<T: Trait1 + Trait2> (param: &T) {
OR
pub fn test (param: &(impl Trait1 + Trait2) {
```
<a name=usingplus></a>
#### 1.2 Using where clause   //Friend Function
```rs
pub fn test<T: Trait1 + Triat2, U: Triat2 + Triat2>(t: &T, u: &U) -> i32 {
OR
pub fn test<T, U>(t: &T, u: &U) -> i32
    where T: Triat2 + Triat2
          U: Triat2 + Triat3
{
```

## Returning Triats from Function
<a name=ret-t></a>
#### Function returning trait
- Function which returns (impl Trait) returns any of type that implements the trait.
```rust
//This Function can return "Employee Type" or "Contractor Type" or "cleaning_staff Type". see above
                //impl Trait
pub fn fun ( ) -> impl CompanyDB {      
  Employee {                            //Created "Employee struct" Type object.
    name:String::from("Amit"),
    emp_id:34,  
  };
}
```
<a name=invalid-t></a>
#### Function cannot implement 2 traits internally
- Returning either or trait(ie Employee or contractor) is not supported by complier.
```rust
pub fn fun (test:bool) -> impl CompanyDB {      
  if test {
    Employee {
      name:String::from("Amit"),
      emp_id:34,  
    }
  } else {
    Contractor {
      name:String::from("Rishu"),
    }
  }
}
```
