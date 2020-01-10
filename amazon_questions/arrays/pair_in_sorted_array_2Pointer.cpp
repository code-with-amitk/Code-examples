/*
 * Problem: Given a sorted array A (sorted in ascending order), having N integers, find if there exists any pair of elements (A[i], A[j]) such that their sum is equal to X.

******* Approach-1      O(n2)********
 - Run 2 for loops
 - Add all elements to each other and find sum
*************************************

******* Approach-2(2 pointer) O(n)****
 - Keep 2 pointers. 1 pointing to start, other to end
 if (start+end<sum)
        start++;
 if (start+end>sum)
        end--;
*************************************
 */
#include<iostream>
using namespace std;

bool approach_2(int arr[], int size, int sum){
        int start,end,i=0,k=size-1;

        while(i<(size-1)){
                start = arr[i];
                end = arr[k];

                if(start+end == sum)
                        return true;

                if(start+end<sum){
                        i++;
                }
                if(start+end>sum){
                        k--;
                }
        }
        return false;
}

bool approach_1(int arr[], int size, int sum){
        for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                        if(arr[i]+arr[j]==sum)
                                return true;

                        if(arr[i]+arr[j]>sum)
                                break;
                }
        }
        return false;
}

int main(){
        int arr[]={1,2,3,4,5,6};
        //cout<<approach_1(arr,(sizeof(arr)/sizeof(int)),20)<<endl;
        cout<<approach_2(arr,(sizeof(arr)/sizeof(int)),9)<<endl;
}
