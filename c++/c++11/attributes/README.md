## `[[Attributes]] C++11 onwards` OR `__attributes((..)) GNU C`
- **What** 
  - Allows user to pass information to complier for various purposes. Examples:
    - Code optimization
    - enforce constraints(conditions) on code
    - do some specific code generation
  - Compilers ignore attribute values they don't recognize. This means you cannot define your own attributes
  
### Types of attributes
  1. `[[noreturn]]`
  2. `[[carries_dependency]]`
  3. `[[deprecated]]C++14  [[deprecated("reason")]](C++14)`
  4. `[[fallthrough]]` only with switch
  5. `[[nodiscard]](C++17)  [[nodiscard("reason")]](C++20)`
  6. `[[maybe_unused]](C++17)`
  7. `[[likely]](C++20)  [[unlikely]](C++20)`
  8. `[[no_unique_address]](since C++20)`

