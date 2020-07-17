## `[[noreturn]] C++` OR 
  - Indicates function will never returns to caller. This means function either `throw an exception` or `call std::terminate`.
  - The behavior is undefined if the function with this attribute actually returns.
  - **Advantage** Complier will not do clean up tasks(pushing rbp etc) and can optimize the function's code.
  
**C++ Example**
```
[[noreturn]] void fun(std::string message) {
    cout<<message;
    if (THROW_EXCEPTION_ON_ASSERT)
        throw AssertException(std::move(message));
    terminate();
}
```
