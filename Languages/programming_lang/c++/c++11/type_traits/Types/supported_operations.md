## Supported Operations
- WHAT? Tells if type supports the operation or not?
- TYPES?
```	
is_constructible,is_trivially_constructible,is_nothrow_constructible: 
	checks if a type has a constructor for specific arguments
is_default_constructible,is_trivially_default_constructible,is_nothrow_default_constructible:checks if a 
type has a default constructor
is_copy_constructible,is_trivially_copy_constructible,is_nothrow_copy_constructible:checks if a type has a copy constructor
is_move_constructible,is_trivially_move_constructible,is_nothrow_move_constructible:checks if a type can be
constructed from an rvalue reference
is_assignable,is_trivially_assignable,is_nothrow_assignable:checks if a type has a assignment operator for a
specific argument
is_copy_assignable,is_trivially_copy_assignable,is_nothrow_copy_assignable:checks if a type has a copy assignment operator
is_move_assignable,is_trivially_move_assignable,is_nothrow_move_assignable:checks if a type has a move assignment operator
is_destructible,is_trivially_destructible,is_nothrow_destructible:checks if a type has a non-deleted destructor
has_virtual_destructor:checks if a type has a virtual destructor
is_swappable_with,is_swappable,is_nothrow_swappable_with,is_nothrow_swappable:checks if objects of a type can be 
swapped with objects of same or different type
```

### Example is_copy_constructible
- T is copy_constructible type if:
	- T is not a referenceable type OR
	- a function type with a cv-qualifier-seq OR
- Return?
	- True, if T is copy_constructible
	- Otherwise false
- DEFINED?
	- /usr/include/boost/type_traits/is_void.hpp
	- /usr/include/c++/8/type_traits.cpp
- SYNTAX:
```
	template< class T >
  struct is_copy_constructible;
::value returns the bool showing result meets desired specification or not?
```
- Code
```
#include<type_traits>

struct Ex1 {
	string str; // member has a non-trivial copy ctor
};

int main(){
	if(is_copy_constructible<Ex1>::value)
		cout<<"Ex1 is copy-constructible "<<"\n";
}
/*./a.out
 * Ex1 is copy-constructible
 */
```
