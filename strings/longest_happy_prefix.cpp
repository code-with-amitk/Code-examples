/*      longest_happy_prefix.cpp

Task: Find longest prefix which is also suffix?

What is prefix? Example string="level". It contains 4 prefix ("l", "le", "lev", "leve")
What is suffix? suffix ("l", "el", "vel", "evel"). 
The longest prefix which is also suffix is given by "l".

Example-1:
Input: s = "level"
Output: "l"
Explanation: s contains 4 prefix excluding itself ("l", "le", "lev", "leve"), and suffix ("l", "el", "vel", "evel"). 
The largest prefix which is also suffix is given by "l".

Example-2:
Input: s = "ababab"
Output: "abab"
Explanation: "abab" is the largest prefix which is also suffix. They can overlap in the original string.

Example-3:
Input: s = "leetcodeleet"
Output: "leet"

Example-4:
Input: s = "a"
Output: ""

***************Logic*******************
https://www.youtube.com/watch?v=GTJr8OvyEVQ [Tushar Roy]

a. We need to build information array containing info of prefix and suffix.
Example:
        Pattern         vector InfoArray
        a b a b a b =>  0 0 1 2 3 4
        0 1 2 3 4 5     0 1 2 3 4 5

Explanation of InfoArray:
Index   Value   Meaning
0       0       Its always 0
1       0       There is no prefix which is also suffix in subarray[0,1]
2       1       Length of longest prefix which is also suffix in subarray[0..2] is 1. aba (ie a)
3       2       Length of longest prefix which is also suffix in subarray[0..3] is 2. abab (ie ab)
4       3       Length of longest prefix which is also suffix in subarray[0..4] is 3. ababa (ie aba)
5       4       Length of longest prefix which is also suffix in subarray[0..5] is 4. ababab (ie abab)

Build the InfoArray(very simple)
 - InfoArray[0] = 0 //Always
 - take 2 pointers, i=0,j=1. loop will j reaches end
        if(s[i] == s[j])
                infoArr[j] = i+1;
                Make i an j to point to next position
        if(s[i]!=s[j])
                if(i!=0){
                  Make i=Value of (i-1) from InfoArray
                }else{
                  Make current infoArry[j] =0;
                }
        
 - You can see simply and understand it

Complexity:
Time: O(n)      //n-Length of input string
Space: O(n)     //Same lengthed temporary InfoArray
******************************************
*/
#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

class Solution{
public:
        string longestPrefix(string s) {
                vector<int> infoA(s.size(),0);
                for(int i = 0, j = 1; j < s.size();){
                        if(s[j] == s[i]){
                                infoA[j] = i + 1;
                                i++;
                                j++;
                        }else{
                                if(i == 0){
                                        j++;
                                }else{
                                        i = infoA[i - 1];
                                }
                        }
                }
                return s.substr(0,infoA[s.size() - 1]);
        }
        
        //Another Simple Solution
        //https://leetcode.com/problems/longest-happy-prefix/discuss/555028/O(n)-Easy-to-understand-using-whileint.for()
};

int main(){
//      string s = "acacabacacabacacac";
//      string s = "level";
//      string s = "ababab";
        Solution obj;
        string s = "leetcodeleet";
//      string s = "bba";
//      string s = "cbcbcba";
        cout<<obj.longestPrefix(s);
//      computeTemporaryArray(s);
}
/*
#./a.out
leet
*/
