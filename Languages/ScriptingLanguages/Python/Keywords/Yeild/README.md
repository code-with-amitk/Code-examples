# Yeild
- Consider below C++ Code. Every time fun() is called from main(), callstack of fun() is destroyed. 
- New call of function fun() creates a new call stack.
- **Yield**
  - A keyword that allows function to return without destroying local variables(ie stack) & resume from old point.
  - Information to return to original point in called function is stored seperately.
  - Yield throws away the stack concept completely. Stop thinking of one process as the caller and the other as the callee, and start thinking of them as cooperating equals.
  - Any function that contains a yield keyword is termed as generator.
- **C++ Code**
```c++
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

- **Python**
```python
def rangeN(a, b): 
    i = a 
    while (i < b): 
        yield i 
        i += 1  # Next execution resumes  
                # from this point     
for i in rangeN(1, 5): 
        print(i) 
Output:
1
2
3
4
5 
```
# Why yield?
- Consider a example
  - String `21312831928`. We want to return *even numbers* from string.
    - We will create fun(), create a vector in fun() and return vector after complete parsing of string. ie LOADING HUGE content in Memory
  - But if this string is very very huge(eg: Microsoft word), and caller wants results immedeiately then we cannot wait for complete string to parsed, then yield will come handy.
