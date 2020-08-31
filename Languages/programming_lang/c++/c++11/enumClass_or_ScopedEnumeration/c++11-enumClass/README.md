## Enum Class
- As compared to C++98 enum this is Strongly type safe and strongly scoped.
- **1. Strongly type safe**
  - See C++-98-enum we can compare two different enums, but not possible in enum class.
```c++
int main() {
  enum class place { agra, pune, delhi };
  enum class animal { dog, horse, cow };

  place p = place::pune;        //Initialization is done using scope resolution
  animal a = animal::horse;

  if ( p == a )           //Compilation Error. while same was not giving error in c++98
    cout<<"Yes";              
}
```

