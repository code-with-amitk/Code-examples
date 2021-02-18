## Example
- **Problem:** Function is not const because return depends on runtime
```c++
const int fun(){
  int b;
  cin>>b;
  return b;              //NO ERROR
}
```
- **Solution:** 
```c++
constexpr int fun(){
  //int b;               //error: uninitialized variable ‘b’ in ‘constexpr’ function
  int b = 10;
  return b;  
}

int main(){
  const float d = fun(2);
}
```
