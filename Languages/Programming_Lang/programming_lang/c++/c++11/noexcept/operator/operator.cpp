/*      noexcept-operator.cpp
  
TYPES OF NOEXCEPT? noexcept exists in two forms since C++11: 
  1. noexcept as specifier and
  2. noexcept as operator

- Operator takes expression as argument.
noexcept(constant_expression)

WHAT? noexcept operator checks at compile-time if an expression can throw exception or not?
*/

#include <iostream>
#include <array>
#include <vector>

class A{
public:
	array<int, 5> arr{1, 2, 3, 4, 5};      
};

class B{
public:
	vector<int> v{1, 2, 3, 4 , 5};        
};

template <typename T>
T fun(T const& src) noexcept(is_nothrow_copy_constructible<T>::value)
{
	return src;
}

int main(){

    A a;
    B b;

    cout << "Array is not copy constructible: " << 	//1
                  noexcept(fun(a)) << endl;

    cout << "Vector is copy contructible: " <<         	//0
                  noexcept(fun(b)) << endl;

}
