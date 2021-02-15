## [Leftmost Column with at Least a One](https://leetcode.com/problems/leftmost-column-with-at-least-a-one/)
- A matrix of only 0,1 is given which is row-sorted in non-decreasing order. Means all 0's will be on left.
- Return the index of the leftmost column with a 1 in it. If such an index does not exist, return -1.
- To access matrix 2 interfaces are provided:
```c
  BinaryMatrix.get(row, col) returns the element of the matrix at index (row, col).
  BinaryMatrix.dimensions() returns the dimensions of the matrix as a list of 2 elements [rows, cols].
```
- More than 1000 times object BinaryMatrix should not be called.
- Examples:
```c
input = 0 0
      1 1      
Output: 0   //0th col contains 1

input = 0 0
        0 1
Output: 1   //1st col contains 1

input = 0 0
        0 0
Output: -1    //None col contains 1

input = 0 0 0 1
        0 0 1 1
        0 1 1 1
Output: 1     //1st col contains 1
```

<img src="https://leetcode.com/problems/leftmost-column-with-at-least-a-one/Figures/10012/linear_search.png" width=500 />

## 1. Appraoch-1        //Linear Search
- **Logic**
  - *1.* Traverse every row, search 1 in it.
  - *2.* if 1 is found, note coloumn number. (out = coloumn number)  //ie note minumum index
  - *3.* if in next row 1 occurs before out, out=new_col else break
- **Complexity**
  - **Time:** O(rows*k). least number of cols after which 1 occurs = k.
  - **Space:** [O(1)](/DS_Questions/README.md)
- **Code**
```c++
/**
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
  //a[0]=row
  //a[1]=col
  vector<int> a = binaryMatrix.dimensions();
  int out = INT_MAX;
        
  for(int i=0; i<a[0]; ++i){
    for(int j=0; j<a[1]; ++j){
      if (j>out)
        break;
      if (binaryMatrix.get(i,j) == 1){
        if (j<out)
          out = j;                    
        break;
      }
                
    }
  return out==INT_MAX ? -1 : out;
 }
};
```

## 2. Approach-2      //Binary Search (Since its sorted)
- **Logic**
  - *1.* Search 1 in every row using binary search, note coloumn number of 1st 1 in 1st row. (out=coloumn number) //ie note minumum index
  - *2.* Perform binary search in next row, if(coloumn of 1>out)discard else out = coloumn where 1 occurs 1st time
- **Complexity**
  - **Time:** log(row) x cols
    - log(row):Searching 1 in every row
    - cols: Number of cols
  - **Space**
    - [O(1)](/DS_Questions/README.md)
- **Code**
```c++
/ * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
  //a[0]=row
  //a[1]=col
  vector<int> a = binaryMatrix.dimensions();
  int out = a[1];     //smallest index = cols
  int ret = 0;
        
  for(int i=0; i<a[0]; ++i){
    int left = 0;
    int right = a[1] - 1;

    //Searching 1st 1 in the row
    while (left < right){
      int mid = (left+right)/2;
      if(binaryMatrix.get(i,mid) == 0)
        left = mid+1;
       else
        right = mid;
    }
            
    if(binaryMatrix.get(i,left) == 1)
      out = std::min(out,left);
  }
  return out == a[1]?-1:out;
}
```

## 3. Approach-3         //Search from top right
- **Logic**
- **Complexity**
  - **Time:** O(N + M)
  - **Space:** O(1)
- **Code**
```c++
int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
  //a[0]=row
  //a[1]=col
  vector<int> a = binaryMatrix.dimensions();
        
  //Top right element
  int row = a[0];
  int col = a[1]-1;
        
  //Search until it goes out of matrix
  while (row <a[0] and col >= 0){
    if(binaryMatrix.get(row, col) == 0)
      row++;
    else
      col--;
  }        
  return col==a[1]-1 ? -1 : col+1;
}
```
