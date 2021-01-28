/*      merge-two-singly-ll.cpp

***********Logic-1(forward_list::merge())***************
- list1.merge(list2) merges lists into list1 in ascending order
- Drawback: 
        a. Both containers should already be ordered else fl.sort()
        b. It does not checks for duplicate entries!! else fl.unique()
        
Complexity: Time:O(n), Space:O(1)

=> To merge in decending order:
list1.merge(list2, cmp_fun);
bool cmp_fun(int a, int b)
{
    return a > b;
}
**************************************
*/

#include<iostream>
#include<forward_list>
#include<algorithm>
using namespace std;

int main(){
        forward_list<int> a = {1,2,3,4,7};
        forward_list<int> b = {4,5};

        a.merge(b);                     //1 2 3 4 4 5 7
        a.unique();                     //1 2 3 4 5 7
        cout<<"Merged-a:";
        for (auto i = a.begin(); i != a.end(); i++)
                cout << *i << " ";
        cout<<"\n";
}
/*
Output:
# ./a.out 
1 2 3 4 5 7
*/
