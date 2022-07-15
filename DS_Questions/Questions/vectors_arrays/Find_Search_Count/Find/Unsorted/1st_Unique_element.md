**First Unique Element**
- [Logic](#l)
- [Complexity](#co)
- [Code](#c]


### First Unique Element/{roduct
- You are given a array of products. You need to find 1st product from array which occurs 1 time only in least possible time.
```c
Example-1:
Input = {"Apple", "Apple", "Computer", "Apple", "Bag"}
Output = Computer

Example-2:
Input = {"Apple", "Apple", "Computer", "Apple", "Computer", "Bag"}
Output = Bag
```

<a name=l></a>
#### Logic
- _1._ Traverse through all products, store count of every product in linked list. insert new elements at beginning
- _2._ Store address of linked list node and product name in unordred_map for O(1) access
```c
|<3,Apple>|<2,Computer>|<1,Bag>|
0x45       0x89        0x91
begin                   end       

|"Bag",0x91|"Computer",0x89|"Apple",0x45|
unordered_map<string, list::iterator>
```

<a name=co></a>
#### Complexity
- **Time:** O(n)
  - 1st for loop, O(n) Traverse products and create list, map
  - 2nd for loop, O(n) Traverse created list to find unique product
- **Space:** 2O(n)
  - O(n): store list
  - O(n): store unordered_map

<a name=c></a>
#### Code
```cpp
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <list>
#include <iterator>
using namespace std;
using List = list<pair<int, string>>;

std::string firstUniqueProduct(const std::vector<std::string>& products) {
    if (!products.size())
        return "";

    List lst;
    unordered_map<string, List::iterator> um;

    for (auto&i:products){                  //Traverse through all products
        auto it = um.find(i);               
        if (it == um.end()){                //if product not found in unordered_map
            lst.push_front({1, i});         //create linked list entry at front
            um[i] = lst.begin();            //store <product, list::iterator> in unordered_map
        }else{
            it->second->first++;            //if product is found, increment count, ie number of occurances of item
        }
    }

    //Start traversal of list from end
    //Whenever entry with count=1 is found return item
    for (auto i=lst.rbegin(); i!=lst.rend(); ++i){
        if (i->first == 1)
            return i->second;
    }
    return "";
}

int main()
{
    //std::vector<std::string> products = { "Apple", "Computer", "Apple", "Bag" };
    std::vector<std::string> products = { "Apple", "Apple", "Computer", "Apple", "Bag"};
    std::cout << firstUniqueProduct(products);
}
```
