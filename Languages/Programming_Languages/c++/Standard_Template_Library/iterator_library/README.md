- Iterator
  - [What](#what)
  - [Why](#why)
- Types of Iterators


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

  
    
### 6 types of iterators 
- input is least & random access is most powerful.
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
