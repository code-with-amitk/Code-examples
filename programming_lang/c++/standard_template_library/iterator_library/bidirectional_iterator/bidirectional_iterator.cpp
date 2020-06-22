/*	birectional_iterator.cpp
 
WHAT?
 - it is used to access the container in either direction
 - ie it can iterated either forward or backward


*/

#include<iostream>
#include<set>

using namespace std;

int main(){

	/* EXAMPLE-1:
	 - set container provides bi-directional iterator
	 */
	set<int> a = {1,2,3,4,5};
	set<int>::iterator it;

	//end(): returns the value past end.
	for(it=a.begin(); it!=a.end(); ++it)
		cout<<*it<<" ";
	cout<<endl;

	//Sice end(): returns the value past the end
	//end we need to do prefix decrement
	for(it=a.end(); it!=a.begin();)
		cout<<*--it<<" ";
	cout<<endl;
}
/* 
# ./a.out 
1 2 3 4 5 
5 4 3 2 1 
*/

