/*      implementing_set.cpp

You have been asked to implement a set data structure, which allows 2 operations:
add element - which should guarantee no duplicates
search element - checks whether element is present in the set

- I have not used unordered_set() bcoz this itself is a set. 
*/

#define CPlusPlus
#ifdef CPlusPlus
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class set{
        vector<string> v;
public:
        void add(string t){     //Adds key to set, if key is unique
                if(!t.size()){
                        cout<<"Empty string cannot be added";
                        return;
                }
                if(!binary_search(v.begin(),v.end(),t))
                        v.push_back(t);
                else
                        cout<<"key already present\n";
        }

        void search(string t){  //Searches key inside set and return true
                if(!t.size()){
                        cout<<"Empty string cannot be searched";
                        return;
                }
                if(!v.size()){
                        cout<<"Vector is empty\n";
                        return;
                }
                if(binary_search(v.begin(),v.end(),t))
                        cout<<t<<" found\n";
                else
                        cout<<t<<" not present\n";
        }
};
int main(){
        set obj;
        obj.add("test");
        obj.add("test");
        obj.search("test");
        obj.search("");
}
/*
# g++ implementing-set.cpp 
# ./a.out 
key already present
test found
Empty string cannot be searched
*/
#endif

#ifdef PureC
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct ll{
        char *p;
        struct ll *next;
}LL;

LL *head;

LL* create_and_return(char *t){
        LL *h;
        h = malloc(sizeof(LL));
        h->next = NULL;
        h->p = malloc(strlen(t)+1);
        strcpy((h->p),t);
        return h;
}

void add(char *t){
        if(!strlen(t)){
                printf("Empty key cannot be added\n");
                return;
        }
        if(head == NULL){
                head = create_and_return(t);
        }

        //head != NULL
        LL *ptr = head;
        while(ptr->next != NULL){
                if(!strcmp(ptr->p,t)){
                        printf("Key [%s] already present, cannot add\n");
                        return;
                }
                ptr=ptr->next;
        }
        ptr->next = create_and_return(t);

        printf("Added [%s] set\n",t);
}

void search(char *t){
        printf("\nSearching [%s] in set\n",t);
        if(!strlen(t)){
                printf("Empty key cannot be searched\n");
                return;
        }
        if(!head){
                printf("set is empty\n");
                return;
        }
        LL *ptr = head;
        while(ptr != NULL){
                if(!strcmp(ptr->p,t)){
                        printf("Key [%s] found in set\n",t);
                        return;
                }
                ptr=ptr->next;
        }
}

int main(){
        add("test");
        add("here");
        add("");
        add("test");
        search("here");
}
/*
# gcc implementing_set.c
# ./a.out
Added [test] set
Added [here] set
Empty key cannot be added
Key [test] already present, cannot add

Searching [here] in set
Key [here] found in set
*/
#endif
