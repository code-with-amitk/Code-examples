### Find pairs with sum=78 in array 6,7,5,1,61,50,73,77,65
Pairs=[1,77] [5,73]

#### Logic-1(Hash Table)      O(n)      //All pair problems can be solved using HT

This is very simple. 
  1. Iterate through the array.
  2. Find difference (temp = to_find_sum - arr[i])
  3. if(temp is found in hash_table)
      - pair is (arr[i], temp)
    - else
      - Insert arr[i] in hashtable

```
void fun(int arr[], int arr_size, int sum)
{
  unordered_set<int> s;
  int temp;
  for (int i = 0; i < arr_size; i++)
  {
    temp = sum - arr[i];

    if (s.find(temp) != s.end())
      cout << "\nPair with given sum " << sum << " is (" << arr[i] << ", " << temp << ")" << std::endl;

      s.insert(arr[i]);
   }
}

int main(){
        int A[] = {6,7,5,1,61,50,73,77,65};
        int to_find_sum = 78, ret;
        std::cout<<"sizeof(A)="<<sizeof(A);
        fun(A, sizeof(A)/sizeof(A[0]), to_find_sum);
}
/*
Output:
 Pair with given sum 78 is (73, 5)
 Pair with given sum 78 is (77, 1)
*/
```

#### Logic-2(Sort)

  1. Sort the array.          std::sort()=>O(nlogn)
  2. Take two index variables
     - Initialize first to the leftmost index: l=0
     - Initialize second  the rightmost index:  r=ar_size-1
  3. while l < r                                        =>O(n)
     - if (A[l] + A[r] == sum)  then return 1
     - else if( A[l] + A[r] <  sum )  then l++
     - else r--
