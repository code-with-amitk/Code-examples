#include <limits.h>
  
void merge_sort(int[], int, int);
  
int solution(int A[], int N) {
    // write your code in C90
  
    // Apply merge sort (takes O(nlogn))
    merge_sort(A, 0, N-1);
     
    // Loop will take O(n) hence total time  in O(nlogn)
    int min_dist = INT_MAX;
    int dist = 0;
    int i;
    for(i = 1; i < N; i++)
    {
        dist = A[i] - A[i - 1];
        if (min_dist > dist)
        {
            min_dist = dist;
        }
    }
     
    return min_dist;
}
  
#define SIZE 1000000
void merge(int arr[],int min,int mid,int max)
{
    int tmp[SIZE];
    int i,j,k,m;
    j = min;
    m = mid+1;
    for(i = min; j <= mid && m <= max ; i++)
    {
        if(arr[j] <= arr[m])
        {
            tmp[i] = arr[j];
            j++;
        }
        else
        {
            tmp[i] = arr[m];
            m++;
        }
    }
    if(j > mid)
    {
        for(k = m; k <= max; k++)
        {
            tmp[i] = arr[k];
            i++;
        }
    }
    else
    {
        for(k = j; k <= mid; k++)
        {
            tmp[i] = arr[k];
            i++;
        }
    }
     
    for(k = min; k <= max; k++)
        arr[k] = tmp[k];
}
  
  
void merge_sort(int arr[],int min,int max)
{
    int mid;
    if(min < max)
    {
        mid = (min + max)/2;
        merge_sort(arr, min, mid);
        merge_sort(arr, mid+1, max);
        merge(arr, min, mid, max);
    }
}
