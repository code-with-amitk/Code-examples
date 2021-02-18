## Unary Left fold
- **Rules**
```c++
  ( ... + a) becomes ((((1+2)+3)+4)+5)
  
  (... op ai) becomes (((a1 op a2) op ...) op an)
     - Where, N is number of elements in pack expansion.
     - Applying binary operator(+) and expands folds/parameter pack
```     
### Code     
```c++
template<typename ... T>
auto sum(T ... a){
	return ( ... + a);
}

template<typename... T>
auto mult(T... a) { 
	return (... * a); 
}
```
