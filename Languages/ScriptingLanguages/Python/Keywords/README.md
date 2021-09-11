- **Yeild**

## Yeild
- Consider below C++ Code. Every time fun() returns, callstack of fun() is destroyed & New call of function fun() creates a new call stack.
- **Yield**
  - is a keyword that allows function to return without destroying local variables(ie stack) & resume from old point.
  - Information to return to original point in called function is stored seperately. Stop thinking of one process as the caller and the other as the callee, and start thinking of them as cooperating equals.
  - _Generator:_ Function containing yield keyword.
- **C++ Code**
```cpp
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

**Python**
```python
def rangeN(a, b): 
    i = a 
    while (i < b): 
        yield i 
        i += 1  # Next execution resumes from this point     
for i in rangeN(1, 5): 
        print(i) 
Output:
1
2
3
4
5 
```
