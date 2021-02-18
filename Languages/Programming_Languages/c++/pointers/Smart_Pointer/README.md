## Smart Pointers
- **What?** User-defined class that manages automatic deletion of dynamic memory. Allocation is done in constructor, deletion inside destructor. Bcoz Destructors are automatically executed 
when Object goes out of scope.
- **Why?** Programmer may allocate memory using new() & later might forget to use delete(). 

### Code
- class maintains a local pointer, memory is allocated and assigned to pointer.
- Overloaded functions are defined for *, ->
```c++
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
	//Automatic template type deduction => Provided in C++17
	smart_pointer <int> obj(new int());	//obj is my pointer now. I can carry all pointer operations
	*obj = 10;
	cout<<*obj<<"\n";

	smart_pointer <float> obj1(new float());
}

# g++ smart_pointers
Allocated memory
10
Allocated memory

Destructor called, Allocated memory freed
Destructor called, Allocated memory freed
```
