/*
Namespace: Logical grouping of: classes, objects, variables etc. These are used to avoid name conflict.
 */
#include<iostream>
using namespace std;

int a;
namespace A{
        int a;
}

int main(){
        a = 10;
        A::a = 20;
        cout<<"A::a "<<A::a<<endl;    //20
        cout<<"Global a: "<<a<<endl;
        return 0;
}

/*
# ./a.out 
A::a 20
Global a: 10
 */
