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

## 1. Approach-1 //Naive O(n<sup>3</sup>)
- **Logic:** 
  - *1.* Check all the substring one by one and see if it has no duplicate characters are present.
  - *2.* 3 for loops would be used.
```c
> input = a b c b e a c
          0 1 2 3 4 5 6
          
  for(i){          
    for(j){        
      if(s[i] == s[j])
        for(k)      //Find substring does not have repeating character
    }
  }

i=0, j=5
    for(k=0 k<5)  //Find any repeating characters(if yes that will not be subseq). index=1,index=3
```

## 2. Approach-2 //Naive + unordered_set O(n<sup>2</sup>)
- **Logic:** Same approach as above but use unordered_set inplace of 3rd for(k) loop.
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

## 3. Approach-3  //Sliding Window
- **Logic:** In naive approach we are comparing characters again which we have already compared.
```c++
```
