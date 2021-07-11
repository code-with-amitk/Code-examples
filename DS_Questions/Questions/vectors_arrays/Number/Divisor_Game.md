- [Question](#ques)
- [Approach-1. Recursion](#apr1)
  - [Logic](#logic1)
  - [Complexity](/DS_Questions)
  - [Code](#code1)
- [Approach-2. Dynamic Programming](#apr2)
  - [Logic](#logic2)
  - [Code](#code2)

<a name=ques></a>
## [Divisor Game / Divide and Subtract Game](https://leetcode.com/problems/divisor-game/)
- Alice and Bob take turns playing a game, with Alice starting first.
- Initially, there is a number n on the chalkboard. On each player's turn, that player makes a move consisting of:
  - Choose number x. (0< x < n) and (x%n == 0)
  - Replace number n on chalkboard by n-x
  - if a player cannot make a move, they lose the game.
- Return true if and only if Alice wins the game, assuming both players play optimally.
```console
Input n = 1
O/p = false. Alice cannot make a move. Alice loose.

Input: n = 2
Alice x=1. n=n-x. n=1
Bob cannot make a move. Bob loose
O/P: true //Alice win

Input: n = 3
Alice x=1, n=2
Bob x=1, n=1
Alice cannot make a move. Alice loose
O/P: false

Input n=4
```

<a name=apr1></a>
## Approach-1. Recursion
<a name=logic1></a>
- **Logic**
  - At each state, we will try to find all the divisors of N and will try to find the next state where the current player is winning. 
  - For Alice, we will try to find the next state where the return value is true while for Bob, we will try to find the next state where the return value is false (as false represents the loss of player Alice).
<a name=code1></a>
- **Code**
```c++
bool divisorGame(int no, bool A) {

  if (no == 1 or no == 3)         //if number=1 or 3 then player Bob wins
    return false;

  if (no == 2)                  //if number=2 Alice wins
    return true;

  int ans = (A == 1) ? 0 : 1;          //If its Alice's Chance. Take ans=0

  for (int i = 1; i * i <= no; i++) {       //Traverse all divisors of number, which are less than no

    if (no % i == 0) {                       //if Current value of i is divisor of Number
      if (A)                                		//if it's Alice's turn, then we need at least one true
        ans |= divisorGame(no - i, 0);          //Next turn of Bob
      else
	ans &= divisorGame(no - i, 1);     //if it's Bob's turn, we need at least one false
    }
  }
  return false;
}

int main() {
  int no = 4;

  if (divisorGame(N, 1) == true)
    cout << "Player A wins";
  else
    cout << "Player B wins";

  return 0;
}
```

<a name=apr2></a>
## Approach-2. Dynamic Programming
<a name=logic2></a>
- **Logic**
  - Everything is same, we store result in DP array having 2 states i.e. 
```c
N -> current number left 
A -> boolean value to decide if it’s player A’s turn or not
```
  - To find the answer, we just need to find the value of `DP[ N ][ 1 ]`.
<a name=code2></a>
- **Code**
```c
// C++ program for implementation of
// Optimal Strategy for the Divisor
// Game using Dynamic Programming
#include <bits/stdc++.h>
using namespace std;

// Recursive function to find the winner
bool divisorGame(int N, bool A, int dp[][2])
{

	// check if N=1 or N=3 then player B wins
	if (N == 1 or N == 3)
		return false;

	// check if N=2 then player A wins
	if (N == 2)
		return true;

	// check if current state already visited
	// then return the previously obtained ans
	if (dp[N][A] != -1)
		return dp[N][A];

	// check if currently it is player A's turn
	// then initialise the ans to 0
	int ans = (A == 1) ? 0 : 1;

	// Traversing across all the divisors of N
	// which are less than N
	for (int i = 1; i * i <= N; i++) {

		// check if current value of
		// i is a divisor of N
		if (N % i == 0) {

			// check if it is player A's turn
			// then we need at least one true
			if (A)
				ans |= divisorGame(N - i, 0, dp);

			// Else if it is player B's turn
			// then we need at least one false
			else
				ans &= divisorGame(N - i, 1, dp);
		}
	}

	// Return the current ans
	return dp[N][A] = ans;
}

// Driver code
int main()
{
	// initialise N
	int N = 3;

	int dp[N + 1][2];

	memset(dp, -1, sizeof(dp));

	if (divisorGame(N, 1, dp) == true)
		cout << "Player A wins";
	else
		cout << "Player B wins";

	return 0;
}

```
