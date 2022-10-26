**Check Password Strength / Sum of Unique letters in all substrings**
- Approach-1, Substring and set. TLE
  - [Logic]
  - Code
    - [CPP](#cpp)
- Approach-2, map
  - Code
    - [CPP](#cpp1)


### Check Password Strength / Sum of Unique letters in all substrings
- Find password Strength for a given password. Iterate over all substrings of given string, sum all unique characters in substrings.
```
input: good
output: 16

substring   unique_letters
  g          1
  o          1
  o          1
  d          1
  go         2
  oo         1      //unique is needed
  od         2
  goo        2
  ood        2
  good       3
        ------------
            16
```

### Approach-1, Substring and set. TLE
<a name=l></a>
#### Logic
Find all substrings, count unique characters using map
#### Code
<a name=cpp></a>
**CPP**
```c
int main() {
  string s = "good";
  int count = 0;
  unordered_set<int> us;
  for (int i = 0; i < s.size(); i++) {
    for (int len = 1; len <= s.size() - i; len++) {
      string ss = s.substr(i, len);
      for (auto &i:ss)
        us.insert(i);
        
      count += us.size();
      us.clear();
    }
  }
  cout << count;
}
```

### Approach-2, map
#### Code
<a name=cpp1></a>
**CPP**
```c
int main() {
    string s = "good";
    int n = s.length(), tmp1=1, count=1;
    map<char, int> mp;
    mp[s[0]] = 1;
    
    for(int i = 1; i < s.length(); i++) {
        tmp1 += 1 + i - mp[s[i]];
        mp[s[i]] = i + 1;
        count += tmp1;
    }

    cout << count;
}
```
