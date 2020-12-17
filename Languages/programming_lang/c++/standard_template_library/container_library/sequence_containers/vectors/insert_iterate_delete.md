## A. Insert
- **1. void push_back( T&& value );   //Since C++11**
  - Appends the value to the end of the container. Return value:None, Complexity:Amortized constant.
```c++
  vector<int> v(5,10);            //array of size=5, Each element value=10
  for(auto i:v)
    cout<<i<<" ";           //10 10 10 10 10
  v.push_back(11);          //10 10 10 10 10 11
```
- **2. void assign( size_type count, const T& value )**
  -  Replaces the contents with count copies of value value
```c++
  vector<int> v; 
  v.assign(3, 10);            //10 10 10  
```
- **insert(position, value)**
```c++
  vector<int> v = { 10, 20, 30, 40 }; 
  auto it = v.insert(v.begin(), 3);     //3 10 20 30 40
  int i = 2; 
  it = vec.insert(v.begin() + i, 7);      //3 10 7 20 30 40
```
       
## B. Traverse/Iterate
- **1. index**
```c++
  for(int i=0;i<v.size();i++)
    cout<<v[i]<<",";        //10,10,10,10,10,11,
```
- **2. begin(), end()**
```c++
  for(auto i=v.begin();i!=v.end();i++)
    cout<<*i<<";";          //10;10;10;10;10;11;
```
- **`3. vector<int>::iterator itr`**
```c++
  vector<int>::iterator itr;
  for(itr=v.begin(); itr!=v.end(); itr++) //10'10'10'10'10'11'
    cout<<*itr<<"'";
```
- **4. vector.at(position)**
  - Returns a reference to the element at position n in the vector.
  - This is same operator`[]` but .at() checks the bounds of array while `operator[]` does not. at() throws `out_of_range` exception when index is out of bounds.
```c++
vector<int> v = {1,2,3};
cout<<v.at(2);            //3
cout<<v.at(3);            //terminate called after throwing an instance of 'std::out_of_range' coredumped
```

## C. Erase/Delete/Remove
- **1. iterator erase( const_iterator pos );**   //Since C++11
  - Remove element at position
```c++
  v.erase(v.begin());
  for(auto i:v)
    cout<<i<<" ";           //10 10 10 10 11
```

- **2. iterator erase( const_iterator first, const_iterator last );**  //Since C++11
  - Remove in range
```c++
  v.erase(v.begin()+1, v.end()-1);
  for(auto i:v)
    cout<<i<<" ";           //10 11
```

- **3. void clear() noexcept;**  //Since C++11
  - Erases all elements from the container. After this call, size() returns 0
  - Complexity: Linear in the size of the container, i.e., the number of elements.  
  - parameters: None. Return values: None
```c++
  v.clear();
  cout<<v.size();                 //0
```
