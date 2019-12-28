/*
 Question: Find occurences of an element in sorted array. Array element is always smaller than sizeof array.
 Array = {1,1,1,1,2,2,3}
 find occurences of 2
 Answer = 2

  Logic-1: Traverse array linearly count number of occurrences of element. Complexity=O(n)
 
  Logic-2: Binary search + Linear count.         O(logn) + count
   -   Find element using binary search.
   -   Once element is found count left, right.
 
  Logic-3(Binary Search): Complexity=O(logn)
   - Traverse in binary search manner.
   - get index of the first occurrence of x in arr[]. Let the index of the first occurrence be i.
   - get index of the last occurrence of x in arr[]. Let the index of the last occurrence be j.
   - Output  (j - i)
*/

#include <stdio.h>
int BinarySearch(int A[], int sizeofA, int element_to_find, int leftOrRightSearch)
{
        int low = 0, high = sizeofA - 1, result = -1;

        while (low <= high)
        {
                int mid = (low + high)/2;

                if (element_to_find == A[mid])
                {
                        result = mid;
                        if (leftOrRightSearch){         //Let's search left occurence of element from mid
                                high = mid - 1;
                        }else{
                                low = mid + 1;
                        }
                }else if (element_to_find < A[mid]){
                        high = mid - 1;
                }else{
                        low = mid + 1;
                }
        }

        return result;
}

int main(void)
{
//      int A[] = {2, 5, 5, 5, 6, 6, 8, 9, 9, 9}, to_find=5;
        int A[] = {1,1,1,1,2,2,3}, to_find = 2;

        int sizeofA = sizeof(A)/sizeof(A[0]);

        int first = BinarySearch(A, sizeofA, to_find, 1);  // 1 for first occurrence
        int last = BinarySearch(A, sizeofA, to_find, 0);   // 0 for last occurrence

        int count = last - first + 1;

        if (first != -1){
                printf("Element %d occurs %d times.", to_find, count);
        }else{
                printf("Element not found in the array.");
        }
        return 0;
}
