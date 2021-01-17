## Pairs with sum X
- Find pairs with specific 
```c++
arr = {6,7,5,1,61,50,73,77,65}, sum=78
ans=[1,77] [5,73]
```

## 1. Approach  //Hash Table
### Logic
  - *1.* Insert compelte array into unordered_set<int>
  - *2.* iterate through array and find (sum - present) in hash table
### Complexity
  - *Space:* O(n) 
  - *Time:* O(n)  //Traversing entire array
### Code
```c++
void fun(int arr[], int arr_size, int sum){
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
