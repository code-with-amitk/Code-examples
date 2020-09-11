## insert (const value_type& val)
```c++
#include<map>

template < typename K, typename V >
class mymap {
  std::map < K, V > m;
public:
  void assign ( K const& key, V const& value ) {
    m.insert ( std::pair <K, V> (key, value));
  }
  
  void disp () {
    typename std::map<K,V>::iterator it;
    for ( it = m.begin(); it != m_map.end(); it++ ) {
      std::cout << it->first << ", "<< it->second << std::endl;
    }  
  }
  
};

int main() {
  mymap obj;
  obj.assign (1, 'a');
  obj.assign (2, 'b');
  obj.disp();
}

/*
1 a
2 b
*/
```
