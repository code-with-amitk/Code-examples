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
          
  for(i){        //finding substr of i  
    for(j){         //substr of i
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

## 3. Approach-3  //Sliding Window using unordred_set   //O(n)
- **Logic:**
  - *1.* start window from index=0. left=0, right =0. 
  - *2.* Take unordered_set to store unique elements of array.
  - *3.* if we cannot find element_at_right in unordered_set
    - Insert element into unordered_set.
    - Keep sliding ie right++
    - Longest subseq = j-i
  - *4.* if element_at_right is found in unordered_set
    - Delete `a[left]`
    - Again search `a[right]` in set, if found again delete `a[left]`. Keep doing this until `a[right]` not found in array.
```c
input = a     b     c     b     d     e
        0     1     2     3     4     5
       left
       right

right      unordered_set           longest_seq 
0             {a}                     1
1             {a b}                   2
2             {a b c}                 3
3 
             {b c} //Delete a[left++]
             {c}  //still a[right] is in set, Delete a[left++]
             
3            {c b}  //a[right] not in set insert
4            {c b d}
5            {c b d e}
```
- **Complexity**
  - **Time:** 2O(n) = O(n)
    - O(n): Linear traversal of array 
    - O(n): Deleting elements from unordered_set
  - **Space:** O(n). Taking unordered_set of size=n
- **Code**    
```c++
  int lengthOfLongestSubstring(std::string s) {
    int max=0, size=s.size(), left=0, right=0;
    std::unordered_set<char> us;

    while(left<size and right<size){
      if (us.find(s.at(right)) == us.end()) {
          us.insert(s.at(right++));
          max = std::max(max, right - left);
        }else
          us.erase(s.at(left++));

      }
    return max;
  }
```

## 4. Approach-4  //Optimized Sliding Window using unordered_map    //O(n)
- **Logic:**
  - *1.* Take `unordered_map<char, index_of_char>` storing key=char, value=index_of_char
  - *2.* start window from index=0. left=0, right =0. 
  - *3.* if we cannot find char_at_right in unordered_map
    - Insert key=char_at_right, value=right+1 into map.
    - Slide window ie right++
    - Longest subseq = j-i+1
  - *4.* if char_at_right is found in unordered_map
    - Instead of deleting `a[left]`. Move to index stored in <key,value> pair ie key=a[left]. Move to its value
    - Change value of key=char_at_right
```c
input = a     b     c     b     d     e
        0     1     2     3     4     5
       left
       right

right      unordered_map           longest_seq 
0          [a,1]                      1
1          [a,1][b,2]                 2
2          [a,1][b,2][c,3]            3
3          Now b is present in um

input = a     b     c     b     d     e
        0     1     2     3     4     5
                  left  right

           left=2 //Move to um[b]->second
           Update um entry  [b,4]
           [a,1][b,4][c,3]      //We skipped deletion of characters as in approach-3
  so on..            
```
- **Complexity**
  - **Time:** O(n) Linear traversal of array of size=n and 1 jump in case of finding repeating char.
  - **Space:** O(2n) for unordered_map
- **Code**
```c++
  int lengthOfLongestSubstring(std::string s) {
    int max=0, size=s.size();

                    //char, index_of_char
    std::unordered_map<char, int> um;

    for(int left=0, right=0; right<size;++right){

      auto it = um.find(s.at(right));
      if (it != um.end())
          left = std::max(left, it->second);

      max = std::max(max, right - left+1);
      um[s.at(right)] = right+1;
    }
    return max;
  }
```
