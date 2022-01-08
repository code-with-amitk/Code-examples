- [Lazy](#lazy)
- [RWLock](#rwl)
- [self & Self](#self)

<a name=lazy></a>
### Lazy
- Allows you to initialize static variables at runtime. 

<a name=rwl></a>
### [RWlock](/Threads_Processes_IPC/IPC/synchronization)

### Self, self
#### Self
Self is the type of the current object. It may appear either in a trait or an impl
```rs
trait Clone {
    fn clone(&self) -> Self;
}
```
#### self
- self is first argument of a method in triat or impl.
- There is no implicit this argument passed to a type's methods: you have to explicitly pass the "current object" as a method parameter
```rs
impl MyType {
    fn doit(&self, a: u32) { ... }
}
```
