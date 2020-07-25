/*
        trie_storage_retrieval.cpp

Trie(Prefix tree/Digital search tree/Retrieval tree):  
Data structure used for efficient storage/retrieval/deletion of strings.

Example of Storing strings:  ten,test
                                                root    //Always empty
                                                   |
                                                   t
                                                   |
                                                   e
                                                 / |
                                                n  s
                                                   |
                                                   t

********1. [using Hash-table(unordered_map)]**********
struct Trie{ 
    unordered_map<char, Trie*> map;
    bool isEndOfWord; 
};

Logic for storage of 'ant':
- Allocate trie node.
- At every alphabet to be stored:
        - Check alphabet is present in hash-table
                if(alphabet present) Go to child node
                if(alphabet not present) allocate child

Storage of 'ant','ans':
<key=a, value=Address of child node>

        |a|0x4|   |isEndofWord=0|
        hashtable

        |n|0x5|   |isEndofWord=0|
        0x4

        |t|0x6| |s|0x7|  |isEndofWord=0|
        0x5

        |<>|<>|isEndofWord=1|           |<>|<>|isEndofWord=1|
        0x6                             0x7

Time Complexity: O(m).  //m is number of characters in word to be stored.
Space Complexity: O(m+n) //n is number of words
*************************************************************


*******2. (using pointer array)***********
Logic for storage of 'ant':
- Allocate trie node, which contains 26 pointers and bool.
- Caculate ascii value difference of character to be stored. eg: n-'a'=13
- Allocate a new trie node and place address on 13th index.

struct TrieNode{
    struct TrieNode *children[ALPHABET_SIZE];           //ALPHABET_SIZE = 26;
    bool isEndOfWord;
};      //26 pointers present on every trie node.
*************************************************

#include<iostream>
#include<cstring>
#include<unordered_map>
using namespace std;


//****************1. (using unordered_map)**********************//  
struct Trie{
    unordered_map<char, Trie*> map;
    bool isEndOfWord;
};

Trie* getNode(){
        Trie *p = new Trie;
        p->isEndOfWord = false;
        return p;
};

void insert(Trie *root, const char key[]){
        if(root == nullptr) return;

        int ascii=0;
        Trie *p = root;

        for(int i=0;i<strlen(key);i++){

                if(p->map.find(key[i]) == p->map.end()){

                        std::pair<char,Trie*>test ((char)key[i],getNode());
                        p->map.insert(test);

                }

                p = p->map.at(key[i]);          //m={"first",1}. m.at("first")=1
        }
        p->isEndOfWord = true;
}

bool search(Trie *root, const char key[]){
        Trie *p = root;

        for(int i=0;i<strlen(key);i++){
                if(p->map.find(key[i]) == p->map.end())
                        return false;

                //Key is found. Move to next char
                p = p->map.at(key[i]);
        }

        return (p->isEndOfWord);
}
//*******************************************************//


/**********2. (using pointer array) DONOT USE THIS KEPT JUST FOR REF***********
#ifdef APPROACH_1
const int ALPHABET_SIZE = 26; 
  
typedef struct TrieNode{ 
    struct TrieNode *children[ALPHABET_SIZE]; 
    bool isEndOfWord; 
}TRIE; 
  
TRIE *getNode(void){ 
        TRIE *ptr =  new TrieNode; 

        ptr->isEndOfWord = false; 
        for (int i = 0; i < ALPHABET_SIZE; i++) 
                ptr->children[i] = NULL; 
  
        return ptr; 
} 

void insert(TRIE *root, const char key[]){

    TRIE *p = root; 
    int t;                                      //This will be index in children array

    //strlen("ant") = 3
    for (int i = 0; i < strlen(key); i++){ 

        //
         // t = a - 'a' = 0
         // t = n - 'a' = 110-97 = 13
         // t = t - 'a' = 116-97 = 19
        // t = s - 'a' = 115-97 = 18
         //
        int t = key[i] - 'a';

        if (p->children[t] == NULL)                     //Check children is free
                p->children[t] = getNode();             //Yes, point to new node
  
        p = p->children[t];                             //Move pointer to point base address of allocated child
    }
  
    p->isEndOfWord = true;                              // mark last node as leaf
} 
  
bool search(TRIE *root, const char key[]) 
{ 
    TRIE *ptr = root;
    int t;
  
    for (int i = 0; i < strlen(key); i++){

        t = key[i] - 'a';                       
        if (ptr->children[t] == NULL)
            return false;
  
        ptr = ptr->children[t];                         //if address is present. Move to child node and let's check again
    } 
  
    if(ptr != NULL && ptr->isEndOfWord)
           return true; 

    return true;
} 
#endif
***********************************************************/
int main(){

        bool result = false;
        Trie *root = getNode();

        insert(root, "ant");
        insert(root, "ans");

        if (search(root, "ank"))
                cout << "ank Found\n";
        else
                cout << "ank Not Found\n";

        if (search(root, "ant"))
                cout << "ant found\n";
        else
                cout << "ant Not found\n";

        return 0;
}
/*
# ./a.out 
ank Not Found
ant found
*/
