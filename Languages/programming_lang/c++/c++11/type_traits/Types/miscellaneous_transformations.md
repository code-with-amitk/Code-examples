## miscellaneous transformations
- List of all miscellaneous type traits:	

- Example: enable_if
	- WHAT? Helps in conditionally removing functions from overload resolution in SFINAE based on type traits & provide separate function overloads and specializations for different type traits.
- HOW TO USE? can be used as
	- an additional function argument OR
	- an return type
	- as a class template or function template parameter
- Return?
  - True, if T is void, const void, volatile void, const volatile void
  - Otherwise false
- SYNTAX?
```		
template< bool B, class T = void >
struct enable_if;
```
- HOW IT WORKS?
	- Parameters of enable_if:	 1st: is_integral<T>::value	 2nd: int
	- if 1st parameter is true then T=2nd parameter.

- Code
```
#include<iostream>
#include<type_traits>
using namespace std;

template <typename T, enable_if_t<is_integral<T>::value, int> = 0>
void fun(T a,T b){
	cout<<a+b<<endl;
}

int main(){
	fun('a','b');	//195
//	fun(10.5,9.5);	//error: no matching function for call to ‘fun(double, double)’
	fun(1,2);	//3
}
```
