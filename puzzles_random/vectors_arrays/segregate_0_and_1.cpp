/*	segregate_0_and_1.cpp
Given an array of 0s and 1s in random order.
Segregate 0s on left side and 1s on right side of the array. Traverse array only once.

Input array   =  [0, 1, 0, 1, 0, 0, 1, 1, 1, 0] 
Output array =  [0, 0, 0, 0, 0, 1, 1, 1, 1, 1] 

*********LOGIC***************
a. Take left, right pointer. leftPtr=0, rightPtr=end
b. move left pointer to right until you find 1
c. move right pointer to left until you find 0
d. Swap elements at left and right pointer.

COMPLEXITY:
TIME: O(n)
Space: O(1)
*****************************
*/
#include<iostream>
using namespace std;

void fun(int a[],int size){
	int leftPtr=0,rightPtr=size;

	while(leftPtr < rightPtr){

		while(a[leftPtr]==0){
			leftPtr++;
		}
                while(a[rightPtr]==1){
                        rightPtr--;
                }

		if(leftPtr < rightPtr){
			a[leftPtr] = 0;
			a[rightPtr] = 1;
			rightPtr--;
			leftPtr++;
		}
	}
	for(int i=0;i<size;i++){
		cout<<a[i]<<" ";
	}
}

int main(){
	int a[]={1, 0, 1, 0, 0, 1, 1, 1, 0};
	fun(a,sizeof(a)/sizeof(int));
}
