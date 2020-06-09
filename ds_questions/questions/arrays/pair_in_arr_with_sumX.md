## Problem: Find pairs with sum=78 in array 6,7,5,1,61,50,73,77,65.
Pairs=[1,77] [5,73]

#### Logic-1(Sort)
  a. Sort the array.          std::sort()=>O(nlogn)
  b. Take two index variables
     - Initialize first to the leftmost index: l=0
     - Initialize second  the rightmost index:  r=ar_size-1
  c. while l < r                                        =>O(n)
     - if (A[l] + A[r] == sum)  then return 1
     - else if( A[l] + A[r] <  sum )  then l++
     - else r--
       
### Logic-2(Hash Table)      O(n)      //In fact all pair problems can be solved using HT
This is very simple. 
  a. Iterate through the array.
  b. Find difference (temp = to_find_sum - arr[i])
  c. if(temp is found in hash_table)
      - pair is (arr[i], temp)
    - else
      - Insert arr[i] in hashtable

```
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
        usingHashTable(A, sizeof(A)/sizeof(A[0]), to_find_sum);
}
/*
Output:
 Pair with given sum 78 is (73, 5)
 Pair with given sum 78 is (77, 1)
*/
```
