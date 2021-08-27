**Generic Types**
- [Generic Structure & Generic impl block](#g)
- [Monomorphization / Generic Internal Implementation](#i)


## Generic Type
Same as templates, used to handle the duplicate data types,code.

<a name=g></a>
## Generic Structure & Generic impl block
```rs
#[derive(Debug)]
struct  point<T,U> {
    x:T,
    y:U,
}
impl<T,U> point<T,U> {    //<> shows point is a Generic type rather than a concrete type.
  fn fun (self) -> T {
    self.x
  }
}

impl<f32,i32> point<f32,i32>{   //Concreate type is also valid
    fn fun(self)->f32{
        self.x
    }
}

fn main() {
    let test = point  {
        x:10,
        y:'c',
    };
    println!("{:?}",test.fun());
}
# .\test.exe
10
```

<a name=i></a>
## Generic Internal Implementation
- Rust replaces generic code into specific-type code by filling in the concrete types that are used when compiled. This is called monomorphization.
- How `Option<T> enum` is implemented?
```rs
let integer = Some(5);
let float = Some(5.0);

//During compilation rust reads the values that have been used in Option<T> instances and finds 2 kinds of Option<T>: 
one is i32 
other is f64. 
As such, it expands the generic definition of Option<T> into Option_i32 and Option_f64.

enum Option_i32 {
    Some(i32),
    None,
}

enum Option_f64 {
    Some(f64),
    None,
}
```
