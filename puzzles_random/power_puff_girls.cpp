/*      power_puff_girls.cpp

Professor Utonium is restless because of the increasing crime in the world. The number of villains and their activities has increased to a great extent. The current trio of Powerpuff Girls is not well to fight the evils of the whole world. Professor has decided to create the maximum number of Powerpuff Girls with the ingredients he has.

There are N ingredients required in a certain quantity to create a Powerpuff Girl. Professor has all the N ingredients in his laboratory and knows the quantity of each available ingredient. He also knows the quantity of a particular ingredient required to create a Powerpuff Girl. Professor is busy with the preparations and wants to start asap.       

To make a Powerpuff Girl, Professor Utonium requires:
3 units of Ingredient A
6 units of Ingredient B
10 units of Ingredient C
The maximum number of Powerpuff Girls which can be created are 3 as after 3, Professor will run out of Ingredient C.

Question: Determine maximum no of power puff girls can be created?

Input Format
The first line of input consists of the number of ingredients, N
The second line of input consists of the N space-separated integers representing the quantity of each ingredient required to create a Powerpuff Girl.
The third line of input consists of the N space-separated integers representing the quantity of each ingredient present in the laboratory.

Output Format: Print the required output in a separate line.

Input:
4
2 5 6 3
20 40 90 50

Output:
8
*/
#include<iostream>
#include<vector>
using namespace std;

int main(){
        int noofingredients, j=0, val=0;

        vector<int> eachIngredientQty;
        vector<int> qtyPresentInLab;
        cin>>noofingredients;


        while(j<2){
                for(int i=0;i<noofingredients;i++){
                        cin>>val;

                        if(j==0){
//                              cout<<val<<"(j=0) ";
                                eachIngredientQty.push_back(val);
                        }else{
//                              cout<<val<<"(j=1) ";
                                qtyPresentInLab.push_back(val);
                        }
                }
//              cout<<"\n";
                j++;
        }

        int k=0, temp=1;
        int ppg=0;

        //Number of ppg
        while(temp){
                for(int i=0; i<noofingredients; i++){
                        if(qtyPresentInLab[i]-eachIngredientQty[i]<0){
                                temp = 0;
                                break;
                        }
                        qtyPresentInLab[i] = qtyPresentInLab[i]-eachIngredientQty[i];
                }
                if(temp)
                        ppg++;
        }
        cout<<ppg;

}
