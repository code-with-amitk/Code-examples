## Attributes
- **What** 
  - Introduced in C++11, these are Feature of C++ with which programmer can provide additional information to the compiler. 
  - Compilers ignore attribute values they don't recognize. This means you cannot define your own attributes
- **Example**
  1. enforce constraints(conditions) on code
  2. optimise certain pieces of code
  3. do some specific code generation
      
### A. Types of attributes
#### A1. `[[noreturn]]`
  - Indicates function will never returns to caller. This means function either `throw an exception` or `call std::terminate`.
  - The behavior is undefined if the function with this attribute actually returns.
  - **Advantage** Complier will not do clean up tasks(pushing rbp etc) and can optimize the function's code.
```
[[noreturn]] void fun(std::string message) {
    cout<<message;
    if (THROW_EXCEPTION_ON_ASSERT)
        throw AssertException(std::move(message));
    terminate();
}
```

#### A2. `[[carries_dependency]]`
  - Tells complier to skip unnecessary memory fence instructions for this function as it will consumes/releases memory being part atomic operation.
  
#### A3. 
`[[deprecated]] C++14`
`[[deprecated("reason")]](C++14)`

  - The use of the name or entity declared with this attribute is allowed, but discouraged for some reason.
```
[[deprecated("Use addTemplated(int,int) instead")]]
int add(int a, int b){return a+b;}
int main(){
        cout<<add(1,2);
}
# g++ test.cpp                //Gets complied but with warning
    : warning: ‘int add(int, int)’ is deprecated: Use addTemplated(int,int) instead [-Wdeprecated-declarations]
  ```

#### A4. `[[fallthrough]]`` only with switch
  - Indicates that the fall through from the previous case label is intentional & compiler should not throw warning
  - fallthrough can only be used with switch statement.
##### Code generating warning 
```c++
void fun(int n) {
  switch (n) {
    case 1:
      cout<<"1"<<endl;
    default:
      cout<<"default"<<endl;
  }
}
int main(){
  fun(1);
}
$ g++ fallthru.cpp -Wimplicit-fallthrough
test.cpp: In function ‘void f(int)’:
test.cpp:11:15: warning: this statement may fall through [-Wimplicit-fallthrough=]
   2 |    cout<<"1"<<endl;
```

##### Code not generating warning
```c++
void fun(int n) {
  switch (n) {
    case 1:
      cout<<"1"<<endl;
  [[fallthrough]];
    default:
      cout<<"default"<<endl;
  }
}
int main(){
  fun(1);
}
```
