- [Rwlock](#rwl)
- **Implementations**
  - [Rust](#ru)
    - [1. Storing u32 in `Arc<RwLock>`](#e1)
    - [2. Storing String, `Option<String>` in `Arc<RwLock>`](#e2)

<a name=rwl></a>
### RWlock
- Allows a n readers(when no writer is inside) or at most one writer at any point in time.
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
<a name=e1></a>
#### 1. Storing u32 in `Arc<RwLock>`, Reading writing using Threads
```rs
//Example: Thread1 reading, Thread2 writing, Thread3 reading
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

<a name=e2></a>
#### 2. Storing String in `Arc<RwLock>`
```rs
pub struct Test {
    ip: Arc<RwLock<String>>,
    opt_ip: Arc<RwLock<Option<String>>>,
}
pub static TEST: Lazy<Arc<Test>> = Lazy::new(|| Arc::new(Test::create()));
impl Test {
    // Create default instance.
    fn create() -> Self {
        Self {
            ip: Arc::new(RwLock::new(String::new())),
            opt_ip: Arc::new(RwLock::new(None)),
        }
    }
}
async fn fun1() {
//////////Write, Read String//////////////////////
  match TEST.ip.write() {                   //Writing
            Ok(mut token_guard) => {
            *token_guard = format!("{}", ip);
            println!("ip stored");
        }
        Err(e) => {
            println!("failed to acquire token lock, error {}", e);
        }
  }
  
  let token_str = match test.ip.read() {                  //Reading
    Ok(token) => token.to_string(),
    Err(e) => {
      println!("{} failed to lock token {:?}", FN_NAME, e);
      return;
    }
  };
  
  ////////Write, Read Option<String>//////////////////
  let mut wg = match TEST.opt_ip.write() {
    Ok(wguard) => wguard,
    Err(err) => {
      return Err(format!("failed to get write lock for opt_ip, error {:?}",err));
    }
  };
  *wg = Some("test".to_string());
  
  
}
```
