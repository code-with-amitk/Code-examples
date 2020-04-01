//https://tour.golang.org/basics/7

package main

import(                  //import: Include Package/Header-File. Grouping imports
    "fmt"            // fmt includes functionality for formatting output to screen
    "time"
)

/*
PARAMETERS:
 - type comes after the variable name
 - When 2 or more consecutive function parameters share a type, we can omit type from all but the last.
*/
//func add(x int, y int) int{	//valid
func add(x, y int) int {	//valid
	return x + y
}

//MULTIPLE RETURNS:
//The swap function returns two strings.
func swap(x, y string) (string, string) {
	return y, x
}


//NAKED RETURNS: 
//return statement without arguments
func split(sum int) (x, y int) {
	x = sum * 4 / 9
	y = sum - x
	return
}

/*
println: Prints in newline
printf: Just prints no new line
*/
func main() {
	fmt.Println(add(42, 13))
	fmt.Printf("  hello  ")
	fmt.Println(time.Now())
	a, b := swap("hello", "world")
	fmt.Println(a, b)
	fmt.Println(split(17))
}

/*
# /usr/local/go/bin/go build add.go
# ./add
55
  hello  2020-04-01 08:53:55.869681784 +0530 IST m=+0.000048093
world hello
7 10

*/

