**PropertyTree**
- [Why Ptree](#w)
- **Reading**
  - [From xml](#rx)
- **Writing**
  - [To xml](#wx)

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

## Read
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
    pt::ptree tree;                                                   //Create empty property tree object
    pt::read_xml("./test.xml", tree);                                 //Parse the XML into the property tree
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

## Write
<a name=wx></a>
### To XML
```cpp
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

void writeX(string& strFile){
    pt::ptree tree;                                 //Create empty property tree object
    
    // Put the simple values into the tree. The integer is automatically converted to a string. 
    //Note that the "debug" node is automatically created if it doesn't exist.    
    tree.put("debug.filename", strFile);
    tree.put("debug.level", 5);                       //put() overwrites existing nodes

    std::set<std::string> dept;
    dept.insert("IT");
    dept.insert("HR");
    
    // Add all the modules. Unlike put, which overwrites existing nodes, add() adds a new node at the lowest level, so the "modules" node will have
    // multiple "module" children.
    BOOST_FOREACH(const std::string &s, dept)
        tree.add("debug.modules.module", s);
        
    pt::write_xml(strFile, tree);               // Write property tree to XML file
}

int main() {
    string file = "output.xml";
    writeX(file);
}

$ g++ main.cpp

$ cat output.xml
<?xml version="1.0" encoding="utf-8"?>
<debug>
  <filename>output.xml</filename>
  <level>5</level>
  <modules>
    <module>HR</module>
    <module>IT</module>
  </modules>
</debug>
```
