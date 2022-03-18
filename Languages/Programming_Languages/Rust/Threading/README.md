- [Arc(Atomically Reference Counted)](#arc)
  - [`Rc<T>` vs `Arc<T>`](#vs)
- **Code**
  - [1. Passing mutable Reference to thread](#c1)

<a name=arc></a>
### `Arc<T>` / Atomically Reference Counted
- [Meaning of Atomic.](/Threads_Processes_IPC/Terms) Arc is [Reference counting Smart pointer](/Languages/Programming_Languages/Rust/Smart_Pointers/).
- Structue T is allocated on Heap, `Arc<T>` provides shared ownership of a value of type T.
- **clone() on Arc** produces a new Arc instance, which points to the same allocation on the heap as the source Arc, only reference count is increased.
- When the last Arc pointer to a given allocation is destroyed, the value stored in that allocation (often referred to as “inner value”) is also dropped.
- **Mutable References** are not allowed inside Arc. Use `Arc<Mutex<Value>>` or `Arc<RwLock<Value>>`, Atomic types inside Arc if needed mutable references.
  - This is just wrapping Mutex inside Arc. We know in [Rust value & mutex are not seperate](/Threads_Processes_IPC/IPC/synchronization/Mutex#rs)

<a name=vs></a>
#### [`Rc<T>`](/Languages/Programming_Languages/Rust/Smart_Pointers/README.md#rc) vs `Arc<T>`
Both are Reference counting Smart Pointers.
```rs
                        RC<T>                                Arc<T>
---------------|-----------------------------|---------------------------------
What           |    Not Thread Safe          |   Thread Safe
Internally     |                             |   Uses atomic operations for reference counting
Memory overhead|    less                     |   More
```

### Code
<a name=c1></a>
#### Passing mutable Reference to thread
```rs
//main.rs
use std::sync{Arc, Mutex}
use tokio;

pub struct Employee {
  age: i32,
}

impl Employee {
  pub fn new() -> Self {
    Employee {
      age: 40,
    }
  }
}

pub async fn thread1(emp: Arc<Mutex<&mut Employee>>) {                          //6. Collected Arc<Mutex<Employee>>
  let a = emp.lock().unwrap();                                                  //7. locked mutex to access value inside it
  println!("a={}",a);                                                           //40
}

pub async fn fun(emp: &mut Employee) {
  let arc_emp:Arc<Mutex<&mut Employee>> = Arc::new(Mutex::new(emp.clone()));    //3. Created Arc<Mutex> clone(). ie it points to original object
  let handle = tokio::spawn(async {                                             //4. Created Green Thread(User level Thread)
    thread1 (arc_emp).await;                                                    //5. passed Arc<Mutex<Employee>> to thread.
  });                                                                                Note we are not passing Arc<Mutex<&mut Employee>>
  let out = handle.await.unwrap();
  
  emp.age = 90;                                                                 //8. Original value inside struct is changed
  
  let arc_emp1:Arc<Mutex<&mut Employee>> = Arc::new(Mutex::new(emp.clone()));    //9. Created new Arc reference
  let handle1 = tokio::spawn(async {
    thread1 (arc_emp1).await;
  }
  let out1 = handle1.await.unwrap();                                            //10. a=90. ie Changed value is accessed using threads
}

#[tokio::main]
pub async fn main(){                  //All tokio functions should be async
  let mut emp = Employee new();       //1. Created struct
  fun (emp);                          //2. Passed mutable reference to function
}
```
