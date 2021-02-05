## all_of

### Syntax
```
template< class InputIt, class UnaryPredicate >
constexpr bool all_of( InputIt first, InputIt last, UnaryPredicate p );
```

### Example
```
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  vector<int> v(10,2);    //10 vectors initialized to 2
  
  for(auto i:v)
    cout<<i<<" ";

  if(all_of(v.begin(), v.end(), [](int i){return i%2 == 0;})){
    cout<<"All nos are even";
  }
}

Output: All nos are even
```
