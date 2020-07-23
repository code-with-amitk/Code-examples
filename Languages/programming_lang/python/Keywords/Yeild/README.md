# What is Yield?
- Consider below C++ Code. Every time fun() is called from main(), callstack of fun() is destroyed. 
- New call of function fun() creates a new call stack.
- **Yield**
  - A keyword that allows function to return without destroying local variables(ie stack) & resume from old point.
  - Information to return to original point in called function is stored seperately.
  - Any function that contains a yield keyword is termed as generator. 
README.md

```
int fun(){
  for(int i=1;i<5;i++)        
    return i;
}      
int main(){
  for(int i=0;i<5;i++)    
    cout<<fun();
}    
# ./a.out    
11111
```    

# Why yield?
- Consider a example
  - String `21312831928`. We want to return *even numbers* from string.
    - We will create fun(), create a vector in fun() and return vector after complete parsing of string.
  - but if this string is very very huge, and caller wants results immedeiately then we cannot wait for complete string to parsed, then yield will come handy.
