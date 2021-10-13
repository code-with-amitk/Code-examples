**PropertyTree**
- [Why Ptree](#w)
- **Reading**
  - [1. From xml](#rx)
  - [2. From json](#rj)
- **Writing**
  - [1. To xml](#wx)
  - [2. To json](#wj)

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
### 1. From xml
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

<a name=rj></a>
### From Json
```cpp
$ cat test.json
{
    "height" : 320,
    "some" :
    {
        "complex" :
        {
            "path" : "hello"
        }
    },
    "animals" :
    {
        "rabbit" : "white",
        "dog" : "brown",
        "cat" : "grey"
    },
    "fruits" : ["apple", "raspberry", "orange"],
    "matrix" : [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
}

$ cat main.cpp
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <string>
#include <set>
#include <exception>
#include <iostream>
using namespace std;
void readJ() {
    pt::ptree tree;
    pt::read_json("./test.json", tree);
    int height = tree.get<int>("height", 0);
    std::string msg = tree.get<std::string>("some.complex.path");

    std::vector< std::pair<std::string, std::string> > animals;
    // Iterator over all animals
    for (pt::ptree::value_type &animal : tree.get_child("animals"))
    {
        // Animal is a std::pair of a string and a child

        // Get the label of the node
        std::string name = animal.first;
        // Get the content of the node
        std::string color = animal.second.data();
        animals.push_back(std::make_pair(name, color));
    }
    std::vector<std::string> fruits;
    for (pt::ptree::value_type &fruit : tree.get_child("fruits"))
    {
        // fruit.first contain the string ""
        fruits.push_back(fruit.second.data());
    }

    pt::write_json("output.json", tree);                                 //WRITTEN to json
    cout << endl;
}
```

## Write
<a name=wx></a>
### 1. To XML
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

<a name=wj></a>
### To json
```json
$ cat main.cpp
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <string>
#include <set>
#include <exception>
#include <iostream>
using namespace std;
int main() {
    pt::ptree root;
    
    vector<pair<string,int>< vec = {
      {"amit", 1}, {"ram", 5}, {"sunny", 10}
    };
    pt::ptree top_words;
    for (auto &i:vec)
        top_words.put(i.first, i.second);
    root.add_child("top_words", top_words);

    vector<int> vecIndex = {1,2,8};
    pt::ptree index_of_smileys;
    for (auto &i:vecIndex) {
        pt::ptree temp;
        temp.put_value(i);
        index_of_smileys.push_back(std::make_pair("", temp));
    }
    root.add_child("index_of_smileys", index_of_smileys);

    pt::write_json("output.json", root);
}    

$ cat output.json
{
    "top_words":
    {
        "amit": 1,
        "ram": 5,
        "sunny": 9
    },
    "index_of_smileys": [
        1,
        2,
        8
    ],
}
```
