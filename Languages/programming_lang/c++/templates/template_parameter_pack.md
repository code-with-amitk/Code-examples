## Template Parameter Pack?
- Template parameter that accepts 0 or more template arguments.

### Rules
1. Ellipsis can be expanded into 0 or more comma-separated instantiations of parameters.
```c++
template<class ... T>
void f1(T ... val) {
  (cout << ... << val);   //a 2cd
}

int main(){
  f1('a');          //Expanded as f1<char> ()
  f1(' ',2,"cd");   //f1<char, int, char const*> ()
}
```

2. Template parameter can be specific type as well.
```c++
template <int i>    //Generic Template argument is not present.
void fun() {
   cout << i;   //10
}

int main() {
   fun<10> ();
}
```
