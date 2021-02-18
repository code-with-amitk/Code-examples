## noexcept operator
- **What?** noexcept operator checks at compile-time if an expression can throw exception or not?
- Operator takes expression as argument.
```c++
noexcept(constant_expression)
```

### Example Code
```c++
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
```
