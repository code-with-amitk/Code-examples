## Array Member Binding
  - expression is of type array
  - Number of identifiers in identifier-list must be equal to the number of elements in the array.
- **Syntax**
  attr(optional) cv-auto ref-operator(optional) [ identifier-list ] = expression ;
```  
### Code
```c++
  int a[2] = { 1,2 };
  auto [ xval, yval ] = a;
  cout<<xval<<" "<<yval<<endl;    //1 2
```  
