- **Iterator**
  - [What](#what)
  - [Why](#why)
- [Types of Iterators](#types)
  - [1. Input](#inp)
  - [2. Output](#out)
  - [3. Forward](#fow)
  - [4. Bidirectional](#bi)
  - [5. Random Access](#ra)
  - [6. Continuous(C++17)](#types)
- Examples
  - [1. Merge 2 sorted vectors using iterator](#e1)


## Iterator
<a name=what></a>
**What**
- A object (similar to pointer) that points to an element inside the container and can iterate through elements of container. 
  - iterators class is defined inside container hence behavior is container specific.
  - Every iterator is not supported by all the containers. eg vectors support Random-access iterator, forward_list support forward iterator.
- *Iterator class?* iterator class is defined inside namespace of container class. Hence its accessed using scope resolution(::) operator.
```c++
    vector<int> a = {1,2,3,4,5,6};
    vector<int>::iterator it;      //Also note type of iterator is bound to type of class.
    it = a.begin();                //vector class's member function begin() returns forward iterator
    it = a.end();                  //vector class's member function end() element 1 past end
```  
**[Why](/Languages/Programming_Languages/Rust/Iterators)**

<a name=types></a>  
### Types of iterators 
input is least & random access is most powerful.
```c++
       Iterator          traverse-thru-container    direction    Read/Write        Example
    a. Input               single                    1             R            istream container
    b. Output              single                    1             W            ostream contianer
    c. forward             single                    1             RW          forward_list container    //both input, output
    d. Bidirectional       many                     both           RW            set<> container              //both
    e. Random-access       many                    random          RW            vector<> container          //both
    e. Continuous(C++17)     this LRA iterator whose logically adjacent elements are also physically adjacent in memory. 
    Eg: array::iterator, basic_string_view::iterator, vector::iterator
```    
- **Mutable Iterator?** (mutable means changeable) Iterators which support both input and output.
- **Constant Iterator?** non-mutable iterators
- **Operations on iterator?** Accessing elements(*,->), Make iterator point to next element(++)

<a name=inp></a>
#### 1. Input Iterator
- Read values from the container and then increment
- Can not alter the value of a container
- 1 way Iterator
- Once value is read it cannot be read again.  (decrement: Not allowed)
```cpp
#include<iterator>
int main(){

	int a,b=0;

	cout<<"Enter a,b";
	cin.clear();

	istream_iterator<int> eos;		    //default ctr
	istream_iterator<int> test(cin);	//stdin iterator

	if(eos == test)	//testing end-of-stream
		cout<<"Hello";
	else
		cout<<"No";
}
#./a.out
1 2
No
```

<a name=out></a>
#### 2. Output Iterator
Used to write the values to the container and then increment.
```cpp
int main(){
	//EXAMPLE: ostream container provides output iterator
	ostream_iterator<int> test(cout," ");

	for(int i=0;i<10;i++)
		*test++=i;
}
# ./a.out 
0 1 2 3 4 5 6 7 8 9 
```

<a name=fow></a>
#### 3. Forward Iterator
 Combination of input & output iterator. Allowed to move forward not backward.
 ```cpp
 #include<forward_list>
int main(){
	//EXAMPLE-1: forward_list(singly ll) uses forward_iterator. iterator can iterate from front to end not from end to start
	forward_list<int> a = {1,2,3,4,5};
	forward_list<int>::iterator it;

	for(it=a.begin();it!=a.end();it++){
		cout<<*it<<" ";
	}
	//it = a.end();
	//--it;			   //Decrement not allowed
}
# ./a.out 
1 2 3 4 5 
1 2 3 4 5
 ```

<a name=bi></a>
#### 4. Bidirectional Iterator
it is used to access the container in either direction forward or backward.
```cpp
#include<set>

int main(){

	//EXAMPLE: set container provides bi-directional iterator
	set<int> a = {1,2,3,4,5};
	set<int>::iterator it;

	//end(): returns the value past end.
	for(it=a.begin(); it!=a.end(); ++it)
		cout<<*it<<" ";

	for(it=a.end(); it!=a.begin();)
		cout<<*--it<<" ";
	cout<<endl;
}
# ./a.out 
1 2 3 4 5 
5 4 3 2 1 
```

<a name=ra></a>
#### 5. Random Access
Any element in container can be accessed randomly, same as pointer.
```cpp
#include <vector>
#include<iterator>

int main(){
	//EXAMPLE: vector has ra iterator
	vector<int> a = {1,2,3,4,5,6};
	vector<int>::iterator it;

	for(it=a.begin(); it!=a.end(); ++it)    //iterate forward
		cout<<*it<<" ";

	for(it=a.end(); it!=a.begin();)         //iterate backward
		cout<<*--it<<" ";

	for(it=a.begin(); it!=a.end(); it=it+2) //random forward
		cout<<*it<<" ";

	it = a.begin();                        //Access element randomly
	cout<<*(it+4);
}
# ./a.out
1 2 3 4 5 6
6 5 4 3 2 1
1 3 5
5
```

### Examples
<a name=e1></a>
#### 1. Merge 2 sorted vectors using iterator
```cpp

```
