/* 
 * What?
 * 	- Dynamic array growing in 1 direction only
 * 	- Elements are stored contigously, can be randomly traversed
 * 	- Vector stores elements from index 0
 * 	- Deletion: Linear(at Head), Amortized(at End)
 *
 * Implementation
 * 	- template <class test, class Alloc = allocator <test>>
 *
 * Rememberance of templates. Vectors are implemeted as templates
 * 	template <class T>
 * 	class addMult {	.... }
 * Called as:	addMult <int> obj1();
 */
#include<iostream>
#include<vector>
int main() {
	std::vector<int> a;		//Creating Vector Object through default Ctr
	std::cout<<"Size="<<a.size()<<std::endl;
	a.push_back (10);
	a.push_back (20);
	a.push_back (30);
	std::cout<<"Size="<<a.size()<<std::endl;

	std::cout<<"Accessing element ="<<a[2]<<std::endl;

	std::cout<<"All Elements are \t";
	//for (int i; i<a.size(); i++)	cout<<a[i];	//This is also valid
	
	//Iterators are universal way of traversing Containers. Even If vec is changed to set This code remains same
	for (std::vector<int>::iterator it = a.begin(); it != a.end(); it++) {
		std::cout<<*it<<"\t";
	}

	//for (auto &it:a) std::cout<<it<<"\t";		//This is also valid
}
/*Output:
 * Size=0
 * Size=3
 * Accessing element = 30
 * All Elements are	10 20 30
 */

/*Other Vector class Constructor Calls
 * std::vector <int> b(4,10)	//Created 4 integers with value = 10
 * std::vector <int> b(a.begin(),a.end())	//Construct b from a
 * std::vector<int> c (b)		//Copy b to c
 */
