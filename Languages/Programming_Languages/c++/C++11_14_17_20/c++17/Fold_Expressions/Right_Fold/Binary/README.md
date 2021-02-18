## Binary right fold
- **Rules**
```c++
     ((a + ...) * 10) becomes ((1+(2+(3)))*10)
     (a op ... op initial-value) becomes (a1 op (... op (an−1 op (an op initial-value))))
```     

### Code
```c++
template<typename... T>
auto addAndMult(T ... a) {          //Add all values in parameter pack and multiply with last.
	return((a + ...) * 10);		
	//lower precedence operator should be grouped in () with parameter pack
}
int main(){
  cout<<addAndMult(1,2,3,10); 	//Output:160
}  
