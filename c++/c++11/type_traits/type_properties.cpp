/*	type_properties.cpp
https://en.cppreference.com/w/cpp/types

WHAT? Checks properties of types	

TYPES?
is_const:checks if a type is const-qualified
is_volatile:checks if a type is volatile-qualified
is_trivial:checks if a type is trivial
is_trivially_copyable: checks if a type is trivially copyable
is_standard_layout: checks if a type is a standard-layout type
is_pod(deprecated in C++20): checks if a type is a plain-old data (POD) type
is_literal_type(removed in C++20): checks if a type is a literal type
has_unique_object_representations(C++17): checks if every bit in the type's object representation contributes to its value
is_empty: checks if a type is a class (but not union) type and has no non-static data members
is_polymorphic: checks if a type is a polymorphic class type
is_abstract: checks if a type is an abstract class type
is_final(C++14): checks if a type is a final class type
is_aggregate(C++17): checks if a type is an aggregate type
is_signed: checks if a type is a signed arithmetic type
is_unsigned: checks if a type is an unsigned arithmetic type
is_bounded_array(C++20): checks if a type is an array type of known bound
is_unbounded_array(C++20): checks if a type is an array type of unknown bound

*****************is_volatile********************
WHAT? Check whether T is:
	volatile or const volatile
Return?
        True, if T satisfies above mentioned types
        Otherwise false

DEFINED?
/usr/include/boost/type_traits/is_void.hpp
/usr/include/c++/8/type_traits.cpp

SYNTAX:
        template< class T >
	struct is_volatile;
************************************************

*/

#include<iostream>
#include<type_traits>
using namespace std;

int main(){
        cout << (is_volatile<volatile int>::value
                     ? "T is volatile"
                     : "T is not a volatile") << '\n';
}
/*Output:
T is volatile
 */

