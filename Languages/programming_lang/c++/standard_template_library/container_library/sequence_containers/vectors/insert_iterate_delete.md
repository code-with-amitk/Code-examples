## A. INSERTION
### 1. void push_back( T&& value );   //Since C++11
- Appends the value to the end of the container.
  - Return value: None
  - Complexity: Amortized constant.
```
  vector<int> v(5,10);            //array of size=5, Each element value=10
  for(auto i:v)
    cout<<i<<" ";           //10 10 10 10 10

  v.push_back(11);          //10 10 10 10 10 11
```
       
## B. TRAVERSING/ITERATING VECTOR
### Method-1 for()
```
  for(int i=0;i<v.size();i++)
    cout<<v[i]<<",";        //10,10,10,10,10,11,
```
### Method-2 begin(), end()
```
  for(auto i=v.begin();i!=v.end();i++)
    cout<<*i<<";";          //10;10;10;10;10;11;
```
### Method-3 iterator
```
  vector<int>::iterator itr;
  for(itr=v.begin(); itr!=v.end(); itr++) //10'10'10'10'10'11'
    cout<<*itr<<"'";
```

## C. ERASE/DELETE/REMOVE
### iterator erase( const_iterator pos );   //Since C++11
- Remove element at position
```
  v.erase(v.begin());
  for(auto i:v)
    cout<<i<<" ";           //10 10 10 10 11
```

### iterator erase( const_iterator first, const_iterator last );  //Since C++11
- Remove in range
```
  v.erase(v.begin()+1, v.end()-1);
  for(auto i:v)
    cout<<i<<" ";           //10 11
```

### void clear() noexcept;  //Since C++11
- Erases all elements from the container. After this call, size() returns 0
- Complexity: Linear in the size of the container, i.e., the number of elements.  
  - parameters: None
  - Return values: None
```
  v.clear();
  cout<<v.size();                 //0
```
