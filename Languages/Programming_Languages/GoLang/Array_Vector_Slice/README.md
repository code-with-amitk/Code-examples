- [Array](#ar)
- [Slice](#sl)
- Vector
  - [2D vector](#2dv)

<a name=ar></a>
### Array
- **resize of array:** Not possible since, size is part of declaration
```go
func main() {
  arr := [6]int{1,2,3,4,5,6}    //[n values] type {}
}
```

<a name=sli></a>
### Slice = C++(vector`<int>`) = [Rust(vec`<i32>`)](Languages/Programming_Languages/Rust/Collections)
- This is just a Reference to underlying array
- A slice represents a view of contiguous sequence of elements in memory.
- Slices are used to borrow a portion of an array or a whole array, allowing to work with subsets of data without needing to copy or own the data
- **Denoted by `[]`**
- **Slice contains 3 components**
  - _1. Pointer to underlying array:_ A slice holds a reference to the underlying array that stores the elements.
  - _2. Length:_ number of elements in slice.
  - _3. Capacity:_ maximum number of elements it can hold 
```go
package main

func main() {
// SLICE DECLARATION
  var arr []int                       //var is used to declare a variable. T=int type of the elements that the slice can hold
  slice := make([]int, 5)             //make([]T, length). Creates a slice with length 5 and capacity 5

// INITIALIZATION
  arr := []int {1,2,3,4,5,6}        //Length of the slice is determined by the number of elements provided
  arr_slice := arr[1:4]             //Creates a new slice from index 1 to 3 (exclusive) from existant array
  
// SLICE MODIFICATION: Changing elements of a slice modifies the corresponding elements of its underlying array 
  slc[0] = 899
  fmt.Println(arr[1])             //899

// length: no of elements slice contains
// capacity: no of elements in underlying array
  fmt.Println(len(slc),cap(slc))  //3 5

// NIL SLICE
  var nilSlc[]int
  fmt.Println(len(nilSlc), cap(nilSlc))   //0 0

//RESLICING:  Slice the Slice's length to new length
    slc1 := []int{10,20,30,40,50}
    slc1 = slc1[:0]
    fmt.Println(slc1)                       //[]
    slc1 = slc1[:4]
    fmt.Println(slc1)                       //[10,20,30,40]
    slc1 = slc1[2:]
    fmt.Println(slc1)                       //[30,40]

//MAKE SLICE: make() allocates a zeroed array and returns a slice that refers to that array
    slc2 :=make([]int, 5)                   //[0 0 0 0 0]
    fmt.Println(slc2)

//APPEND TO SLICE: append(slice, element). Append new element to slice
    slc3 := []int{10,20,30,40,50}           //[10 20 30 40 50 60]
    slc3 = append(slc3,60)
    fmt.Println(slc3)
}
```

### Vector
<a name=2dv></a>
#### 2D Vector = `[][]` = slice of slices
```go
package main
func main() { 
  // Method-1: Declare a 2D vector
  var test [][]int     
  
  // Method-2: Declare an empty 2D vector
  test := make([][]int, rows)
  // Initialize each row with specific length
  for i := range vector {
    test[i] = make([]int, cols)
  }
  
  // Method-3: Declare an empty 2D vector
  var test [][]int
  // Initialize each row with specific length
  for i := 0; i < rows; i++ {
    test = append(test, make([]int, cols))
  }


  // Initialize the 2D vector with values
  test = [][]int {
    1,2,3
    4,5,6
  }
  
  // Accessing elements in the 2D vector
  fmt.Println(vector[0][0]) // Output: 1
}
```
