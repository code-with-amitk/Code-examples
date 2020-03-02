/*      build-lowest-number.cpp
Situation/Task: Build Lowest Number by Removing k digits from given number, inplace.
Input: str = "4325043", k = 3. Remove k digits and build lowest number.
Output: "2043"

Input str = "765028321",k = 5, Output: "0221"
Input str = "121198", k = 2, Output: "1118"

*******************Logic(QUEUE)**********************
Example: str="4325043", k=3
- str.length()=7, k=3. We need to create 7-3=4 digit number
  __  __  __  __
  Thousand's digit should be Minimum possible.

- Take a queue. Traverse str from index0.
  -> Insert element if its smaller than already present in Q.
  -> Remove bigger element.
*/
#include<string>
#include <deque>
#include<iostream>
using namespace std;

class A {
public:
        string removeKdigits(string str, int n);
        void insertInNonDecOrder(deque<char> &dq, char ch);
};

string A::removeKdigits(string str, int n){
        int len = str.length();
        int k = len - n;
        deque<char> dq;
        string res = "";
        int i;

        for (i=0; i<=n; i++){
                insertInNonDecOrder(dq, str[i]);
        }

        while (i < len){
                res += dq.front();
                dq.pop_front();
                insertInNonDecOrder(dq, str[i]);
                i++;
        }

        res += dq.front();
        dq.pop_front();
        return res;
}

void A::insertInNonDecOrder(deque<char> &dq, char ch){
        if (dq.empty()){
                dq.push_back(ch);
        }else{
                char temp = dq.back();
                while(temp > ch && dq.empty() != 1){
                        dq.pop_back();
                        if (dq.empty() != 1)
                                temp = dq.back();
                }
                dq.push_back(ch); // insert the current digit 
        }

        return;
}

int main(){
        string str = "243112";
        A s;
        cout<<s.removeKdigits(str,2)<<endl;
}
/*
Output:
./a.out 
2112
*/
