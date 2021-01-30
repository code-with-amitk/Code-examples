## [Valid Palindrome II](https://leetcode.com/problems/valid-palindrome-ii/)
- Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.
- Examples
```c
Input: "aba"
Output: True

Input: "abca"
Output: True    //Explanation: You could delete the character 'c'.
```

## 1. Approach-1  //Recursion + 2 Pointer //54% Faster
> s = "xyzabcbcbabzyx"
- **Logic**
  - *1.* Take start=0, end=s.size() - 1
  - *2.* Take a bool to note number of times we can skip the character. initialize to true, Once we skip the character, assign to false, so that no further skips are allowed.
  - *3.* if (`s[start] == s[end]`)  ++start, --end;
```c
  xyabcbcbabyx  //if(start == end). yes. ++start;--end
  yabcbcbaby    //if(start == end). yes. ++start;--end
  abcbcbab      //No
```
  - *4.* if ((`s[start] != s[end]`)   //There can be 2 paths, either skip start, or skip end. We will check on both paths
    - *4a.* ++start, set bool=false(Since we have used our 1 chance of skipping) and continue compare.
```c
  abcbcbab    //++start
  bcbcbab     //if(start == end). yes. ++start;--end
  cbcba       //No
      -> We can only skip character 1 time, return false;
   return false;
```
    - *4b.* --end, set bool=false(Since we have used our 1 chance of skipping) and continue compare.
```c
  abcbcbab    //--end
  abcbcba     //if(start == end). yes. ++start;--end
  bcbcb       //if(start == end). yes. ++start;--end
  cbc        //if(start == end). yes. ++start;--end
  b         //start, end cross. Return true
  return true;
```
- **Complexity**
  - *Time:* O(n). 
    - O(n): Skipping 1 character from start when start != end.
    - O(n): Skipping 1 character from end when end != start.
  - *Space:* 2O(n)
- **Code**
```c++
  bool valid(std::string& s, int start, int end, bool b){
    bool out=false;

    if(start>=end)
      return true;
      
    if(s.at(start) == s.at(end))
      out |= valid(s,++start,--end,b);

    if(s.at(start) != s.at(end)){
      if(b)
        out |= valid(s,start+1,end,false);
      if(b)
        out |= valid(s,start,end-1,false);
    }
    return out;
  }    
  bool validPalindrome(string s) {
    int start=0, end=s.size()-1;
    bool bOnce = true;

    return valid(s, start, end, bOnce);
  }
int main(){
  std::string s = "abcdeffdcba";
  std::cout<<validPalindrome(s);
}
```

## 2. Approach-2    //2 Pointer, Iterative  //30% Faster
> Slower than recursive
- **Complexity**
  - *Time:* O(n)
  - *Space:* 2O(n)
- **Code**
```c++
  bool valid(std::string& s, int start, int end){
    while (start < end) {
      if(s.at(start++) != s.at(end--)){
        return false;
      }
    }
  return true;
  }

  bool validPalindrome(std::string s) {
    int start=0, end=s.size()-1;
    while (start < end) {
      if(s.at(start) != s.at(end)){
        return valid(s, start+1, end) || valid(s,start, end-1);
      }
      ++start; --end;
    }
    return true;
  }
```
