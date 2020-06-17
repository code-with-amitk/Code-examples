## `[[fallthrough]]` only with switch
  - Indicates that the fall through from the previous case label is intentional & compiler should not throw warning
  - fallthrough can only be used with switch statement.
  
##### Code generating warning 
```c++
void fun(int n) {
  switch (n) {
    case 1:
      cout<<"1"<<endl;
    default:
      cout<<"default"<<endl;
  }
}
int main(){
  fun(1);
}
$ g++ fallthru.cpp -Wimplicit-fallthrough
test.cpp: In function ‘void f(int)’:
test.cpp:11:15: warning: this statement may fall through [-Wimplicit-fallthrough=]
   2 |    cout<<"1"<<endl;
```

##### Code not generating warning
```c++
void fun(int n) {
  switch (n) {
    case 1:
      cout<<"1"<<endl;
  [[fallthrough]];
    default:
      cout<<"default"<<endl;
  }
}
int main(){
  fun(1);
}
```
