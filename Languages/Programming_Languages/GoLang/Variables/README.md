**Variables**
- [Declaration & Initialization](#di)
- [Built in variables](#biv)

### Variables
<a name=di></a>
#### Declaration & Initialization
```go
fun main() {
     // Variable declaration and initialization
    var num int = 10
    var name string = "John Doe"
    var flag bool = true
 
    // Variable declaration without initialization (zero value assignment)
    var age int
    var score float64
    var isValid bool
 
     // Short variable declaration (with type inference)
    count := 5
    message := "Hello, world!"
    isFound := false
 
    // Printing the variables
    fmt.Println(num)
    fmt.Println(name)
}
```

<a name=biv></a>
#### Built in variables
- bool, string, int  int8  int16  int32  int64, uint uint8 uint16 uint32 uint64 uintptr,
- byte{alias for uint8}, rune{alias for int32}//Represents a Unicode code point, float32 float64,
- complex64 complex128
