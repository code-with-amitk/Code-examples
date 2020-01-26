/*
        one_string_is_permutation_of_other.cpp  
 
Question: Check Permutation: Given two strings, write a method to decide if one is a permutation of the other.

Approach: [Think Matching Real World Bigger Problem it helps] How to find an element in a sorted array (My Ans-binary search), if given someone who has no knowledge of computer science an alphabetized pile of student papers and they'll likely implement something like binary search to locate a student's paper from pile or dictionary.

********Real World Matching Problem*************
        - - - - - - - - - - - - -       Think Row of 1 lac people standing.
        - - -   Think these are 3 people(p1,p2,p3) whose twins are there in above row. How to find?

Approach1: Match every person in row with faces of p1,p2,p3. Let match of p1 is found, get him out and compare rest 2.
************************************************

Logic:
- Take a string representing 1 lac characters
- Take hash set. unordered_set<char>
- Iterate thourgh the string
        if (element is found in hash-set)
                - remove element from hash-set
                - Count it's presence.

Time Complexity:
O(n)
*/
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

void fun(vector<char> v, unordered_set<char> f){
        int found=0, size=f.size();

        for(auto i=v.begin();i!=v.end();i++){           //O(n)

                if(f.find(*i) != f.end()){              //O(1)
                        found++;

                        f.erase(f.find(*i),f.end());    //O(1)

                        if(found==size){
                                cout<<"All elements found";
                                break;
                        }
                }
                cout<<"\n";
        }
}

int main(){
        vector<char> v = {'a','b','c','d','t','e','f','g','s','h','i','t'};
        unordered_set<char> f = {'t','e','s'};
        fun(v,f);
}
