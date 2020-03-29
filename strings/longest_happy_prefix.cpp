/*      longest_happy_prefix.cpp

A string whose prefix is also suffix.
A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).
Given a string s. Return the longest happy prefix of s .
Return an empty string if no such prefix exists.        

Example-1:
Input: s = "level"
Output: "l"
Explanation: s contains 4 prefix excluding itself ("l", "le", "lev", "leve"), and suffix ("l", "el", "vel", "evel"). The largest prefix which is also suffix is given by "l".

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
a. We need to build a array containing info of prefix and suffix.
Example:
        Pattern         vector InfoArray
        a b a b a b =>  0 0 1 2 3 4
        0 1 2 3 4 5     0 1 2 3 4 5

Meaning of
1 in InfoArray: Till index 2(aba), There is string(a) which has suffix=prefix(length=1)
2 in InfoArray: Till index 3(abab), There is string(ab) which has suffix=prefix(length=2)
3 in InfoArray: Till index 4(ababa), There is string(aba) which has suffix=prefix(length=3)
4 in InfoArray: Till index 5(ababab), There is string(abab) which has suffix=prefix(length=4)

b. Logic to calculate InfoArray(very simple)?
 - InfoArray[0] = 0 //Always
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
