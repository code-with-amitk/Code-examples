/*A new fighting game has become popular. There are N number of villains with each having some strength. There are N players in the game with each having some energy. The energy is used to kill the villains. The villain can be killed only if the energy of the player is greater than the strength of the villain. 
 * Maxi is playing the game and at a particular time wants to know if it is possible for him to win the game or not with the given set of energies and strengths of players and villains. Maxi wins the game if his players can kill all the villains with the allotted energy.
Input Format
  The first line of input consist of number of test cases, T.
  The first line of each test case consist of number of villains and player, N.
  The second line of each test case consist of the N space separated strengths of Villains.
  The third line of each test case consist of N space separated energy of players.
Output Format
        For each test case, Print WIN if all villains can be killed else print LOSE in separate lines.


Time Limit(X):  1.00 sec(s) for each input.
Memory Limit:   512 MB
Source Limit:   100 KB

Input
1                       //Test cases
6                       //Number of Villians
112 243 512 343 90 478  => 90  112 243 343 478 512      //Energies of villians
500 789 234 400 452 150 => 150 234 400 452 500 789      //Energies of players
Output
WIN

Input
1
6
10 20 50 100 500 400 => 10 20 50 100    
30 20 60 70 90 490 =>   20 30 60 70  90 490
Output
LOOSE
 */

/*Enter your code here. Read input from STDIN. Print your output to STDOUT*/
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int main()
{
        int test_cases, no_of_villians, t, c, j, villian_strength, player_strength ,loose;
        vector<int> vec_villian;
        vector<int> vec_player;

        cin>>test_cases;
        for(t=0;t<test_cases;t++){
                loose = 0;
                vec_villian.clear();
                vec_player.clear();
                cin>>no_of_villians;

                for(j=0;j<no_of_villians;j++){
                        cin>>villian_strength;
                        vec_villian.push_back(villian_strength);
                }
                sort(vec_villian.begin(), vec_villian.end());

                for(j=0;j<no_of_villians;j++){
                        cin>>player_strength;
                        vec_player.push_back(player_strength);
                }
                sort(vec_player.begin(), vec_player.end());
                for(c=0;c<vec_villian.size();c++){
                        if(vec_villian[c] > vec_player[c]){
                                cout<<"\nLOSE";
                                loose=1;
                                break;
                        }
                }
                if(!loose)
                        cout<<"WIN\n";
        }
}

