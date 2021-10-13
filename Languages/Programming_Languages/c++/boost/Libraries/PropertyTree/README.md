**PropertyTree**
- [Why Ptree](#w)
- **Reading**
  - [from xml](#rx)

## PropertyTree
- This library provides a data structure to store [m-ary Tree]() where each node has `<key, value>`
```cpp
struct ptree_node
{
   data_type data;                         // data associated with the node
   list< pair<key_type, ptree_node> > children; // ordered list of named children
};

          1, (2,c2)<>(4,c4)<>(5,c5)
       / \  \
      c2 c4 c5
```

<a name=w></a>
### Why PTree
Ptrees can store data to which can be presented in number of data formats: XML, INI, and JSON. ie library provides parsers and generators for xml,ini,json.

## Reading
<a name=rx></a>
### From xml
```cpp
$ cat test.xml
<debug>
    <filename>test.xml</filename>
    <modules>
        <module>Finance</module>
        <module>Admin</module>
        <module>HR</module>
    </modules>
    <level>2</level>
</debug>

$ cat main.cpp
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <string>
#include <set>
#include <exception>
#include <iostream>
using namespace std;
namespace pt = boost::property_tree;

int main() {
    pt::ptree tree;
    pt::read_xml("./test.xml", tree);
    std::string file = tree.get<std::string>("debug.filename");       //Throws exception if path cannot be resolved
    int level = tree.get("debug.level", 0);

    std::set<std::string> modules;
    
    //Use get_child to find the node containing the modules, and iterate over its children
    //If the path cannot be resolved, get_child throws.
    BOOST_FOREACH(pt::ptree::value_type &v, tree.get_child("debug.modules")) {
        modules.insert(v.second.data());
    }
    
    cout << file << endl;          //test.xml
    cout << level << endl;         //2
    for (auto i:modules) {
        cout << i << " ";           Admin Finance HR
    }
    cout << endl;
    return 0;
}
```
