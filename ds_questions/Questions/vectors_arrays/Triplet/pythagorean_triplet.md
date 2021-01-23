### Problem
- Check if Pythagoras triplet is present in array? 
```c++        
ar[]={3, 2, 4, 6, 5} 
Answer: yes //3,4,5
```
### Approach-1  //3 nested for loops O(n<sup>3</sup>)
```c++
  x = a[0]*a[0]     
  y = a[1]*a[1]     
  z = a[2]*a[2]
  if (a==b+c || b==c+a || c==a+b)//check any combination satisfies the rule?
    return true
```

### Approach-2  //Square, Sort 2O(n)+O(nlogn)
```c++
Step-1: Square the array        //O(n)
        {9, 4, 16, 36, 25}
Step-2: Sort the array          //O(nlogn)
        {4, 9, 16, 25, 36}
Step-3: 3 pointer approach to find triplet       //O(n)
        {4, 9, 16, 25, 36}
        /\         /\  /\
        a           b   c
        a = last_element_of_array, Largest
        l = first_element
        r = last-1
        while (a < b) {
                if(ar[a] + ar[b] == ar[c])
                        found     
                if(a + b < c)
                        a++
                else
                        b--
        }
```

### Approach-3  //Hash Table
```c++
1. Square original array inplace  //O(n)
        {9, 4, 16, 36, 25}
2. Store unique squares in hash-table.
        {9, 4, 16, 36, 25}
3. Using 2 for loops check sum of 2 elements is present in HT or not.
```

### Code-3
```c++
#include<unordered_set>
unordered_set<int> ht;

bool checkTriplet(int a[], int n){
        for(int i=0;i<n;i++){                   //O(n)
                a[i]=a[i]*a[i];
                if(ht.find(a[i]) == ht.end())
                        ht.insert(a[i]);
        }

        for(int i=0;i<n;i++){
                for(int j=1;j<n;j++){
                        if(ht.find(a[i]+a[j]) != ht.end()){
                                cout<<a[i]<<" "<<a[j];
                                return true;
                        }
                }
        }
        return false;
}

int main()
{
    int arr[] = { 3, 2, 4, 6, 5 };
    int sizeOfArr = sizeof(arr) / sizeof(arr[0]);
    if (checkTriplet(arr, sizeOfArr))
        cout << "Yes";
    else
        cout << "No";
}
```
