## Big O Notation, Complexity Calculations
- **What**
  - worst-case: maximum number of steps taken in any instance of size n
  - best-case: minimum number of steps taken in any instance of size n.
  - average-case: average number of steps over all instances of size n
### Space
- **O(1) is not Constant Space?** 
  - Constant soace means amount of space that your algorithm uses is independent of the input parameters. Say you are given an array of size n. If the amount of space your algorithm uses increases/decreases with n, then it's not constant. If your algorithm always uses a fixed amount of space everytime independent of input size, then its constant space.
- **Recursion?** When you use recursion, the stack also counted in space complexity.
### Time
- **ASYMPTOTIC ANALYSIS?** Used to simplify the analysis of Running-Time of algorithm.
  - a. Drop lower level order terms+constant factors. 50nlogn => O(nlogn).
  - b. O(nlogn) + O(n) => O(nlogn)
- **Recursion: O(2<sup>n</sup>)** Recursion has space complexity of O(2<sup>n</sup>)
  - Given a string of length of length n (eg:ab), there are n+1 ways(a,b,ab) to split it into two parts. At each step, we have a choice: to split or not to split. In the worse case, when all choices are to be checked, that results in 2<sup>n</sup>.

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
