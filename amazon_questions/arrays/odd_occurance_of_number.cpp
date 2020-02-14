/*      odd_occurance_of_number.cpp

Problem: Given a unsorted array where every number occur even number of times except one number, find the odd occurring number.
arr[] = {1, 1, 4, 9, 6, 8, 6, 4, 8 }
Answer: 9

*********Approach-1*************
1. Sort:        O(nlogn)
2. Binary search: O(logn)
Complexity: O(n+1(logn))
********************************

********Approach-2**************
Using xor operator.
Complexity: O(n)
********************************
*/
#include <iostream>
using namespace std;

int main(void)
{
    int num = 0;

    int a[] = {1, 1, 4, 9, 6, 8, 6, 4, 8 };
    int n = sizeof(a) / sizeof(a[0]);

    for (int i = 0; i < n; i++)
        num ^= a[i];

    cout<<num;
}
/*
Output:
9
*/
