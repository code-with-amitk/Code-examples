/*	smart_pointer.cpp

What? class that manages automatic deletion of dynamic memory. Allocation is done in constructor, 
deletion inside destructor. Bcoz Destructors are automatically executed when Object goes out of scope.

*********Logic********
- class maintains a local pointer, memory is allocated and assigned to pointer.
- Overloaded functions are defined for *, ->
***********************
*/
#include<iostream>
using namespace std;

//Steps to Write Generic Code/Templates?
//a. Write class for a type(Eg: int)
//b. Replace the type with template
template <class T>		
class smart_pointer{
//	int *a;
	T *a;
public:
//	smart_pointer(int *r):a(r){
	smart_pointer(T *r):a(r){
		cout<<"Allocated memory\n";
	}
	~smart_pointer(){
		cout<<"\nDestructor called, Allocated memory freed\n";
		delete a;
	}
//	int &operator *(){	//& returns a only, does not create new copy
	T &operator *(){
		return *a;
	}
};

int main(){
	smart_pointer obj(new int());	//obj is my pointer now. I can carry all pointer operations
	*obj = 10;
	cout<<*obj;

	smart_pointer obj1(new float());
}
