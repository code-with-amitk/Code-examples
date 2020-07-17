/*      if-statement.go

1. IF STATEMENT:
 a. Expression not surrounded by parentheses ( ) but the braces { } are required.
 b. if statement can start with Short statement to execute before condition.
 c. Variables declared in if statement are also avaiable in else block.
*/

package main
import (
        "fmt"
        "math"
)

func main() {
        a := 1.1 
        if a < 4 {                              //1a
                fmt.Println("Hi")
        }

        b := 2.2
        if v := math.Pow(a, b); v < 4 {         //1b
                fmt.Println("There")
        } else {                                //1c
                fmt.Println(v)
        }
}
/*
# /usr/local/go/bin/go build if-statement.go
# ./if-statement
Hi
There
*/
