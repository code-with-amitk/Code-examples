/*      variables.go

VARIABLES:
1. BUILT-IN VARIABLE-TYPES:
bool, string, int  int8  int16  int32  int64, uint uint8 uint16 uint32 uint64 uintptr,
byte{alias for uint8}, rune{alias for int32}//Represents a Unicode code point, float32 float64,
complex64 complex128

2. VARIABLE DECLARATION & INITIALIZATION:
 a.var Statement:
  2a1. Declare the gobal variables. Type is last
  2a2. Declare & Initialize local variables, If an initializer is present, the type can be omitted
  - Variables declared without an explicit initial value are given their zero value.

 b. Short Variable declarations:
  2b1. Only inside function := can be used to assign variable. Outside function := is not available.
        Type of variable is inferred from value on right hand side.

3. CONSTANTS
 a. Declared using =. These cannot be declared using :=

*/

package main
import (
        "fmt"
        "math/cmplx"
)

var (
        bl   bool       = false                         //1
        mi uint64     = 1<<64 - 1
        z      complex128 = cmplx.Sqrt(-5 + 12i)
)

var a bool                                              //2a1

func main() {
        var b, c = true, "Yes"                          //2a2

        d := 4.4                                        //2b1

        const e = "Hello"                               //3a

        fmt.Println(a,b,c,d,e)

        fmt.Printf("Type: %T Value: %v\n", b, b)
        fmt.Printf("Type: %T Value: %v\n", mi, mi)
        fmt.Printf("Type: %T Value: %v\n", z, z)

}
/*
# /usr/local/go/bin/go build var.go
# ./var
false true Yes 4.4
Type: bool Value: true
Type: uint64 Value: 18446744073709551615
Type: complex128 Value: (2+3i)
*/
