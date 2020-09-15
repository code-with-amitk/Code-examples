## Tuple
- **What** Class template `std::tuple` is a fixed-size collection of heterogeneous values.
- **Syntax**
```c++
	template< class... Types >		//(Since C++11)
```
- **Example**
```c++
#include<iostream>
#include <tuple>
using namespace std;

int main(){
	
	//Creates a tuple object, deducing the target type from the types of arguments.
	//make_tuple(Types&&... args):
	tuple<int,char,float> t = make_tuple(10,'g',4.5);

	//get( tuple<Types...>& t ) noexcept;
	//Extract the contents of tuple 
	cout<< get<0>(t) \
	    <<", "<<get<1>(t)\
	    << ", "<<get<2>(t)\
	    << '\n';			//O/P: 10,g,4.5
}
```
