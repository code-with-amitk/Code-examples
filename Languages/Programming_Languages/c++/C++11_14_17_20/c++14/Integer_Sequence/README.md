## Integer Sequence
- **What?** Represents a compile-time sequence of integers. it can be used as argument to variadic function template.

- make_integer_sequence: Alias template fro creating integer_sequence<>
template<class T, T N>
using make_integer_sequence = std::integer_sequence<T, //a sequence 0,1,2,..,N-1>;

- make_index_sequence: 
template<std::size_t N>
using make_index_sequence = make_integer_sequence<std::size_t, N>;
*/
#include <iostream>
#include <utility>
using namespace std;

template <typename T, T... var>		//1st argument=type, 2nd argument= Parameter pack	
void fun(integer_sequence<T, var...> test){

	cout<<test.size()<<"\t";

	((cout<<var<<' '),...);		//Displaying Values from parameter pack

	cout<<"\n";
}

int main() {
	//1st argument=type, 2nd argument= Parameter pack	
    	fun(integer_sequence<int, 1, 2, 3>());

    	fun(make_integer_sequence<int, 20>{});

	fun(make_index_sequence<10>{});
}
/*
 g++ integer_sequence.cpp --std=c++17
# ./a.out 
3	1 2 3 
20	0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 
10	0 1 2 3 4 5 6 7 8 9
*/
