/*  range.go
RANGE: is for loop iterating over slice or map.
 1. Returns: when iterating over slice
  value-1: index inside slice
  value-2: copy of the element at that index.
 2. index or value anything can be skipped using "_"
*/
package main
import "fmt"

var slc = []int{1, 2, 3}        //Created Slice

func main() {
        for i, v := range slc {
                fmt.Printf("slc[%d]=%d,\t", i, v)       //slc[0]=1, slc[1]=2, slc[2]=3  //1
        }

        for _, v := range slc {
                fmt.Printf("slc[]=%d,\t", v)       //slc[]=1, slc[]=2, slc[]=3  //2
        }
}
/*
# /usr/local/go/bin/go build range.go 
# ./range 
slc[0]=1,	slc[1]=2,	slc[2]=3
slc[]=1,	slc[]=2,	slc[]=3
*/
