**Letter Combinations of a Phone Number**
- [Approach-1, Backtracking](#bt)

### [17. Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/)
- Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
- A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

<img src=https://assets.leetcode.com/uploads/2022/03/15/1200px-telephone-keypad2svg.png width=300/>

- Examples
```c
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Input: digits = ""
Output: []

Input: digits = "2"
Output: ["a","b","c"]
```

<a name=a1></a>
### Approach-1, Backtracking
- **Backtracking Problems:** Combinations, Permutations, N-Queen, Suduko, Word Search in Grid
#### Logic
```c
"234"
"abc" "def" "ghi"
```
- Backtrack Tree
<img src=images\Letter_combination_of_a_phone_number.jpg width=900 />

#### Code
```cpp
class Solution {
    using vecS = vector<string>;
	unordered_map <char, string> um;
	void create_map() {
        um['1'] = "";
        um['2'] = "abc";
        um['3'] = "def";
        um['4'] = "ghi";
        um['5'] = "jkl";
        um['6'] = "mno";
        um['7'] = "pqrs";
        um['8'] = "tuv";
        um['9'] = "wxyz";
    }
    vecS out;
    string input;
public:
    vector<string> letterCombinations(string digits) {
      if (!digits.size())
          return out;
	    input = digits;
      
      /// 1. Create map
	    create_map ();

	    string cand;
      
      /// Start with empty candidate
	    rb (0, cand);
      
      return out;
    }
    void rb (int startIndex, string cand) {
    
      /// Base case
	    if (cand.size() >= input.size()) {
		    out.push_back(cand);
		    return;
	    }

	    auto it = um.find(input[startIndex]);
	    string letters_for_numbers = it->second;
      
      /// Iterate thru all possible candidates
	    for (int i=0; i<letters_for_numbers.size(); ++i) {
      
        /// Place this candidate on 1 solution
		    cand += letters_for_numbers[i];
        
		    rb (startIndex+1, cand);
        
        /// Mark this as unvisited, remove the element
		    cand.pop_back();
	    }
    }
};
```
