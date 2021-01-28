/* Logic:
 1. Sort the array
 2. nth_largest_element = arr[sizeof(arr) - n]
*/

#include<iostream>
#include<algorithm>
int kthLargest(int arr[], int n, int k)
{
        std::sort(arr, arr + n);              //Implemented internally as Quick-Sort O(nlogn)
        return arr[n - k];
}

int main(){
        int arr[] = {4,6,7,10,4,62};    //4,4,6,7,10,62.        Answer-6
        int n = sizeof(arr) / sizeof(arr[0]);
        int k = 4;
        std::cout<<"kth lar="<<kthLargest(arr, n, k)<<std::endl;
        return 0;
}
