/*	tuple.cpp

WHAT?
- Class template std::tuple is a fixed-size collection of heterogeneous values.

SYNTAX:
	template< class... Types >	(Since C++11)
*/

#include<iostream>
#include <tuple>
using namespace std;

int main(){

	/*1. Creating a tuple and printing its values
	    a. make_tuple(Types&&... args):
	       Creates a tuple object, deducing the target type
	       from the types of arguments.

	     b. get( tuple<Types...>& t ) noexcept;
	        Extract the contents of tuple 
	 */

	tuple<int,char,float> t = make_tuple(10,'g',4.5);
	cout<< get<0>(t) \
	    <<", "<<get<1>(t)\
	    << ", "<<get<2>(t)\
	    << '\n';			//O/P: 10,g,4.5
}
