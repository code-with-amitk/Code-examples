## Binary left fold
- Pack-variable on right
- **Rules**
```c++
     10 * (... / a)) becomes ((((10 * 100)/2)/5)/10)
     (initial-value op ... op ai) becomes ((((initial-value op a1) op a2) op ...) op an)
```     

### Code
```c++
template<typename... T>
auto multiplyDivide(T ... a) {    //Function multiply with last
        return(10 * (... / a));
}
int main(){
	cout<<multiplyDivide(100,2,5,10);	  //Output:10
}  
