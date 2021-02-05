/*      pointers.go
  
 a. & operator generates pointer to operand
 b. * operator derefences pointer's value
 c. Unlike C there is no pointer arithematic in go
*/
package main

import "fmt"

func main() {
        a := 1

        ptr := &a                       //Points to a
        fmt.Println(*ptr)               //1

        //ptr = ptr + 1;                //c
}
/*
# /usr/local/go/bin/go build pointer.go
# ./pointer
1
*/
