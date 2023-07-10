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
Self is the type of the current object.
```rs
struct test {};
impl test {
    fn new() -> Self {    /// This function will return object of type=test
        test {
        }
    }
}
```
#### self
- self is first argument of a method that represents instance of struct or enum.
- Same as this in C++.
```rs
struct test{ };
impl test {
    /// self indicates it takes address of struct object on which method is called.
    fn fun (&self) {
    }
}
```
