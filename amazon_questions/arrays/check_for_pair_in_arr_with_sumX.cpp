/*arr: 6,7,5,1,61,50,73,77,65.   To find sum=78.     Pairs=[1,77] [5,73]
Logic-1(Sort):
  a. Sort the array. 1,5,6,7,9,50,61,65,73,77   std::sort()=>O(nlogn)
  b. Take two index variables
     - Initialize first to the leftmost index: l=0
     - Initialize second  the rightmost index:  r=ar_size-1
  c. while l < r                                        =>O(n)
     if (A[l] + A[r] == sum)  then return 1
     else if( A[l] + A[r] <  sum )  then l++
     else r--
*/
#include<iostream>
#include<algorithm>
#include <unordered_set>
int logic1(int arr[], int arr_size, int sum){
        std::cout<<"Inside Logic-1"<<std::endl;
        std::sort(arr, arr + arr_size);

        int front=0, rear=arr_size-1;
        int l;
        for(l=0;l<rear;l++)
                std::cout<<arr[l]<<" ";

        while(front < rear){

        if(arr[front] + arr[rear] == sum){
                std::cout<<"found sum";
                return 1;
        }else if(arr[front] + arr[rear] < sum)
                front++;
        else
                rear--;
        }
        //std::cout<<"\nl="<<l<<" r="<<r;
}

/*
Logic-2: Using Hash Table:      O(n)
This is very simple. 
 a. Iterate through the array.
 b. Find difference of (temp = to_find_sum - arr[i])
 c. if(temp is found in hash_table)
        elements are -> (arr[i], temp)
    else
        Insert arr[i] in hashtable
*/
void usingHashTable(int arr[], int arr_size, int sum)
{
        std::unordered_set<int> s;
        int temp;
        for (int i = 0; i < arr_size; i++) {
                temp = sum - arr[i];

                if (s.find(temp) != s.end())
                std::cout << "\nPair with given sum " << sum << " is (" << arr[i] << ", " << temp << ")" << std::endl;

                s.insert(arr[i]);
        }
}

int main(){
        int A[] = {6,7,5,1,61,50,73,77,65};
        int to_find_sum = 78, ret;
        std::cout<<"sizeof(A)="<<sizeof(A);
//      ret = logic1(A,sizeof(A)/sizeof(A[0]), to_find_sum);
        usingHashTable(A, sizeof(A)/sizeof(A[0]), to_find_sum);
        /*
                Pair with given sum 78 is (73, 5)
                Pair with given sum 78 is (77, 1)
         */
}
