/*	composite_types.cpp
https://en.cppreference.com/w/cpp/types

WHAT? Composite data types check.



*****************is_compound********************
WHAT? Check whether T is array, function, object pointer, function pointer, member object pointer, member 
function pointer, reference, class, union, or enumeration?
Return?
        True, if T satisfies above mentioned types
        Otherwise false

DEFINED?
/usr/include/boost/type_traits/is_void.hpp
/usr/include/c++/8/type_traits.cpp

SYNTAX:
	template< class T >
	struct is_compound;
************************************************
*/

#include<iostream>
#include<type_traits>
using namespace std;


