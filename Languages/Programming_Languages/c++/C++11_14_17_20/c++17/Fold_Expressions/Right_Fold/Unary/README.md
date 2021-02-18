## Unary Right Fold
- **Rules
```c=+
     (a % ... ) becomes (49%(10%4))
     (a op ...) becomes (a1 op (... op (an-1 op an)))
     - Applying binary operator(%) and expands folds/parameter pack
```     

### Code
```c++
template<typename... T>
auto mod(T ... a){
	return (a % ... );
}

int main(){
  cout<<mod(49,10,4);	    //Output:1
}  
