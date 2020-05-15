/*	random_access_iterator.cpp

WHAT?
 - Any element in container can be accessed.
 - Offers all functionality of C++ pointer.
*/

#include<iostream>
#include <vector>
#include<iterator>
using namespace std;

int main(){
	/* EXAMPLE-1
	 - default constructor of random access iterator
	   provides random access iterator
	 */
	vector<int> a = {1,2,3,4,5,6};
	vector<int>::iterator it;

	//iterate forward
	for(it=a.begin(); it!=a.end(); ++it)
		cout<<*it<<" ";
	cout<<endl;

	//iterate backward
	//end() points to 1 element past end(), hence we need decrement out of for
	for(it=a.end(); it!=a.begin();)
		cout<<*--it<<" ";
	cout<<endl;

	//random forward
	for(it=a.begin(); it!=a.end(); it=it+2)
		cout<<*it<<" ";
	cout<<endl;


	//Accessing element randomly
	it = a.begin();
	cout<<*(it+4);
}
/*
# ./a.out
1 2 3 4 5 6
6 5 4 3 2 1
1 3 5
5
*/
