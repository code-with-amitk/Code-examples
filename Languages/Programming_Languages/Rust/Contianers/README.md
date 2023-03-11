Containers
- [std::cell](#sc)
- [std::cell::RefCell](#rc)

## Containers
<a name=sc></a>
### std::cell
Shareable mutable containers

<a name=rc></a>
### Struct std::cell::RefCell (NOT Thread-safe)
- type which provides sharable, mutable ownership over its contents, but enforces the borrow rules at runtime instead of compile time.
- RefCell is useful when you need to mutate data that is shared between multiple parts of your code.
- RefCell has some performance overhead compared to direct mutable borrowing, due to the runtime borrow checking. (Since compile time is faster)
- To make it thread-safe (Use it with Arc)
