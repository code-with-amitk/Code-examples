### `1. find(const key_type& k)`
### `2. erase(const key_type& k)`
- Finding key in map
```c++
#include<map>
using namespace std;

template < typename K, typename V >
class mymap {
  std::map < K, V > m;
public:
  void assign ( K const& key, V const& value ) {
    m.insert ( std::pair <K, V> (key, value) );
  }
  
  void find ( K key ) {
    if ( (m.find (key)) != m.end() )   //key found
      m.erase (key);
  }
  
};

int main() {
  std::map <
}
```
