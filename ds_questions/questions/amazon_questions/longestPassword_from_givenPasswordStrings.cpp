/*
You would like to set a password for a bank account. However, there are three restrictions on the format of the password:

it has to contain only alphanumerical characters (a−z, A−Z, 0−9);
there should be an even number of letters;
there should be an odd number of digits.
You are given a string S consisting of N characters. String S can be divided into words by splitting it at, and removing, the spaces. The goal is to choose the longest word that is a valid password. You can assume that if there are K spaces in string S then there are exactly K + 1 words.

For example, given "test 5 a0A pass007 ?xy1", there are five words and three of them are valid passwords: "5", "a0A" and "pass007". Thus the longest password is "pass007" and its length is 7. Note that neither "test" nor "?xy1" is a valid password, because "?" is not an alphanumerical character and "test" contains an even number of digits (zero).

Write a function:

class Solution { public int solution(String S); }

that, given a non-empty string S consisting of N characters, returns the length of the longest word from the string that is a valid password. If there is no such word, your function should return −1.

For example, given S = "test 5 a0A pass007 ?xy1", your function should return 7, as explained above.

Assume that:

N is an integer within the range [1..200];
string S consists only of printable ASCII characters and spaces.
In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.
 */
#include<iostream>
#include<string>
#include<vector>
#include <bits/stdc++.h>
#include<string>

int solution(std::string &S){
        std::cout<<"Got string: "<<S<<"\n";

        std::vector <std::string> tokens;               //Using vector for token storage
        std::stringstream check1(S);            //Object initialization for stringstream class
        std::string intermediate, final_str;
        int letter_count = 0;
        int not_alpha_num = 0;
        int digit_count = 0;
        int letter_present_but_not_even = 0;

        while(getline(check1, intermediate, ' ')) {     //Tokenize for Space ' '
                tokens.push_back(intermediate);
                std::cout<<"string="<<intermediate<<", len="<<intermediate.length()<<"\n";

                //Checking for Longest Password.
                for (std::string::iterator it=intermediate.begin(); it!=intermediate.end(); ++it){
                        int tmp = int(*it);

//                              std::cout << *it;
                        //it has to contain only alphanumerical characters (a−z, A−Z, 0−9);
                        if(tmp<48 || (57<tmp && tmp<65) || (90<tmp && tmp<97) || 122<tmp){
                                std::cout<<*it<<" This Char does not fall in range "<<tmp<<"\n";
                                not_alpha_num = 1;
                                break;
                        }
//                      std::cout<<"not_alpha_num :"<<not_alpha_num<<"\n";

                        //there should be an even number of letters;
                        if((64<tmp && tmp<91) || (96<tmp && tmp<123)){
                                letter_count++;
                        }

                        //there should be an odd number of digits;
                        if((47<tmp && tmp<58)){
                                digit_count++;
                        }
                }

                if(letter_count != 0 && letter_count%2 != 0){
                        letter_present_but_not_even = 1;
                }
//              std::cout<<4%2<<"\n";
                std::cout<<"letter_count:"<<letter_count<<" digit_count:"<<digit_count<<" not_alpha_num="<<not_alpha_num<<" letter_present_but_not_even="<<letter_present_but_not_even<<"\n";

                if((not_alpha_num == 0) && (digit_count != 0 && digit_count%2 != 0) && (letter_present_but_not_even == 0)){
                        std::cout<<"This satisfies password complexity"<<intermediate<<"\n";
                        if(final_str.length()<intermediate.length()){
//                              intermediate.copy(final_str,intermediate.length(),0);
                                final_str = intermediate;
                        }
                }
                letter_count = digit_count = not_alpha_num = letter_present_but_not_even = 0;
                std::cout<<"\n";
        }

        std::cout<<"Best Password: "<<final_str<<"\n";
        if(final_str.length()==0)
                return -1;
        else
                return(final_str.length());
//      for(int i = 0; i < tokens.size(); i++)          //Printing Tokens
  //            std::cout << tokens[i] << '\n';         

        std::cout<<"bye";
}

int main(){
//      std::string pass = "test 5 a0A pass007 ?xy1 H";
        std::string pass = "H";
        std::cout<<solution(pass)<<"\n";
        return 0;
}
