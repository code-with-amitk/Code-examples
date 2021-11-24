- [Arc(Atomically Reference Counted)](#arc)
- [`Rc<T>` vs `Arc<T>`](#vs)

<a name=arc></a>
### `Arc<T>` / Atomically Reference Counted
- [What is Atomic](/Threads_Processes_IPC/Terms)
```rs
let mut a_atm:AtomicU32 = Atomic:U32::new(100);          //Create and Initialize Atomic variable(a_atm)
let mut b_atm:AtomicU32 = Atomic:U32::new(5);
```
- This is [reference counting](/Languages/Programming_Languages/Rust/Smart_Pointers/) pointer.
- Structue T is allocated on Heap, `Arc<T>` provides shared ownership of a value of type T.
- **clone() on Arc** produces a new Arc instance, which points to the same allocation on the heap as the source Arc, only reference count is increased.
- When the last Arc pointer to a given allocation is destroyed, the value stored in that allocation (often referred to as “inner value”) is also dropped.
- **Mutable References** are not allowed inside Arc. Use Mutex, RwLock, Atomic types inside Arc if needed mutable references.

<a name=vs></a>
#### `Rc<T>` vs `Arc<T>`
Both are Reference counting Smart Pointers.
```rs
                        RC<T>                                Arc<T>
---------------|-----------------------------|---------------------------------
What           |    Not Thread Safe          |   Thread Safe
Internally     |                             |   Uses atomic operations for reference counting
Memory overhead|    less                     |   More
```
