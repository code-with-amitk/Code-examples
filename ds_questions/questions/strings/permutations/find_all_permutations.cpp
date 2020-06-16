/*
        find_all_permutations.cpp

Question:Find all permutations of given string. Eg: ABC
Answer: ABC  ACB  BAC  BCA  CBA  CAB

Logic:
https://www.youtube.com/watch?v=GuTPwotSdYw
A B C
0 1 2

                       ABC
         ------------------------------
         |              |             |
         |A-A           |A-B          |A-C
         |              |             |
        ABC            BAC           CBA                //Swap all indexes with index=0. (index0 swapped-with index1) & (index0 swapped-with index2)
         |              |             |
       ------       --------      ---------
       |    |       |      |      |       |
    B-B| B-C|    A-A|   C-A|   B-B|    B-A|     
      ABC  ACB     BAC    BCA    CBA     CAB            //Keeping index=0 fixed, Swap index=1 with rest of indexes in array

Time Complexity: O(n*n!), where n is number of elements in string     
*/

#include<iostream>
using namespace std;

//This function works on above logic, But
//unfortunately its complex to understand
//And better to cram.
void perm(string a, int l, int r)
{
    if (l == r)
        cout<<a<<endl;
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(a[l], a[i]);
            perm(a, l+1, r);
            swap(a[l], a[i]);
        }
    }
}

int main(){
        string t = "abc";
        perm(t, 0, t.size()-1);
}
/*Output:
# ./a.out 
abc
acb
bac
bca
cba
cab
*/
