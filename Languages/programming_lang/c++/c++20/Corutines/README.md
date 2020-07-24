# COROUTINES
## A. WHAT
- Same as **yield** keyword in `python`.
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
- Functions becomes coroutine if it has any of these 3 keywords in its body `co_await` or `co_yield` or `co_return`.
### 1. co_await()
- co_yield suspends the functions execution, stores that state in the generator<int>
- then returns the value of current through the generator<int>.
```
generator<int> get_integers( int start=0, int step=1 ) {
  for (int current=start; true; current+= step)
    co_yield current;
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
