/*      switch.go
  
 a. breaks statement is provided automatically in go
 b. Unlike C,C++ swtich only runs the selected case, not all cases that follow
 c. Switch cases, Need Not to be constants.
        values involved need not to be integers.
*/
package main

import (
        "fmt"
        "runtime"
)

func main() {

        switch os := runtime.GOOS; os {
        case "darwin":
                fmt.Println("OS X")             //a. go provides break automatically
        case "linux":                           //c. switch case need not to be constants
                fmt.Println("Linux")
        case "ubuntu":
                fmt.Println("Ubuntu")
        default:
                fmt.Printf("%s.\n", os)
        }
}
/*
# /usr/local/go/bin/go build switch.go
# ./switch
Linux
*/
