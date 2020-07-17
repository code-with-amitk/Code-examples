/*              aggregation.cpp
  
Aggregation:
Contained Object can exist without container Object. Contained object can belong to different classes at same time. Contained class does not delete container class object. Owner-ship is present. Contained class have pointer to object of contained class

 */
#include <string>
#include <iostream>
using namespace std;

class tree{
    string name;
public:
    tree(string t):name(t){}
    string getName() { return name;}
};

class sunlight{
    tree *p;
public:
    sunlight(tree *t):p(t){}
};

int main(){
    tree *ptr = new tree("palm");               //plam can exist with ant without sunlight
   {
        sunlight d(ptr);

    } // sunlight object goes out of scope here and is destroyed

    std::cout << ptr->getName() << " Exists without Sunlight\n";

    delete ptr;

    return 0;
}
/*
./a.out
# ./a.out
palm Exists without Sunlight

*/
