## Left Rotation of Array
```c
Input: arr[] = [1,2,3,4,5,6,7], k = 3
Output: [4, 5, 6, 7, 1, 2, 3]

2 3 4 5 6 7 1   //1st left rotation
3 4 5 6 7 1 2   //2nd left rotation
4 5 6 7 1 2 3   //3rd left Rotation
```

### Logic
- If rotation_size(K) > size_of_array(N). Calculate actual_rotation(K) = rotation_size(K) % size_of_array(N)

### Approach-1
- **Complexity:** n: Array size, (m = arrSize%k) Actual Number of rotations needed
  - Time: O(nm)
  - Space: O(1) //Constant
- **Code**
```c
void LeftRotate(vector<int>& v, int k){
  int mod = v.size() % k;
  if (mod == 0){
    //No rotation needed
    return;
  }

  for (int i=0; i<mod; ++i) {
    int first = arr[0];
    for (int i = 0; i < v.size()-1; i++) {
        v[i] = v[i + 1]; 
    }
    v[i] = temp;   
  }
}

int main(){
  vector<int> a = {1,2,3,4,5,6,7};
  int k=3;
  LeftRotate(a,k);
  for (auto i:a)
    std::cout<<i<<" ";
}
```
