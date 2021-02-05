/*	input_iterator.cpp

INPUT ITERATOR? 
 - Used to read the values from the container and then increment.
 - Can not alter the value of a container.
 - 1 way Iterator
 - Once value is read it cannot be read again.
 
Allowed operations?
1. dereference
2. increment: Allowed
3. decrement: Not allowed
*/
#include<iostream>
#include<iterator>

using namespace std;

int main(){
	/*EXAMPLE IOSTREAM
	  iostream class uses input iterator for cin
	 */
	int a,b=0;

	cout<<"Enter a,b";
	cin.clear();

	istream_iterator<int> eos;		//default ctr
	istream_iterator<int> test(cin);	//stdin iterator

	if(eos == test)	//testing end-of-stream
		cout<<"Hello";
	else
		cout<<"No";
}
/*
Output:
#./a.out
1 2
No
*/
