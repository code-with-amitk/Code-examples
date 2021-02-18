## Class/Structure Member Binding
- expression is of type structure
```c++
  attr(optional) cv-auto ref-operator(optional) [ identifier-list ] ( expression ) ;
```  
### Code
```c++
struct A{
  int x;
  double y;
  A(int a, int b):x(a),y(b){}
};

int main(){
  const auto [d1, d2] = A(10,20);
  cout<<d1<<" ,"<<d2<<endl;               //10,20
}
```
