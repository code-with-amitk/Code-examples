**Always Take 1 example of your own. In question, delibrately they donot provide all cases**

- [Approach-1. Sliding Window. O(n<sup>2</sup>)](#a1)
  - [Logic](#l)
  - [Complexity](#com)
  - Code
    - [CPP](#cpp)
- [Approach-2. Sliding Window. O(n)](#a2)
  - [Complexity](#com2)
  - Code
    - [CPP](#cpp2)

### [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/description/)
- You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
- Return the length of the longest substring containing the same letter you can get after performing the above operations.
```c
Example 1:
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Example 2:
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.

Example 3:
Input: s = "AABACBA", k = 1
Output: 4
Explanation: Replace the one 'B' in the middle with 'A' and form "AAAACBA".
The substring "AAAA" has the longest repeating letters, which is 4.
```

### Approach-1. Sliding Window
1. Take all windows.
  - Count freq of elements in window
  - if (window_size - max_freq_element_in_window > k)
    - Shrink Window. window_start++
  - else
    - Expand window. window_end++
    - longest_repeating_char_with_replacement = max_freq_element_in_window+k (Because we can replace k more chars to have longest string)
```c
"A A B A C B A"
 0 1 2 3 4 5 6
 | |
 s e

window_start  window_end  window_size  freq_of_elements   (win_size - max_freq_ele)
 0            1           2            A=2                 0
 0            2           3            A=2,B=1             1
 0            3           4            A=3,B=1             1
 0            4           5            A=3,B=1,C=1         2     //window_start++
```
#### Complexity
- **Time:** O(n<sup>2</sup>). Everytime we are filling whole dict.
- **Space:** O(1) = O(26)
#### Code
<a name=cpp></a>
**CPP**
```cpp
class Solution {
    int len;
public:
    int characterReplacement(string s, int k) {
        len = 0;
        int N = s.size();
        int window_start = 0;
        int window_last = 0;

        while (window_last <= N) {
            int window_size = window_last - window_start;
            if (!check_window (s, window_start, window_size, k))
                window_start++;
            else
                window_last++;
        }
        return  len>N ? N : len;
    }
    bool check_window(string& s, int start, int window_size, int k) {
        string str = s.substr(start, window_size);
        //cout << str << "\n";
        vector<int> dict(26, 0);
        for (char&i:str) {
            int index = i-'A';
            dict[index]++;
        }
        int max_in_dict = 0;
        for (auto&i:dict)
            max_in_dict = max(i, max_in_dict);

        if (window_size - max_in_dict > k) {
            // Shift window
            return false;
        }
        len = max(max_in_dict+k, len);
        return true;
    }
};
```

<a name=a2></a>
### Approach-2. Sliding Window. O(n)
<a name=com2></a>
#### Complexity
- **Time:** O(n). Because we keep adding elements at end of dict and remove from front.
- **Space:** O(1). Taking 26 element array

#### Code
<a name=cpp2></a>
**CPP**
```cpp
class Solution {
public:
    int characterReplacement(string s, int k) {
        int len = 0;
        int N = s.size();
        int start = 0;     //Window Start element
        int last = 0;      //Window last element
        int wsize = 0;      //Window Size
        int max_in_dict = 0;
        bool start_shift = false;
        
        /* Count number of freq of each element. Eg: AABABBA
        | 4 | 3 | ....... 26 rows ......  |
          0   1
        */
        vector<int> dict(26, 0);

        while (last < N) {
            wsize = last - start + 1;    //if start=0, last=0, Still we have window of size=1
            
            // We have fixed start. So 
            if (!start_shift) {
                dict[s[last] - 'A']++;
                start_shift = false;
            }

            // Get max occuring freq element
            for (auto&i:dict) 
                max_in_dict = max(i, max_in_dict);

            // if window_size - max_freq_elemnt > k
            // shift window from start.
            if (wsize - max_in_dict > k) {
                // Shift window
                dict[s[start] - 'A']--;
                start++;
                start_shift = true;
                continue;
            }
            // increase window from last
            start_shift = false;
            last++;

            // if window_size != max_freq_element_in_dict, It means we can replace k elements from input array
            // hence add k
            int temp = max_in_dict;
            if (max_in_dict != wsize)
                temp = max_in_dict + k;
            len = max(temp, len);
        }
        return len>N ? N : len;      
    }
};
```
