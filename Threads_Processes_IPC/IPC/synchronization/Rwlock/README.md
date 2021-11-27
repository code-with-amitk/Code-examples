- [Rwlock](#rwl)
- **Implementations**
  - [Rust](#ru)

<a name=rwl></a>
### RWlock
- This type of lock allows a n number of readers(when no writer is inside) or at most one writer at any point in time.
- **Rwlock vs Mutex**
```c
                        rwlock                  |             mutex
------------|-----------------------------------|--------------------- 
Distinction | distinguishes b/w reader & writer | Does not distinguish between readers or writers that acquire the lo
Allowed     | n readers inside                  | Only 1 reader inside CS.            
```
- **Poisoned?** Same as mutex, this becomes poisoned on panic, when lock is held by writer. Panic on reader holding the lock does not poisons it.

## Implementations
### Rust
- Rwlock is often used with [Arc](/Languages/Programming_Languages/Rust/Threading/), because cannot be sent between threads safely bcoz trait `Send` is not implemented for `RwLockReadGuard`.
- Atomicity is provided by RwLocks, once all references to resource are gone(ie its not used by any thread) its automatically deallocates.
- **Example: Thread1 reading, Thread2 writing, Thread3 reading**
```rs
use std::{
    thread,
    sync::{
        RwLock,
        Arc,
    },
};

fn main() {
    let lock = Arc::new(RwLock::new(5));
    let thread1_lock = lock.clone();
    let thread2_lock = lock.clone();
    let thread3_lock = lock.clone();

    let handle1 = thread::spawn(move ||{               //Reader Thread
        if let Ok(r1) = thread1_lock.read(){
            println!("Thread1 read{:?}",*r1);    
        };
    });
    let handle2 = thread::spawn(move ||{                //Writer Thread
        let w1 = thread2_lock.write();
        let mut val = match w1 {
            Ok(v)=>v,
            Err(e)=>{
                println!("{}",e);
                unreachable!()
            }
        };
        *val = 10;
        println!("Thread2 write,read {}",*val);
    });
    let handle3 = thread::spawn(move ||{                //Reader Thread
        let a = thread3_lock.read();
        let r = match a {
            Ok(v)=>v,
            Err(e)=>{
                println!("{}",e);
                unreachable!()
            }
        };
        println!("Thread3 read{}",r);
    });
    handle1.join().expect("Thread1 panics");
    handle2.join().expect("Thread2 panics");
    handle3.join().expect("Thread3 panics");
}

$ cargo run
Thread1 read5
Thread2 write,read 10
Thread3 read10
```
