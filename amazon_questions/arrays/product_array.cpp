/*
https://www.geeksforgeeks.org/a-product-array-puzzle
/
A Product Array Puzzle:
Given an array arr[] of n integers, construct a Product Array prod[] (of same size) such
that prod[i] is equal to the product of all the elements of arr[] except arr[i]. 

      Input arr[] = {10,3,5,6,2}
      Output Array = {180,600,360,300,900}    //180=3*5*6*2, 600=10*5*6*2 so on
        
      Input = {1,2,3,4}
      Output = {24,12,8,6}      //24=2*3*4, 12=1*3*4, 8=1*2*4

********************Logic********************

Approach-1(Brute-force): O(n sqaure)
- Run 2 nested for() loops, Calculate the product and store in 2nd array


Approach-2(Time Complexity=O(n)):
- 1st Traverse Array left to right using for() loop. 
        Take 2nd array=sizeof(original array)
        Take temp variable.
        Calculate temp = temp*ar[i] and store in 2nd_array.

- 2nd Traverse Array right to left using for() loop.
        Do same for reverse side as well.
- Spend some time but was not clear with approach followed to solve the question.
Time Complexity = O(n)+O(n) = O(n)      //Since 2 for() loop are seperate not nested.
Space Complexity = O(n)                 //Used Extra array
********************************************* 
*/

#include <iostream>
using namespace std;

void approach_2(int arr[], int sizeofArr){

        int i, temp = 1;

        if (sizeofArr == 1){
                cout << 0;
                return;
        }

        int p[sizeofArr] = {0}; //Product Array

        //In this loop, temp variable contains product of elements on left side excluding arr[i]
        for (i = 0; i < sizeofArr; i++) {
                p[i] = temp;
                temp = temp * arr[i];
        }

        temp = 1;

        // In this loop, temp variable contains product of elements on right side excluding arr[i]
        for (i = sizeofArr - 1; i >= 0; i--) {
                p[i] = p[i] * temp;
                temp = temp * arr[i];
        }

        // print the constructed prod array
        for (i = 0; i < sizeofArr; i++)
                cout << p[i] << " ";
}

//Brute Force: O(n sqaure)
void approach_1(int arr[], int sizeofArr){
        int i, j, t;

        if (sizeofArr == 1){
                cout << 0;
                return;
        }

        int p[sizeofArr] = {0}; //Product Array

        for(i=0;i<sizeofArr;i++){
                t=1;
                for(j=0;j<sizeofArr;j++){
                        if(i==j)
                                continue;
                        t = t*arr[j];
                }
                p[i]=t;
        }

        for (i = 0; i < sizeofArr; i++)
                cout << p[i] << " ";
}

int main(){
        int arr[] = {1,2,3,4};
        int size = sizeof(arr) / sizeof(arr[0]);

        cout << "The product array is: \n";
        //approach_2(arr, size);
        approach_1(arr, size);
}
/*
Output:
# ./a.out 
The product array is: 
24 12 8 6
*/
