## CONSTEVAL
  - 1st see ***problem*** in [constexpr](https://github.com/amitkumar50/Code-examples/blob/master/programming_lang/c++/c++11/Constexpr/README.md)
  
### Problem with constexpr (It's not Guranteed compile-time-constant)
  - See the below code.
  - A runtime variable `c` is passed to constexpr function, then how constexpr function can be compile-time gurantee?
```
constexpr int fun(int a){
  return 2*a;
}
int main(){
  constexpr int b = fun(5); cout<<b;    //10
  
  int c;  cin>>c;
  int d = fun(c); cout<<d;        //c=7 d=14
}
```
  - **Conclusion**
    - Compiler “tries its best” to evaluate constexpr compile-time, but not guranteed.
    - ie constexpr is only a marker used to express that the function can be used in a constant expression if needed.
    
https://awfulcode.io/2019/01/26/immediate-functions-in-c20/    
