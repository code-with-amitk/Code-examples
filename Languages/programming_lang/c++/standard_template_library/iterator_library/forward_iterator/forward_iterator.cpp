/*
WHAT?
 - Combination of input & output iterator.
 - Allowed to move forward not backward.

OPERATIONS:
1. INCREAMENT: ok
2. DECREMENT: not possible
	- forward iterator class have not implemented decrement operator
*/
#include <iostream>
#include<forward_list>

using namespace std;

int main(){
	/* EXAMPLE-1: forward_list uses forward_iterator
	 * forward_list is single LL
	 * & provides forward iterator.
	 * iterator can iterate from front to end not from end to start
	 */
	forward_list<int> a = {1,2,3,4,5};
	forward_list<int>::iterator it;


	/* DECREMENTING: not allowed
	   - if we try to decrement forward iterator it gives error at compile time
	 */
	//it = a.end();
	//--it;			//error: no match for ‘operator--’ (operand type is ‘std::forward_list<int>::iterator’ {aka ‘std::_Fwd_list_iterator<int>’})

	for(it=a.begin();it!=a.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;


	/* EXAMPLE-2: range-based loops uses forward iterator
	 */
	for(int i:a)
		cout<<i<<" ";

}
/*
# ./a.out 
1 2 3 4 5 
1 2 3 4 5
*/
