/*
Namespace: Logical grouping of: classes, objects, variables etc. These are used to avoid name conflict.
 */
#include<iostream>
using namespace std;

int a = 10;

namespace A{
        int a;
}

int main(){
        int a = 20;

        /*Initializing namespace*/
        A::a = 30;
        cout<<"namespace's a "<<A::a<<endl;    //30

        /*Global variable*/
        {
                extern int a;
                cout<<"Global a: "<<a<<endl;    //10
        }


        cout<<"Main's a: "<<a<<endl;            //20
        return 0;
}

/*
# ./a.out 
namespace's a 30
Global a: 10
Main's a: 20
 */
