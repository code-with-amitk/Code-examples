**Class**


### Class
- Go uses a struct-based approach to define types and methods associated with those types.
- The struct type can be considered similar to a class, as it allows you to define fields and associated methods.
```go
package main

import "fmt"

// Define a struct type
type Person struct {
	name string
	age  int
}

// Define a method associated with the Person struct
func (p Person) SayHello() {
	fmt.Printf("Hello, my name is %s and I am %d years old.\n", p.name, p.age)
}

func main() {
	// Create a new instance of Person
	person := Person{name: "John", age: 30}

	// Call the SayHello method
	person.SayHello()
}

```
