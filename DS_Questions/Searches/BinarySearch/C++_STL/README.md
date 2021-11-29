- [binary search](#bs)
- [lower_bound](/Languages/Programming_Languages/c++/Standard_Template_Library/container_library/sequence_containers/vectors/README.md#lb)

<a name=bs></a>
## binary_search
- Returns true if element is found else false.
```c++
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
  vector<int> a = {1,2,4,5,8,9};
  if( true == binary_search(a.begin(), a.end(), 8))
    cout << "Found";
  else
    cout << "Not Found";
}

# ./a.out
Found
```

