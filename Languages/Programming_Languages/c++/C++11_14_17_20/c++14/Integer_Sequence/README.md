**Integer Sequence**

## Integer Sequence
- Represents a compile-time sequence of integers. it can be used as argument to [variadic function template](/Languages/Programming_Languages/c%2B%2B/Characteristics_of_OOPS/Polymorphism/Static_CompileTime/Templates/Variadic/Function)
- `make_integer_sequence:` Alias template for creating `integer_sequence<>`
```cpp
template<class T, T N>
using make_integer_sequence = std::integer_sequence<T, //a sequence 0,1,2,..,N-1>;
```
- make_index_sequence:
```cpp
template<std::size_t N>
using make_index_sequence = make_integer_sequence<std::size_t, N>;
```
### Code Example
```cpp
#include <iostream>
#include <utility>

template <typename T, T... var>     //1st argument=type, 2nd argument= Parameter pack
void fun(std::integer_sequence<T, var...> test){
  std::cout<<test.size()<<"\t";
  ((std::cout<<var<<' '),...);      //Displaying Values from parameter pack}

int main() {

  fun(std::integer_sequence<int, 1, 2, 3>()); //1st argument=type, 2nd argument= Parameter pack

  std::cout<<"\n";
  fun(std::make_integer_sequence<int, 20>{});

  std::cout<<"\n";
  fun(std::make_index_sequence<10>{});
}
 g++ integer_sequence.cpp --std=c++17
# ./a.out 
3	1 2 3 
20	0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 
10	0 1 2 3 4 5 6 7 8 9
```
