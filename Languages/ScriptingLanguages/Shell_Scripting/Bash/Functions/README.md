## Functions
- **How?** We can create functions in file using 2 methods.
  - *1.* Using keyword function
  - *2.* Without using keyword function
- **3. Function Arguments?**
  - Unlike C++ `fun(int a, intb)`. In bash there is no need to specify argument names `fun()`
  - Inside function arguments are accessed using `$1 $2 so on`
- **4. Calling function?**
  - For calling the function `()` is not needed.
  
```bash
#!/usr/bin/env bash

function fun1() {     #Method-1: Declaring function
  echo "fun1 Hello"
}

fun2() {              #Method-2: Declaring function
 echo "fun2 Hello"
}

fun3() {                        #3
  local param1 = $1
  echo "fun3" $param1
}

fun4() {
  echo "fun4" $1 $2
}

fun1                      #3. Calling functions. Functions are called without ()
fun2
fun3 bob
fun4 tom rich

$ ./test.sh
fun1
fun2
fun3 bob
fun4 tom rich
```
