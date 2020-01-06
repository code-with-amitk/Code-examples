#include<iostream>
using namespace std;

class A{
public:
    A() { cout<<"base ctr"<<endl;  }
    ~A() { cout<<"base dtr"<<endl;  }
};

class B: public A {
public:
    B() { cout<<"Derv ctr"<<endl;  }
    ~B() { cout<<"Derv dtr"<<endl;  }
};

int main(){
    B obj;
}
/*
Output:
base ctr
Derv ctr
Derv dtr
base dtr
 */
