/*      defer-statement.go

defer statement defers execution of a function until the surrounding function returns.
*/
package main

import "fmt"

func main() {
        defer fmt.Println("world")

        fmt.Println("hello")
}
/*
# /usr/local/go/bin/go build defer-statement.go
# ./defer-statement
hello
world
*/
