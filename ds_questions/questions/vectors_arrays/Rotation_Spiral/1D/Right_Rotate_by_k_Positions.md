## Right Rotate by k positions
- Array is given and number of times it needed to be rotated is given. Return rotated array
```c
Input: arr[] = [1,2,3,4,5,6,7], k = 3
Output: [5, 6, 7, 1, 2, 3, 4]

7 1 2 3 4 5 6   //1st rotation
6 7 1 2 3 4 5   //2nd rotation
5 6 7 1 2 3 4   //3rd Rotation
```

## Logic
- If rotation_size(K) > size_of_array(N). Calculate actual_rotation(K) = rotation_size(K) % size_of_array(N)

### Approach-1
- **Complexity:** n: Array size, (m = arrSize%k) Actual Number of rotations needed
  - Time: O(nm)
  - Space: O(1)   //Constant
- **Logic**
```c
last = 7

    1   2   3   4   5   6   7
                            j
                          
j=6  v[6] = v[5]. --j
    1   2   3   4   5   6   6
                            j                          
j=5  v[5] = v[4]. --j
    1   2   3   4   5   5   6
                        j                          
                            
```
- **Code**
```c
void RightRotate(vector<int>& v, int k){
  int mod = v.size() % k;
  if (mod == 0){
    //No rotation needed
    return;
  }

  for (int i=0;i<mod;++i){  
    int last = v[v.size()-1];    
    for(int j = v.size()-1; j > 0; --j){
      v[j] = v[j-1];
    }
    v[0] = last;
  }
}

int main(){
  vector<int> a = {1,2,3,4,5,6,7};
  int k=4;
  RightRotate(a,k);
  for (auto i:a)
    std::cout<<i<<" ";
}
# ./a.out
5 6 7 1 2 3 4
```
