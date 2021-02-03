## [Longest Substring Without Repeating Characters LeetCode](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
- Given a string s, find the length of the longest substring without repeating characters.
- Examples
```c
Input: s = "abcabcbb"
  subsequences(without repeating chars):  
    a, ab, abc
    b, bc, bca
    c, ca, cab
    a, ab, abc
    b, bc,
    c, cb
    b
Output: 3                   //The answer is "abc", with the length of 3.

Input: s = "bbbbb"
Output: 1                   //The answer is "b", with the length of 1.

Input: s = "pwwkew"
Output: 3                   //The answer is "wke", with the length of 3. Note "pwke" is not contigious substring.

Input: s = "abac"
Output: 3                   //bac
```

## 1. Approach-1 //Naive O(n<sup>2</sup>)

- **Logic:** Check all the substring one by one and see if it has no duplicate character by inserting into unordered_set
```c
> input = a b a c
          0 1 2 3

//Inserting unique element in set
//Clear the set when duplicate found.
                                        unordered_set     max
i=0 
  j=0                                     {a}              1
  j=1                                     {a b}            2
  j=2 (a already exist in set. erase)     {}               2
  break;

i=1
  j=1                                     {b}             2
  j=2                                     {b a}           2
  j=3                                     {b a c}         3
```
- **Complexity**    
  - Time: O(n<sup>2</sup>)  //2 for loops
  - Space: O(n) //Taking unordered_set
- **Code**    
```c++
  int lengthOfLongestSubstring(string s) {
    int max=0;
    std::unordered_set<char> us;
    
    for (int i=0; i<s.size(); ++i){
      for (int j=i; j<s.size(); ++j){

        if (us.find(s.at(j)) == us.end()) {
          us.insert(s.at(j));

          max = us.size()>max ? us.size() : max;

        }else{
          us.clear();
          break;
        }

      }
    }
    return max;
  }
```

## 2. Approach-2  //Sliding Window
```c++
```
