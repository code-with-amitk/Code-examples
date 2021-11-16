- [Atomic](#at)
- [Arc(Atomically Reference Counted)](#arc)

<a name=at></a>
### Atomic
- [What is Atomic](/Threads_Processes_IPC/Terms)
```rs
let mut a_atm:AtomicU32 = Atomic:U32::new(100);          //Create and Initialize Atomic variable(a_atm)
let mut b_atm:AtomicU32 = Atomic:U32::new(5);
```

<a name=arc></a>
### `Arc<T>` / Atomically Reference Counted
- This is [reference counting](/Languages/Programming_Languages/Rust/Smart_Pointers/) pointer.
- Structue T is allocated on Heap, `Arc<T>` provides shared ownership of a value of type T.
- clone on Arc produces a new Arc instance, which points to the same allocation on the heap as the source Arc, only reference count is increased.
```rs
pub struct Arc<T> 
where
    T: ?Sized, 
 { /* fields omitted */ }
```

#### `Rc<T>` vs `Arc<T>`
```rs
//Both are Reference counting Smart Pointers.

                        RC<T>                                Arc<T>
---------------|-----------------------------|---------------------------------
What           |    Not Thread Safe          |   Thread Safe
Internally     |                             | Uses atomic operations for reference counting
Memory overhead|    less                     | More
```
