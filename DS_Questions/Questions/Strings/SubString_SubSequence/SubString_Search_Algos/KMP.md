**Knuth Morris Pratt algorithm**
- Steps of Algo

### Steps
- **1. Build LPS(longest prefix which is also proper suffix)**
  - Logic is discussed in [longest_happy_prefix.cpp](/DS_Questions/Questions/Strings/Prefix_Suffix)
- **2: Search needle using LPS in haystack**

## Code
```c++
class Solution{
public:
   void LPSArray(string& s, vector<int>& lps) {
   
    for(int i = 0, j = 1; j < s.size();){
      if(s[j] == s[i]){
        lps[j] = i + 1;
        i++;  j++;
       }else{
        if(i == 0)
          j++;
        else
          i = lps[i - 1];
       }
    }
    cout << "LPS Array:\n";
    for(auto i:lps)
      cout << i <<" ";
    cout<<"\n";
  }
  
  void SearchNeedle(string haystack, string needle){
    int haystackSize = haystack.size();
    int needleSize = needle.size();

    //Create Longest Prefix which is also Suffix
    vector<int> lps(needleSize, 0);
    LPSArray(needle, lps);                            //Step-1

    int i = 0; //index for haystack
    int j = 0; //index for needle
    
    while (i < haystackSize) {                       //Step-2
        if (needle[j] == haystack[i]) {
            j++; i++;
        }

        if (j == needleSize) {
            printf("Found pattern at index %d \n", i - j);
            j = lps[j - 1];
        }
        else if (i < haystackSize && needle[j] != haystack[i]) {          // mismatch after j matches
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
      }
    }
};
int main(){
  Solution obj;
  string haystack = "ababaabababa";
  string needle   = "abab";
  obj.SearchNeedle(haystack, needle);
}
# ./a.out
LPS Array:
0 0 1 2
Found pattern at index 0 
Found pattern at index 5 
Found pattern at index 7
```
