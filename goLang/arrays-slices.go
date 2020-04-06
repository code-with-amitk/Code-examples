/*    arrays-slices.go

ARRAYS [n]T
 - FIXED SIZED: [n]T is  array of n values of type T
 - RESIZE: not possible because array's length is part of its declaration


SLICES []T
 - REFERENCE TO SECTION OF ARRAY: slice does not store any data, it just describes a section of an underlying array.
 - MODIFICATION:  Changing elements of a slice modifies the corresponding elements of its underlying array 
 - LENGTH: No of elements slice contains
 - CAPACITY: no of elements in underlying array, counting from 1st element in array.
 - NIL SLICE: nil slice has a length and capacity of 0 and has no underlying array
 - RESLICING: Slice the Slice's length to new length
 - MAKE: make() allocates a zeroed array and returns a slice that refers to that array
 - APPEND: append(slice, element). Append new element to slice
*/
package main

import "fmt"

func main() {

//ARRAY//
        arr := [6]int{1,2,3,4,5,6}

//SLICE DEFINITION//
        var slc[]int = arr[1:4]
        fmt.Println(slc)                        //2 3 4

//SLICE MODIFICATION//  
        slc[0] = 899
        fmt.Println(arr[1])             //899

//SLICE LENGTH, CAPACITY//
        fmt.Println(len(slc),cap(slc))  //3 5

//NIL SLICE//   
        var nilSlc[]int
        fmt.Println(len(nilSlc), cap(nilSlc))   //0 0

//RESLICING//
        slc1 := []int{10,20,30,40,50}
        slc1 = slc1[:0]
        fmt.Println(slc1)                       //[]
        slc1 = slc1[:4]
        fmt.Println(slc1)                       //[10,20,30,40]
        slc1 = slc1[2:]
        fmt.Println(slc1)                       //[30,40]

//MAKE SLICE//
        slc2 :=make([]int, 5)                   //[0 0 0 0 0]
        fmt.Println(slc2)

//APPEND TO SLICE//
        slc3 := []int{10,20,30,40,50}           //[10 20 30 40 50 60]
        slc3 = append(slc3,60)
        fmt.Println(slc3)
}
