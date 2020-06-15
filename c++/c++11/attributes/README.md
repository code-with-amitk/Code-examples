## Attributes
  - **What**
    - Introduced in C++11, these are Feature of C++ with which programmer can provide additional information to the compiler. Eg:
      1. enforce constraints(conditions) on code
      2. optimise certain pieces of code
      3. do some specific code generation
      
### A. Types of attributes
#### A1. `[[noreturn]]`
  - Indicates function does not return to caller either executing a return statement, or by reaching the end if it's body
  - Example-1
    - This function will always either throw an exception or call std::terminate, so it is a good candidate for `[[noreturn]]`
```
[[noreturn]] void fun(std::string message) {
    cout<<message;
    if (THROW_EXCEPTION_ON_ASSERT)
        throw AssertException(std::move(message));
    terminate();
}
```
