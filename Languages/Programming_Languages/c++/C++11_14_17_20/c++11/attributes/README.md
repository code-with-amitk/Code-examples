## `[[Attributes]] C++11 onwards` OR `__attributes((..)) GNU C`
- **What** 
  - These are basically preprocessor macros introduced after c++11.
  - Allows user to pass information to complier for various purposes. Examples:
    - Code optimization
    - enforce constraints(conditions) on code
    - do some specific code generation
  - Compilers ignore attribute values they don't recognize. This means you cannot define your own attributes.
  - **VALUES** These attributes are given standard values which can be expanded using `__has_cpp_attribute( attribute-token ) C++20`. if you observe these values are year-month in which attribute is added to working draft.

| attribute-token | Attribute | Value | Standard |
| --- | --- | --- | --- |
| carries_dependency | `[[carries_dependency]]` | 200809L |	(C++11) |
| deprecated | `[[deprecated]]` | 201309L | (C++14) |
| fallthrough | `[[fallthrough]]` | 201603L | (C++17) |
| likely | `[[likely]]` | 201803L | (C++20) |
| maybe_unused | `[[maybe_unused]]` | 201603L | (C++17) |
| no_unique_address | `[[no_unique_address]]` | 201803L	| (C++20) |
| nodiscard |	`[[nodiscard]]` | 201603L, 201907L | (C++17), (C++20) |
| noreturn | `[[noreturn]]` | 200809L | (C++11) |
| unlikely | `[[unlikely]]` | 201803L |	(C++20) |
  
### Types of attributes
#### 1. `[[noreturn]]`
  - Indicates function will never returns to caller. This means function either `throw an exception` or `call std::terminate`.
  - The behavior is undefined if the function with this attribute actually returns.
  - **Advantage** Complier will not do clean up tasks(pushing rbp etc) and can optimize the function's code.
```cpp
[[noreturn]] void fun(std::string message) {
    cout<<message;
    if (THROW_EXCEPTION_ON_ASSERT)
        throw AssertException(std::move(message));
    terminate();
}
```

#### 2. `[[carries_dependency]]`
Tells complier to skip unnecessary memory fence instructions for this function as it will consumes/releases memory being part atomic operation.

  3. `[[deprecated]]C++14  [[deprecated("reason")]](C++14)`
  4. `[[fallthrough]]` only with switch
  5. `[[nodiscard]](C++17)  [[nodiscard("reason")]](C++20)`
  6. `[[maybe_unused]](C++17)`
  7. `[[likely]](C++20)  [[unlikely]](C++20)`
  8. `[[no_unique_address]](since C++20)`
  9. `[[optimize_for_synchronized]]`
  
#### Added support in C++17
`[[ using attribute-namespace : attribute-list ]]		(since C++17)`
  -  attribute-list is comma seperated 0 or more attributes.
```
[[using gnu : const, always_inline, hot]] [[nodiscard]]
int main(){
  cout<<"Hello";
}
```

