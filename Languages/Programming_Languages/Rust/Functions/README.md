**Function**
- [Returning from Function](#return)
  - [1. Function returning a value](#return_val)
  - [2. Function returning struct](#return_struct)
  - [3. Function Taking struct as argument](#take_struct)
- [Rust defined Functions, Inbuilt Functions](Inbuilt_Functions)
- [Closure / Lambda](#closure)
  - [Why](#why)
  - Properties
    - [Curly brackets are optional](#op)
    - [Types are locked](#lock)
  - [Closure inside struct](#st)

<a name=fun></a>
## Functions
- Function definition starts with fn. Coding convention followed in Rust is snake case ie underscores.
- See another_fun() is defined after main() that means only function definition is required, place(above or below main()) does not matter.
- Type annotation is mandatory.
```rs
fn main() {
  println!("Main\n");
  another_fun (5, 6);
}
fn another_fun(x:i32, y:i32){               //Type annotation mandatory
  println!("Another_fun x: {}", x);
  println!("Another_fun y: {}", y);
}
```

<a name=return></a>
## Returning from Function
- _a._ Type of return value is specified with `->`
- _b._ Last statement in function(without semicolon) is the return value.

<a name=return_val></a>
#### 1. Function returning a value
```rs
fn main() {
  let y:i32 = fun (5);
  println!("fun y: {}", y);
}
fn fun(x:i32) -> i32{              //a 
  println!("fun x: {}", x);
  6                                 //b
}
```

<a name=return_struct></a>
#### 2. Function returning struct
- [How Struct is defined, initialized in rust](/Languages/Programming_Languages/Rust)
```rs
struct User {
    name: String,
    id:i32,
    active:bool
}

fn main() {
    let u = fun(String::from("Amit"),32);
    println!("{}",u.name);
}

fn fun(name:String, id:i32) -> User {
    User {
        name:name,
        id:id,
        active:true
    }
}
```
- **Writing struct in shorthand:** When function's parameter and struct name are same. We can skip rewriting the name.
```rust
fn fun(name:String, id:i32) -> User {
    User {
        name,                             //Rewriting of name, id is skipped
        id,
        active:true
    }
}
```

<a name=take_struct></a>
#### 3. Function Taking struct as argument
- *1.* Passing Structure as Reference ie [BORROWING not taking ownership](/Languages/Programming_Languages/Rust)
- *2.* Accepting function as Reference
```rust
struct dimen {
    len:u32,
    width:u32
}

fn main() {
    let a = dimen {
        len:10,
        width:20
    };
    println!("{}",area(&a));    //1
}

fn area(b:&dimen) -> u32 {      //2
    b.len*b.width
}
```

<a name=closure></a>
## Closure / [Lambda Function](/Languages/Programming_Languages/c++/C++11_14_17_20/c++11/Lambda_Expression)
- Anonymous functions(ie with no name) which can be saved in a variable or and then this variable can be passed as argument to other functions.
- Unlike normal functions, [Type annotation](#fun) of parameters is not required. complier can infer on his own.

<a name=why></a>
#### Why Closure
If some logic/function need to be called n times, then n function call is not good(stack creation/destroy). Call function only once and Store result in variable.
```rs
fn main() {
    let a = 4;
    let b = 5;
    let var = |a,b| {       //Closure stored in variable var. a,b are parameters to closure
        a+b
    };                      //semicolon neeced to complete let statement.
    println!("{}", var(a,b));
}
$ cargo run
9
```

### Properties of closure
<a name=op></a>
#### Curly brackets are optional
```rs
fn main() {
    let a = 4;
    let b = 5;
    let var = |a,b| a+b;    //Closure returning sum
    println!("{}", var(a,b));
}
```

<a name=lock></a>
#### Types are locked
First time we call var with the String, compiler infers the type of x, return type(as string) and locks into closure. We get type error if we try to use a different type on same closure.
```rs
fn main() {
    let var = |x| x;

    let s = var(String::from("hello"));
    let n = var(5);                    //Compilation error. Type error
}
```

<a name=st></a>
### Closure inside struct
To store closure inside struct, we need to:
1. Define type of closure(because anything to be stored inside struct has to have type). Hence struct is implemented as Generc (T).
2. And Closure has to implement any of these [traits Fn, FnMut, or FnOnce](/Languages/Programming_Languages/Rust)
  - Add return type to trait. In this case closure has parameter of u32 and returns u32.

Implementing trait for closure:

3. [Trait](/Languages/Programming_Languages/Rust) is implemented as Generic
4. Instead of calling the closure directly, we will call fun(), This method checks whether we already have a return value in self.ret_value in a Some; if we do, we return the value within the Some without executing the closure again.
5. If ret_value does not have a value(None) then we will call closure_fun() and save result in ret_value.
```rs
struct test<T>              //1
where
    T: Fn(u32) -> u32,      //2
{
    closure_fun: T,             //Closure
    ret_value: Option<u32>,     //Return value of closure
}

impl<T> test<T>                     //3
where 
    T: Fn(u32) -> u32,
{
    fn closure_fun(var:u32){
        var
    }
    
    fn fun(&mut self, var:u32) -> u32 {       
        match self.ret_value {
            Some(v) => v,                           //4
            None => {                               //5
                let v = self.closure_fun(arg);
                self.ret_value = Some(v);
                v
            }
        }
    }
}
```
