## [Deletion Distance](https://www.pramp.com/challenge/61ojWAjLJbhob2nP2q1O)
- The deletion distance of two strings is the minimum number of characters you need to delete in the two strings in order to get the same string
- Example
```c++
input:  str1 = "dog", str2 = "frog".      output: 3

input:  str1 = "some", str2 = "some".     output: 0

input:  str1 = "some", str2 = "thing".    output: 9

input:  str1 = "", str2 = "".             output: 0
```

## Logic
- *1.* Find LCS(Longest common subseqeunce) between strings. 
  - [LCS is Explained here](https://github.com/amitkumar50/Code-examples/blob/master/ds_questions/questions/strings/SubString/3.%20Longest_Common_SubSeq.md)
```c++
LCS(dog, frog) = 2(og)
```
- Answer = str1.size()-lcs + str2.size()-lcs

## Code
```c++
int lcs(const string& a, const string& b, int m, int n){
    if (m == 0 || n == 0)
        return 0;

    if (a[m-1] == b[n-1])
        return 1 + lcs(a, b, m-1, n-1);
    else
        return max(lcs(a, b, m, n-1), lcs(a, b, m-1, n));
}

int deletionDistance( const string& a, const string& b ) {
  int lcs1 = lcs(a,b,a.size(),b.size());
  
  return a.size()-lcs1 + b.size()-lcs1;
}
```
