- **Trait**
  - [Declaration, Definition](#dec)
  - [Function with default implemenration](#def)
  - [Function cannot implement 2 traits internally](#invalid-t)
  - Passing, Returning Triats
    - [Trait as Argument to function](#arg)
    - [Returning Trait from function](#r)
- **Trait Bound**
  - _1._ Multiple Trait Bounds //Friend Function
      - [1.1 Using +](#usingplus)
      - [1.2 Using where clause](#usingplus)
- **Traits provided by Standard library**
  - Fn, FnMut, or FnOnce, Dref
  - [Default](#di)
  - [Drop](#dr)
  - [Future](#fu)


## Trait
Interface/class in Rust(declared with keyword trait) having Virtual Functions(not pure Virtual) declared or defined inside it. These functions are implemented(overridden) on type.

<a name=dec></a>
### Trait Declaration & Definition
- **1. Declaration:** Trait declared having functions.
- **2. Definition:** Trait is implemented for particular types. Eg: add_to_db() function is overridden for Employee, Contractor Type.
```rust
pub struct Employee{                          //Declared "struct Employee"
    pub name:String,
    pub emp_id:u32,
}

pub struct Contractor{                        //Declared "struct Contractor".
    pub contractor_name:String,
}

pub trait CompanyDB {                         //1. Trait Declaration
    fn add_to_db(&self);
}

//impl  TRAIT  for   TYPE
impl CompanyDB for Employee{                  //2. Trait Definition. Implemented trait/Overridden for Type="Employee struct"
    fn add_to_db(&self) {
        println!("Added {} {}", self.name, self.emp_id);
    }
}
impl CompanyDB for Contractor{                //Trait Definition. Implemented trait/Overrideen for Type="Contractor struct"
    fn add_to_db(&self) {
        println!("Added {}", self.contractor_name);
    }
}

fn main() {
    let amit = Employee {                     //Created Employee variable
        name:String::from("Amit"),
        emp_id:34,
    };
    amit.add_to_db()                         //Called trait's function for type
}
$ ./test.exe
Added Amit 34
```

<a name=def></a>
#### Function with Default Implementation in Trait
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

<a name=invalid-t></a>
#### Function cannot implement 2 traits internally
Returning either or trait(ie Employee or contractor) is not supported by complier.
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

### Passing,Returning Triat 
<a name=arg></a>
#### Trait as argument to function
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
<a name=r></a>
#### Returning Trait from function
Function which returns (impl Trait) returns any of type that implements the trait.
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

## Traits provided by Standard Library
- **[Dref trait](/Languages/Programming_Languages/Rust/Smart_Pointers)**

<a name=di></a>
#### Default Trait
Used to give default value.
- **Default value by Rust System**
```rs
#[derive(Default)]              <<<<<<<<<This asks Rust to provide Default implementation
pub struct Test {
    a : i32,
}
fn main() {
    let test1: Test = Default::default();
    println!("{}",test1.a);
}
$ cargo run
0                       //0 is initialized by rust system
```
- **Default value by user:** User need to implement default trait.
```rs
pub struct test {
    a : i32,
}
impl Default for test{            //Implemented trait for type "struct test"
    fn default() -> Self {
        Self {
            a: 48,
        }
    }
}
fn main() {
    let test1: Test = Default::default();
    println!("{}",test1.a);             //48
}
```

<a name=dr></a>
#### Drop trait
Allows you to customize the code that is run when an instance of the smart pointer goes out of scope.

<a name=fu></a>
#### Future Trait
**Future?** is a "asynchronous value" that may not have finished computing yet. Thread waits on future to become available. These are similar to [epoll()](/Networking/OSI-Layers/Layer-4/Socket_Programming/APIs_Structures/APIs/Polling_APIs/), not smilar to poll() or select().
```rs
pub trait Future {
    //The type of value produced on completion.
    type Output;                 
    
    /*Description:
       This method resolves future into a final value. This is aync method does not block if value is not ready
      Returns:
       Poll::Pending if the future is not ready. 
       Poll::Ready(val) with the result val of this future if it finished successfully.
     */
    fn poll(self: Pin<&mut Self>, cx: &mut Context<'_>) -> Poll<Self::Output>;
}
```
