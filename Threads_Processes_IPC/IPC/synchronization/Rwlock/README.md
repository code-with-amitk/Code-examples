- [Rwlock](#rwl)
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

### Implementations
#### Rust
```rs
std::sync::RwLock
```
