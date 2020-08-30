## Big O(n)
- **Complexity**
	- worst-case: maximum number of steps taken in any instance of size n
	- best-case: minimum number of steps taken in any instance of size n.
	- average-case: average number of steps over all instances of size n
- **Rules** Ignore the difference between multiplicative constants.	f(n) = 2n and g(n) = n are identical

## SPEED UP PROGRAM
- **Why** When some of test cases fail, this will lead to time improvements. Add before your class implementation
- **How**
	- **1.** Disable synchornization b/w C and C++ stream after each IO operation.
	- **2.** Untie cin from cout
```c++
//1. ios_base is class for IO streams.
// static bool sync_with_stdio( bool sync = true );
- Sets whether the standard C++ streams are synchronized to the standard C streams after each input/output operation.
- To speed up streams should not be synched after each IP operation.

//2. cin.tie(NULL)	means  flush std::cout before std::cin accepts an input.
//useful for interactive console programs which require the console to be updated constantly

int beforeMain() {			//Speeds up cout.
	ios_base::sync_with_stdio( false );
  cin.tie(NULL);
  return 0;
}

int static r = beforeMain();		//Call function before main

#define endl '\n';			//Changes endl to "\n". This prevents flushing buffer for each line.
```
