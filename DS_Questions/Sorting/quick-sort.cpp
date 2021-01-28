/*      quick-sort.cpp          //Divide and conquer algo

https://www.youtube.com/watch?v=QN9hnmAgmOc [if confused]

**************Logic is very simple***************
Crux of Algo.
a. Any random element is selected as Pivot. Eg: pivot=a[0]=6
b. Find the final place for pivot in the array. 
Final place(index=2) will be the position which it will have in sorted array.
sorted array would be: 1 5 6 7 8 9.

How to find final place of pivot?
  6   7   8   9   1   5
start                end
Iterate Until(start < end)
       if(element_at_start <= pivot){ 
        it ok. 
        Because on left of pivot elements should be smaller.
        start++
       }else
         stop

      if(element_at_end > pivot){ it ok.
        Because on right of pivot elements should be greater.
        end--
      }else
        stop
 
     - we found elements where element_at_start>pivot & 
     element_at_end<pivot. Swap needed
     if(start < end)
       - Swap end and start elements
}
- Now end crossed start, swap element_pointed_by_pivot with end_element.

Recursively do this for left and right sub-arrays.

Complexity:
        worst: O(n2)
        Avg: O(nlogn)
        Best: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

int part(int a[], int l, int h){
        int pivot = a[l];
        int start = l;
        int end = h;
        int temp;
        while(start < end){
                while(a[start] <= pivot)
                        start++;

                while(a[end]>pivot)
                        end--;

                if(start<end){  //Swap
                        temp = a[start];
                        a[start]=a[end];
                        a[end]=temp;
                }
        }
        temp = a[l];
        a[l] = a[end];
        a[end]=temp;
        return end;
}

void qs(int a[], int l, int h){
    if (l < h){
        int pi = part(a, l, h);

        qs(a, l, pi - 1);
        qs(a, pi + 1, h);
    }
}

int main(){
    int a[] = {6, 7, 8, 9, 1, 5};
    int n = sizeof(a) / sizeof(a[0]);
    qs(a, 0, n - 1);

    cout << "Sorted array is: \n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
/*
Output
# ./a.out
Sorted array is:
1 5 6 7 8 9
*/
