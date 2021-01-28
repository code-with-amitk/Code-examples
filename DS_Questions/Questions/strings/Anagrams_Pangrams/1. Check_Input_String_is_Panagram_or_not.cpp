### Check Whether Panagram
- **Pangram?** Sentence(or string) containing every letter in the English Alphabet.
- Example:
```c
1. "The quick brown fox jumps over the lazy dog" is a Pangram [as it contains all the characters from ‘a’ to ‘z’]
2. "The quick brown fox jumps over the dog"      is not Pangram [as it does not contian ‘l’, ‘z’, ‘y’]
```
- Problem: Write a function taking string and returning 'true' if string is pangram else false.

### Logic(using Hash-table)
- a. Take a unordered_set<char>
- b. Parse every character of string.
  - if character is not present in Hash-table
    - insert the character.
```c
        if(hash-table size==26)
                return;
```

### Complexity
- Time Complexity: O(n)
- Space Complexity: 26

### Code
```c
#include<iostream>
#include<unordered_set>
using namespace std;

bool pangram(string str){

        unordered_set<char> s;  //Hash-table
        bool k=false;

        for(int i=0;i<str.size();i++){                                  //O(n)

                if((str[i] != 32) && \
                (s.find(tolower(str[i])) == s.end())){          //O(1)
                        s.insert(tolower(str[i]));
                }

                if(s.size() == 26){
                        k = true;
                        break;
                }
        }
        if(k)
                return true;

        return false;
}

int main(){
        string str = "The quick brown fox jumps over the lazy dog";

        if (pangram(str) == true)
                cout<<"This is pangram";
        else
                cout<<"This is not pangram";
}
/*Output:
This is pangram
*/
```
