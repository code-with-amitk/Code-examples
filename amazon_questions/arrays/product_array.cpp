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
Consider this array [2, 3, 4, 5]    
                     0  1  2  3
it's resulting arra [60, 40, 30, 24] 
Calculated using    [3*4*5, 2*4*5, 2*3*5, 2*3*4]
                     1*2*3  0*2*3  0*1*3  0*1*2
Can you see: For every index i We need product of all values to its left with all values to its right?

Loop-1: Traverse Array from left to right using for(), Fill left[] with product of all elements on left
//There are no values to the left of index 0 & no values to the right of index arr.length - 1, 
we can use 1 which is neutral to multiplication.
 - Fill int left[] = [1, 1*2, 1*2*3, 1*2*3*4]

Loop-2: Traverse Array from right to left using for(), Fill right[] with product of all elements on right.
 - Fill int right[] = [3*4*5*1, 4*5*1, 5*1, 1]

Answer:
      for(int i=0;i<sizeofArr -1; i++)
            cout<<left[i]*right[i]

Time Complexity = O(n)+O(n) = O(n)      //Since 2 for() loop are seperate not nested.
Space Complexity = O(n)                 //Used Extra array
********************************************* 
*/

#include <iostream>
using namespace std;

void approach_2(int arr[], int sizeofArr){
        int left[sizeofArr]={0},right[sizeofArr]={0}, i;
        
        for(i=0;i<sizeofArr;i++){   //Calculate product of left array for each element
                if(i==0)
                        left[i] = 1;
                else
                        left[i] = left[i-1]*arr[i-1];
        }

        for(i=(sizeofArr-1);i>=0;i--){   //Calculate product of right array for each element
                if(i==(sizeofArr-1))
                        right[i] = 1;
                else
                        right[i] = right[i+1]*arr[i+1];
        }

        for (i = 0; i < sizeofArr; i++)
                cout << left[i]*right[i] << " ";
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
