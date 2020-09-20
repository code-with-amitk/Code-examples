### [Problem](https://leetcode.com/contest/weekly-contest-207/problems/rearrange-spaces-between-words/)
- Given a string text of words having words and random number of spaces(1 or more) between words.
- It's guaranteed that text contains at least one word.
- Rearrange the spaces so that there is an equal number of spaces between every pair of adjacent words and that number is maximized. 
- If you cannot redistribute all the spaces equally, place the extra spaces at the end, meaning the returned string should be the same length as text.
- Return the string after rearranging the spaces.
- Examples: 
```c
Example-1:
Input: text = "  this   is  a sentence "
Output: "this   is   a   sentence"
Explanation: There are a total of 9 spaces and 4 words. We can evenly divide the 9 spaces between the words: 9 / (4-1) = 3 spaces.

Example-2:
Input: text = " practice   makes   perfect"
Output: "practice   makes   perfect "
Explanation: There are a total of 7 spaces and 3 words. 7 / (3-1) = 3 spaces plus 1 extra space. We place this extra space at the end of the string.
```

### [YouTube Video Explanation](https://youtu.be/PiW-tH_-Dqk)

#### Code
```c++
class Solution {
public:
  string rs(string s) {
    int spaces = 0, i = 0;
    string word;
    vector<string> vec;

    //1. Seperating words and spaces. Going character by character
    while (i < s.size()) {

      if ( s[i] == ' ' ) {    //if whitespace, count spaces

        if ( word.empty() != 1 )  //There was a word before this whitespace
          vec.push_back(word);    //Push word on vector

        word = "";

        while ( s[i] == ' ' ){  //Count continous whitespaces
          spaces++;
          i++;
        }

      } else {                //if not white space, store the word in word
        word = word + s[i];
        i++;
      }
    }

    //Push last word on vector
    if ( word.empty() != 1 )
      vec.push_back(word);

    /*for (auto i:vec)
      cout<<i << " ";
    cout<<"\nspaces="<<spaces<<"\n";
    cout<<"vec.size()="<<vec.size();
    cout<<"\n";*/
     //Find number of spaces to be inserted in between and end
    string result, stk, sae;
    int sbw = 0, mod, l = 0;
    if (spaces > 0 and vec.size() not_eq 1) {
      sbw = spaces / (vec.size() - 1);
      mod = spaces % (vec.size() - 1);
    }

    //Create a word of spaces to be inserted in between.
    while( l < sbw ){
      stk = stk + " ";
      l++;
    }

    l = 0;
    if (vec.size() == 1)
      mod = spaces;

    //Create a word of spaces to be inserted at end
    while( l < mod ){
      sae = sae + " ";
      l++;
    }

    //Create the resultant string
    for (int i = 0; i < vec.size(); i++){
      result = result + vec[i];
      if (i < vec.size() - 1 )
        result = result + stk;
    }   
    }

    if ( mod > 0 )
      result = result + sae;

    return result;
  }
};

int main(){
  //string s = "  walks  udp package   into  bar a";
  //string s = "a";
  //string s = " practice   makes   perfect";
//string s = "  this   is  a sentence ";
  string s = "  hello";
  Solution o;
  cout<<o.rs(s);
}
```
