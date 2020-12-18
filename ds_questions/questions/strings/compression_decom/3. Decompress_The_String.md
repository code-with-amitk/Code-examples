### Decompress
```c++
 input : 2[xyz]4[a]10[c].
 Output: xyzxyzaaaacccccccccc
```
### Logic
- a. Store numbers before `[` in string. Convert string to integer using `x = atoi(string.c_str())`
- b. Store string between `[` and `]` into string temp
- c. using for loop append temp into `string final_s` x times.

### Complexity : O(n)

### Code
```c
#include<iostream>
#include<string>
#include <sstream>

void decomp(string s){
        string num;
        string temp;
        int x;
        string final_s;

        for(int i=0;i<s.size();i++){

                //a. Find all characters in string which are digits. Append to str num.
                while(isdigit(s[i])){
                        num += s[i];
                        i++;
                }

                //b. Convert 'string num' to integer.
                if(num.empty()!=1){
                        x = atoi(num.c_str());
                }

                //c. Store string between '[' and ']' into 'string temp'.
                if(s[i] == '['){
                        i++;
                        while(s[i]!=']'){
                                temp += s[i];
                                i++;
                        }
                }

                //d. Create the final string
                for(int j=0;j<x;j++){
                        final_s += temp;
                }
                x=0;
                num.erase();
                temp.erase();
        }
        cout<<final_s;
}

int main(){
        string s="2[xyz]4[a]10[c]";
        decomp(s);
}
/*
Output:
xyzxyzaaaacccccccccc
*/
```
