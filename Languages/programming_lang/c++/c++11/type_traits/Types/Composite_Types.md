## Composite Types
- **What** Composite data types check.
- Types
```
is_fundamental: checks if a type is a fundamental type(void or nullptr_t)
is_arithmetic: checks if a type is an arithmetic type
is_scalar: checks if a type is a scalar type
	- cv-qualified arithmetic, pointer, pointer to member, enumeration, or nullptr_t type
is_object: checks if a type is an object type
is_compound: checks if a type is a compound type
	- array, function, object pointer, function pointer, member object pointer, member function pointer, 
	reference, class, union, or enumeration,
is_reference: checks if a type is either a lvalue reference or rvalue reference
is_member_pointer: checks if a type is a pointer to an non-static member function or object
```
- Code
```
int main(){
	class test{};
    	cout << (is_compound<test>::value
                     ? "T is compound"
                     : "T is not a compound") << '\n';

    	cout << (is_compound<int>::value
                     ? "T is compound"
                     : "T is not a compound") << '\n';	
}
/*
Output:
# ./a.out 
T is compound
T is not a compound
*/
```
