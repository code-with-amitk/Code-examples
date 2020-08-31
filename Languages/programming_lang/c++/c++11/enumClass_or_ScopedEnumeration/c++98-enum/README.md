## Drawbacks of C++98 enums
- **1. Not type safe**
  - *What is type safe?*
    - Extent to which programming language prevents type errors.
    - type error is erroneous program behaviour caused by a discrepancy between differing data types
```c++
int main() {
  enum place { agra, pune, delhi };
  enum animal { dog, horse, cow };

  place p = pune;
  animal a = horse;

  if ( p == a )               //No error but gives warning: comparison between ‘enum main()::place’ and ‘enum main()::animal’
    cout<<"Yes";              //Output Yes
}
```

- **2. Variables cannot take names of enum variables**
```c++
int main() {
  enum color {red,black,blue};
  color c = red;

  int blue = 1;              //Compilation error:  ‘int blue’ redeclared as different kind of symbol
}
```

- **3. Two enums cannot have same named variables**
```c++
int main() {
  enum IndianColor {red,black,blue};
  enum DublinColor {white,excellentGrey,blue};            //Compilation Error: error: redeclaration of ‘blue’
}
```
