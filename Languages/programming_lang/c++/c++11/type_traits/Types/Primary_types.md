## Primary Types
- **What** Primary data type checks.
- Example:
```
is_void: checks if a type is void
is_null_pointer(C++14): checks if a type is std::nullptr_t
is_integral:checks if a type is an integral type
is_floating_point:checks if a type is a floating-point type
is_array:checks if a type is an array type
is_enum:checks if a type is an enumeration type
is_union:checks if a type is an union type
is_class:checks if a type is a non-union class type
is_function:checks if a type is a function type
is_pointer:checks if a type is a pointer type
is_lvalue_reference: checks if a type is a lvalue reference
is_rvalue_reference: checks if a type is a rvalue reference
is_member_object_pointer: checks if a type is a pointer to a non-static member object
is_member_function_pointer: checks if a type is a pointer to a non-static member function
```
- Defined in
```
/usr/include/boost/type_traits/is_void.hpp
/usr/include/c++/8/type_traits.cpp
```
- Code
```
#include<type_traits>
int main(){
  cout << is_void<void>::value;	//1
  cout << is_void<int>::value;	//0
}
```
