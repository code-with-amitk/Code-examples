/*      struct.go

STRUCT? struct is collection of feilds

 a. Struct fields are accessed using a dot.
 b. Struct pointer can point to the structure. Values can be accessed using 
        (*p).x  OR      p.x

*/
package main

import "fmt"

type test struct {
        a int
        b int
}

func main() {
        v := test{1,2}
        fmt.Println(v.a)        //a

        ptr := &v               //b
        (*ptr).a = 5
        fmt.Println((*ptr).a)
        fmt.Println(ptr.b)

        v1 := test{}            //Initialize to a=0,b=0
        v2 := test{a:1}         //a=1,b=0
        fmt.Println(v1, v2)
}
/*
# /usr/local/go/bin/go build struct.go
# ./struct
1
5
2
{0 0} {1 0}
*/
