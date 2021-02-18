## NRVO(Named Return Value Optimization)
- Object with a name is returned but is not copied or used.
```c++
int fun(int a){ 
  int c = a;
  return c;
}

int b(){
  int a[fun(10)];
}
```
