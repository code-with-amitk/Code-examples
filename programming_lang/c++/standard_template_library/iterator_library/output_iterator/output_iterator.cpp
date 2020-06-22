/*	output_iterator.cpp

OUTPUT ITERATOR? 
 - Used to write the values to the container and then increment.
*/
#include<iostream>
#include<iterator>
using namespace std;

int main(){

	/*EXAMPLE:
	  ostream container provides output iterator
	 */
	ostream_iterator<int> test(cout," ");

	for(int i=0;i<10;i++)
		*test++=i;

	cout<<endl;
}
/* O/P:
# g++ output_iterator.cpp 
# ./a.out 
0 1 2 3 4 5 6 7 8 9 

*/

