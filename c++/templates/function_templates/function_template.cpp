/*  function_template.cpp

Template is compiler abstraction.
 
Compiler creates the specialization for each type at compile time.
 */
#include<iostream>
using namespace std;

template <class T>                      //OR template <typename T>
T maxof(T a, T b){
        return (a>b)?a:b;
}

/*
//Specialization build for int
int maxof(int a, int b){
        return (a>b)?a:b;
}

//Specialization build for string
string maxof(string a, string b){
        return (a>b)?a:b;
}
*/

int main(){
        cout << maxof(4,5) <<endl;               //5
 
        cout << maxof(5,7.8) <<endl;             //error: no matching function for call to ‘maximum(int, double)’
 
        cout << maxof("hellome","hello") <<endl;           //hellome
 
        return 0;
}
