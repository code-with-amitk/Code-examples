## Code
```c++
#include<iostream>
using namespace std;

class Plug{             //ABSRACT CLASS
public:
        void virtual plug_fun()=0;
};

class flatPinPlug : public Plug{
public:
        void plug_fun(){
                cout<<"Inside flatPin class\n";
        }
};

class switchBoard {     //ABSTRACT CLASS
public:
  void virtual switchBoard_fun()=0;
};

class roundSwitchBoard : public switchBoard {   //CONCREATE CLASS
public:
  void switchBoard_fun(){
          cout<<"Inside roundSwitchBoard class\n";
  }
};

class Adapter : public Plug {
public:
  switchBoard *sbObj;                   //Aggregation
  Adapter(switchBoard *t):sbObj(t){}
  void plug_fun(){
        cout<<"Adapter Taking signal from Plug and passing to Switchboard\n";
        sbObj->switchBoard_fun();
  }
};
// Client code

int main(){
  roundSwitchBoard *ptr = new roundSwitchBoard; // Adaptee
  // Target = Adapter(Adaptee)
  Plug *adapter = new Adapter(ptr);
  adapter->plug_fun();
}
/*
Output:
# ./a.out
Adapter Taking signal from Plug and passing to Switchboard
Inside roundSwitchBoard class
 */
```
