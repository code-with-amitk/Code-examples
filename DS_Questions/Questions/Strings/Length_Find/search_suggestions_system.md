**search-suggestions-system**
- [Approach-1](#a1)

**[Self Video](https://youtu.be/a1c5W3layRM)**

### Search Suggestions System/Google Search Suggestion
- You are given an array of strings products and a string searchWord.
- Design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.
- Return a list of lists of the suggested products after each character of searchWord is typed.
```c
Example 1:

Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [
["mobile","moneypot","monitor"],
["mobile","moneypot","monitor"],
["mouse","mousepad"],
["mouse","mousepad"],
["mouse","mousepad"]
```

<a name=a1></a>
### Approach-1
- sort all words
- find 1st occuring word index (using binary search)
- Get next 3 consecutive words.
#### Code
```cpp
using vecS = std::vector<std::string>;
using vecVecS = std::vector<vecS>;
using String = std::string;

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vecVecS out;
        std::sort(products.begin(), products.end());
        String prefix;

        int start;
        //Search every alphabet into products
        for (auto&c:searchWord) {
            vecS temp;
            //Start search with 1 character, then substring
            prefix += c;

            //Binary search since products are sorted
            //Get 1st occurance of prefix in word
            start = std::lower_bound(products.begin(), products.end(), prefix) - products.begin();
            //temp.push_back(products[start]);

            //Now search other 2 words ahead of word searched above
            //Only search 2 words in next 2 words, if we reached end,donot cross boundary
            for(int i=start; i < start+3; ++i){
                if (i >= products.size())
                    break;

                //next word contains prefix
                if (!products[i].compare(0, prefix.length(), prefix))
                    temp.push_back(products[i]);
            }
            out.push_back(temp);
        }
        return out;
    }
};
```
