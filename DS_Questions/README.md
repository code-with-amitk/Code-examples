- **:heart: I love problems. This is Awesome. :heart:**
- [Approach](#apr)
- [Big O Notation / Asymtotic Analysis](#bigo)
  - [1. Space Complexity](#space) 
    - [1.1 O(1) is not Constant Space](#o1)
    - [1.2 Recursion = O(2<sup>n</sup>)](#recurs)
  - [2. Time Complexity](#time) 
    - [2.1 What is Asymtotic Analysis](#asym) 
    - [2.1 Recursion = O(2<sup>n</sup>)](#recurt)
- [Speed up the program](#speed)

<a name=apr></a>
## Approach (UAWCTS(U Amit Will Conquer This Season))
**Google Interview:** https://www.youtube.com/watch?v=XKu_SEDAykw
1. Understand Clearly. Repeat          {5 min}
  - Note key points from question. {ON PAPER}
  - Repeat in your own words
  - Ask 3 clarifying questions(from interviewer)
2. Approach{ON PAPER}: Naive, Optimized. {O(logn) or O(n)}. Thought-out loud {5 min}
3. Walk{ON PAPER}: Walk approach on given input          {10 min}
4. Code. Write Modularized code. meaningful function,variable names.  {10 min}
5. Test cases: doctest(-1,0,1,-inf,+inf)       {10 min}
6. Scale on Multiple machines                  {5 min}


<a name=bigo></a>
## Big O Notation, Complexity Calculations
- worst-case: maximum number of steps taken in any instance of size n
- best-case: minimum number of steps taken in any instance of size n.
- average-case: average number of steps over all instances of size n

<a name=space></a>
### 1. Space Complexity
<a name=space></a>
#### 1.1 O(1) is not Constant Space?
 - Constant space means amount of space that your algorithm uses is independent of the input parameters. Say you are given an array of size n. If the amount of space your algorithm uses increases/decreases with n, then it's not constant. If your algorithm always uses a fixed amount of space everytime independent of input size, then its constant space.
<a name=recurs></a>
#### 1.2 Recursion = O(2<sup>n</sup>)
- When you use recursion, the stack also counted in space complexity.

<a name=time></a>
### 2. Time Complexity
<a name=time></a>
#### 2.1 Asymtotic Analysis
- Used to simplify the analysis of Running-Time of algorithm.
  - _a._ Drop lower level order terms+constant factors. 50nlogn => O(nlogn).
  - _b._ O(nlogn) + O(n) => O(nlogn)
<a name=recurt></a>
#### 2.2 Recursion: O(2<sup>n</sup>)
  - Given a string of length of length n (eg:ab), there are n+1 ways(a,b,ab) to split it into two parts. At each step, we have a choice: to split or not to split. In the worse case, when all choices are to be checked, that results in 2<sup>n</sup>.

<a name=speed></a>
## Speed up the program
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
