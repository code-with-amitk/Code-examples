**Unique Email Addresses**
- [Approach-1, Split string. O(n)](#a1)


### [Unique Email Addresses](https://leetcode.com/problems/unique-email-addresses/)
- Every valid email consists of a local name and a domain name, separated by the '@' sign. Besides lowercase letters, the email may contain one or more '.' or '+'.
- For example, in "alice@leetcode.com", "alice" is the local name, and "leetcode.com" is the domain name.
- **Rules**
```c
//1. Keep domain name as it is (ie after @)
//2. local name rules
    // . ignore them
    // + skip all characters till @
```
- Find number of valid emails
```c
Example 1:
Input: emails = ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
Output: 2
Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails.

Example 2:
Input: emails = ["a@leetcode.com","b@leetcode.com","c@leetcode.com"]
Output: 3
```

<a name=a1></a>
### Approach-1, Split string. O(n)
- _1._ Seperate localname, domainname. 
- _2._ Apply rules on localname.
- _3._ Create valid email using localname@domainname and store in hash_set. sizeof hashset = count
```cpp
#include<unordered_set>
using String = std::string;
using US = std::unordered_set<String>;
//Rules:
//1. Keep domain name as it is (ie after @)
//2. local name rules
    // . ignore them
    // + skip all characters till @
class Solution {
public:
    int numUniqueEmails(vecS& emails) {
        int count = 0;

        US us;
        //Get domain name, local name seperated
        for (String& str:emails){
            int index=0;
            if((index = str.find("@")) != String::npos){}
            String localname = str.substr(0,index);
            String domainname = str.substr(index+1,str.size()-1);

            String localname1;
            for (int i=0;i<localname.size();++i){
                if (localname[i] == '.')
                    continue;
                if (localname[i] == '+')   //Ignore everything after +
                    break;
                localname1 += localname[i];
            }
            us.insert(localname1+"@"+domainname);
        }

        return us.size();
    }
};
```
#### Complexity
- **Time:** O(n)
- **Space:** 2O(n) = O(n)
