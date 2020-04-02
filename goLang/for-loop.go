/*        for-loop.go

1. FOR LOOP:
 - Go has only one looping construct ie for loop.
 - init_statement(optional); condition_expression; post_statment(optional)
 a. No () are required but {} is required
 b. init_statment, post_statment is optional
 c. semicolons can also be dropped
 d. Without loop condition, this becomes INFINITE loop.
*/

package main
import "fmt"

func main() {
        sum := 0
        for i := 0; i < 10; i++ {       //1a
                sum += i
        }
        fmt.Println(sum)

        sum1 := 1
        for ; sum1 < 1000; {            //1b
                sum1 += sum1
        }
        fmt.Println(sum1)

        sum2 := 1
        for sum2 < 2000 {               //1c
                sum2 += sum2
        }
        fmt.Println(sum2)

        for {                           //1d
        }
}
/*
# /usr/local/go/bin/go build for-loop.go
# ./for-loop 
45
1024
2048
^C
*/
