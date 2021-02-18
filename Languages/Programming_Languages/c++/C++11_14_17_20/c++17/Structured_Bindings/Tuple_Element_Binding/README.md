## Tuple Element Binding
- expression is of type tuple
- **Syntax**
```c++
  attr(optional) cv-auto ref-operator(optional) [ identifier-list ] { expression }
```  
### Code
```c++
  tuple<int,char,float> tp1 = make_tuple(1,'a',3.5);
  auto [t1,t2,t3] = tp1;
  cout<<t1<<" "<<t2<<" "<<t3<<endl;       //1 a 3.5
```        
