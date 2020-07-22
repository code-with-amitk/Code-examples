[Problem](https://leetcode.com/discuss/interview-question/375262/twitter-oa-2019-partitioning-array)

## Problem
- Given an array of integers. if its possible to partition array into subsequence of length k each.
  - if possible(return yes)
  - if not possible(return no)
- Conditions for subsequence:
  - Each element in array should appear only once in sub-sequence.
  - All numbers in subsequence should be distinct
  - Same valued numbers in array should be in different sub-sequences.
  - All element should be used

- Example-1:
```
  Input: arr=[1,2,3,4] k=2
  Output: Yes. {1,2} {3,4}
```  

- Example-2:
```
  Input: arr={1,2,2,3} k=3
  Output: False. 1 sub-seq={1,2,3} But 2 is left.
  There is no way to partition arr[] into subsequence of len=3 satisfying above conditions
```

- Example-3:
```
  Input: arr={1,2,2,3,4,5}, k=3
  Output: Yes. {1,2,3}{2,4,5}
```

## Logic(Very Simple):
  {1,2,3,4}. k=3
- if number of elements in array is not multiple of k, return No.
  - Example:  {1,2,3,4} k=3. This arr cannot be partitioned in sub-seq of len=3
- Create Hash table containing count of occured elements.
```
     elememt | count
        1       1
        2       1
        3       1
        4       1
    -> if count > k return No.
```

## Code
```
string partitionArray(vector<int>&arr, int k)
{
    if(arr.size() % k != 0)
        return "No";

    unordered_map<int,int> um;

    for(int &i : arr)
    {
      cout<<"i="<<i<<endl;
        um[i]++;
        if(um[i] > arr.size()/k)
            return "No";
        cout<<"um["<<i<<"]="<<um[i]<<endl;
    }
    return "Yes";
}

int main() {
    //vector<int> arr = {1,2,2,3};
    //cout<<partitionArray(arr,3);

    vector<int> arr = {1,2,2,3,4,5};
    cout<<partitionArray(arr,3);

    return 0;
}
```
