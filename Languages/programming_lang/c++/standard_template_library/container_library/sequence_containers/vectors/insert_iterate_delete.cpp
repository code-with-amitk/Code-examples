/*      insert_iterate_delete_vector.cpp

 A. INSERTION
    A1. Appends the value to the end of the container.
      void push_back( T&& value );      //Since C++11
      Return value: None
      Complexity: Amortized constant.

 B. TRAVERSING/ITERATING VECTOR

 C. ERASE/DELETE/REMOVE
    C1. Remove element at position
        iterator erase( const_iterator pos );   //Since C++11

    C2. Removes the elements in the range [first, last).
        iterator erase( const_iterator first, const_iterator last );  //Since C++11

    C3. Erases all elements from the container. After this call, size() returns 0.
        void clear() noexcept;  //Since C++11
        parameters: None
        Return values: None
        Complexity: Linear in the size of the container, i.e., the number of elements.
        
*/
#include<iostream>
#include<vector>
using namespace std;

int main(){
        vector<int> v(5,10);            //array of size=5, Each element value=10
        for(auto i:v)
                cout<<i<<" ";           //10 10 10 10 10
        cout<<endl;

        /**********A. INSERTION*********/
        //A1. Insert at end
        v.push_back(11);
        for(auto i:v)
                cout<<i<<" ";           //10 10 10 10 10 11
        cout<<endl;


        /**********B. TRAVERSING/ITERATING*********/
        for(int i=0;i<v.size();i++)
                cout<<v[i]<<",";        //10,10,10,10,10,11,
        cout<<endl;
        for(auto i=v.begin();i!=v.end();i++)
                cout<<*i<<";";          //10;10;10;10;10;11;
        cout<<endl;
        vector<int>::iterator itr;
        for(itr=v.begin(); itr!=v.end(); itr++) //10'10'10'10'10'11'
                cout<<*itr<<"'";
        cout<<endl;


        /*******C. DELETION/REMOVAL*******/
        //C1. Erase at position
        v.erase(v.begin());
        for(auto i:v)
                cout<<i<<" ";           //10 10 10 10 11
        cout<<endl;

        //C2. Remove in range
        v.erase(v.begin()+1, v.end()-1);
        for(auto i:v)
                cout<<i<<" ";           //10 11
        cout<<endl;

        //C3. Empty the container
        v.clear();
        cout<<v.size();                 //0
        cout<<endl;
}
