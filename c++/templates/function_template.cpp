/*
Function template
 - template <class T>. T is template variable
 */
#include<iostream>
using namespace std;

template <class T>                      //OR template <typename T>
T maximum(T a, T b){
        return (a>b)?a:b;
}

int main(){
        cout<<maximum(4,5)<<endl;               //5
        cout<<maximum(5.5,7.8)<<endl;           //7.8
        cout<<maximum(5,7.8)<<endl;             //error: no matching function for call to ‘maximum(int, double)’
        cout<<maximum('a','b')<<endl;           //b
        return 0;
}
