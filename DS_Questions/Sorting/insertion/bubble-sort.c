/* Name: Smallest element Bubbles at top
 * Time Complexity: O(n2)//Worst	O(n2)//Best	O(n2)//Avg
 * Space Complexity: O(1)//constant ie No extra space needed
 *
 * Logic:
 * Step-1: Take an unsorted array. arr[n]
 * Step-2: Using 2 for loops
 * 	2a. Compare arr[i] with arr[i+1]. if(arr[i]>arr[i+1]) swap
 * 	2b. Compare arr[i] with all other elements in array
 * 	2c. Once arr[i] is compared, Move to arr[i+1] and perform same steps as in 2a, 2b
 */

#include<stdio.h>
void main(){

	int arr[5]={4,2,5,1,3};
        int i,j,temp, size=sizeof(arr)/sizeof(int);

        for(i=0;i<size;i++){
                for(j=i+1;j<size;j++){
                        if(arr[i]>arr[j]){	//x,y
				arr[i] = arr[i] + arr[j];	//x=x+y
				arr[j] = arr[i] - arr[j];	//y=x-y
				arr[i] = arr[i] - arr[j];       //x=x-y
                        }
                }
        }

        for(i=0;i<size;i++)
	        printf("\n%d",arr[i]);
}
