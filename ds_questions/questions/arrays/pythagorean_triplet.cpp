#include<unordered_set>
using namespace std;
unordered_set<int> ht;

/*         pythagorean_triplet.cpp

Problem: Check if Pythagoras triplet is present in array. ar[]={3, 2, 4, 6, 5}. a2 + b2 = c2. 3,4,5
Answer: yes

*****Approach-1[3 nested for loops O(n3)]********
        x = a[0]*a[0]     
        y = a[1]*a[1]     
        z = a[2]*a[2]
        if (a==b+c || b==c+a || c==a+b)//check any combination satisfies the rule?
                return true
************************************************

*****Approach-2[Square, Sort] O(n2)+O(nlogn)********
- Square elements in original array, Sort.
- iterate through the array to find triplet       O(n2)
        a = last_element_of_array, Largest
        l = first_element
        r = last-1
        while(l<r)
                if(ar[l] + ar[r] == ar[a])
                        found
                if(first_element+(last-1) < a)
                        first_element++
                else
                        last-1-1
************************************************

*****Approach-3 Hash-table O(n2)********
- Square original array inplace  O(n)
- Store unique squares in hash-table.
- Using 2 for loops check sum of 2 elements is present in HT or not.
*****************************************
*/

bool checkTriplet(int a[], int n){
        for(int i=0;i<n;i++){                   //O(n)
                a[i]=a[i]*a[i];
                if(ht.find(a[i]) == ht.end())
                        ht.insert(a[i]);
        }

        for(int i=0;i<n;i++){
                for(int j=1;j<n;j++){
                        if(ht.find(a[i]+a[j]) != ht.end()){
                                cout<<a[i]<<" "<<a[j];
                                return true;
                        }
                }
        }
        return false;
}

int main()
{
    int arr[] = { 3, 2, 4, 6, 5 };
    int sizeOfArr = sizeof(arr) / sizeof(arr[0]);
    if (checkTriplet(arr, sizeOfArr))
        cout << "Yes";
    else
        cout << "No";
}
