/*	primary_types.cpp

PRIMARY TYPES? Primary data type checks.

Examples:
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

************is_void<>****************
WHAT? Check whether T is void type?
Return?
	True, if T is void, const void, volatile void, const volatile void
	Otherwise false

DEFINED?
/usr/include/boost/type_traits/is_void.hpp
/usr/include/c++/8/type_traits.cpp

SYNTAX:       	
	template< class T >
	struct is_void;

::value returns the bool showing result meets desired specification or not?

INTERNAL IMPLEMENTATION?
  template<typename _Tp, _Tp __v>
    struct integral_constant
    {
      static constexpr _Tp                  value = __v;
      typedef _Tp                           value_type;
      typedef integral_constant<_Tp, __v>   type;
      constexpr operator value_type() const noexcept { return value; }
    };

  typedef integral_constant<bool, true>     true_type;		//3

  template<>
    struct __is_void_helper<void> : public true_type { };	//2

  template<typename _Tp>
    struct is_void : public __is_void_helper<typename remove_cv<_Tp>::type>::type	//1
    { };

1. Publicly inherits __is_void_helper
2. Publicly inherits true_type
3. typedef of integral_constant
4. Implemented as integral_constant internally

****************************************
*/

#include<iostream>
#include<type_traits>
using namespace std;

int main(){
	cout << is_void<void>::value;	//1
    	cout << is_void<int>::value;	//0
}
