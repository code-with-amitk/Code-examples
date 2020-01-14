/*
This code writes "Writing into file" in a file named "test.txt" and then reads the same file.
*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
        string line;

        /*Creating/Writing Data to file*/
        ofstream fo;                            //OUTPUT STREAM
        fo.open("test.txt");
        fo<<"Writing into file";
        fo.close();


        /*Reading data from file*/
        ifstream fi;
        fi.open("test.txt");
        while(getline(fi, line)){
                cout<<line<<"\n";
        }
        fi.close();

        return 0;
}
