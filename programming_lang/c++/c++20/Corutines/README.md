# COROUTINES
## A. WHAT
- This is **a stackless function** that can suspend execution to be resumed later. Resumption information is stored seperately from stack.
- **Restrictions**
  1. ***Coroutines cannot Use***
     - Variadic arguments
     - plain return statements (should use co_return)
     - Constexpr functions, constructors, destructors
     - main() function cannot be coroutines.
- **Internal Implementation**
  1. ***Promise Object*** This created by courtine internally, croutine submits its *result* or *exception* through it.
  2. ***Coroutine handle*** Manipulated from outside of couroutine, used to resume/destroy execution of coroutine.
  3. ***Coroutine state*** This is another Object containing
     - Promise object
     - parameters(all copied by value)
     - current suspension point
     - local variables
     
## B. APPLICATIONS
1. Asynchronous code execution. Examples
   - Handle non-blocking I/O without explicit callbacks.
   - Algorithms on lazy-computed infinite sequences

## C. CREATING COROUTINES
- Functions becomes coroutine if it does any of following
### 1. co_await()
- co_await operator to suspend execution until resumed
```
task<> tcp_echo_server() {
  char data[1024];
  for (;;) {
    size_t n = co_await socket.async_read_some(buffer(data));
    co_await async_write(socket, buffer(data, n));
  }
}
```
### 2. co_yeild()
- co_yield to suspend execution returning a value
```
generator<int> iota(int n = 0) {
  while(true)
    co_yield n++;
}
```
### 3. co_return()
- co_return to complete execution returning a value
```
lazy<int> f() {
  co_return 7;
}
```
