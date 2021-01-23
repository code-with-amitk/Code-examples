/*              graph_transpose.cpp
        
Question: Find transpose of this graph. In transpose directions of edges are reversed.
        [1] --> [0] --> [3] --> [4]
        /\       |
        |       \/
        --------[2]

Can you find transpose of undirected graph? No, since there are no directions

Answer:
        [1] <-- [0] <-- [3] <-- [4]
        |        /\
        |        |
        ------> [2]

*************Logic*****************
-> This is simply finding transpose of matrix   [Check matrix_transpose.cpp]
-  a[i][j] = t[j][i]    //Make rows as cols, col as rows for new matrix
***********************************
*/

#include<iostream>
#include<vector>
#include<list>
using namespace std;

#ifdef USING_VECTOR
void transpose(vector<int> v[]){
        vector<int> t[5];
        for(int i=0;i<5;i++){
                for(auto j=v[i].begin();j!=v[i].end();j++){
                        t[*j].push_back(i);
                }
        }
        cout<<"Transpose using vector Done\n";
}

int main(){
        //Using vector
        vector<int> v[5];
        v[0].push_back(2);
        v[0].push_back(3);
        v[1].push_back(0);
        v[2].push_back(1);
        v[3].push_back(4);
        transpose(v);
}
#endif

void transpose(list<int> *p){
        list<int> *t;
        t = new list<int>[5];

        for(int i=0;i<5;i++){
                for(auto j=p[i].begin(); j!=p[i].end(); j++){
                        t[*j].push_back(i);
                }
        }
        cout<<"Transpose using list Done\n";
}

int main(){
        //Using Doubly LL
        list<int> *p;
        p = new list<int>[5];
        p[0].push_back(2);
        p[0].push_back(3);
        p[1].push_back(0);
        p[2].push_back(1);
        p[3].push_back(4);
        transpose(p);
}
