**Trie**


### Trie / Prefix tree / Digital search tree / Retrieval tree
- Trie is variant of an n-arytree in which characters are stored at each node. Each path down the tree may represent a word.
- **Null nodes or * Nodes:** are often used to indicate complete words.
- **Usage of Trie:** Trie is used to store the entire (English) language for quick prefix lookups. It can tell us if a string is a prefix of any valid words.
- Data structure used for efficient storage/retrieval/deletion of strings.

<img src=images/trie.JPG width=500/>

# Implementations
## 1. APPROACH-1(Using Hash-table/unordered_map)
### Data structure
```c++
struct Trie{ 
    unordered_map<char, Trie*> map;
    bool isEndOfWord; 
};
```
### Logic for storage of 'ant'
- Allocate trie node.
- At every alphabet to be stored:
```c++
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
```
### Complexity
  - Time Complexity: O(m).  //m is number of characters in word to be stored.
  - Space Complexity: O(m+n) //n is number of words
### Code
```c++
#include<iostream>
#include<string>
#include<unordered_map>

struct Node{
  std::unordered_map<char, Node*> map;
  bool bEndOfWord;
};

Node* GetNode() {
  Node* pNode = new Node;
  pNode->bEndOfWord = false;
  return pNode;
};

void InsertWord(Node* pRoot, std::string strWord) {
  if(not pRoot)
    return;

  for(const auto& i : strWord) {

    //if character is not Found in map, Create a new node
    if(pRoot->map.find(i) == pRoot->map.end())
      pRoot->map[i] = GetNode();

    pRoot = pRoot->map[i];    //Move to newly created Node
  }
  pRoot->bEndOfWord = true;
}
bool SearchWord(Node* pRoot, std::string strWord) {

  for(const auto& i : strWord) {
    if(pRoot->map.find(i) == pRoot->map.end())    //Character not in map
      return false;

    //Key is found. Move to next char   map[key]=value is address of NextNode
    pRoot = pRoot->map[i];
  }

  return (pRoot->bEndOfWord);
}
int main(){
  Node* pRoot = GetNode();
  InsertWord(pRoot, "can");
  InsertWord(pRoot, "cat");

  if (SearchWord(pRoot, "can"))
    std::cout << "can Found\n";
  else
    std::cout << "can Not Found\n";

  if (SearchWord(pRoot, "cat"))
    std::cout << "cat found\n";
  else
    std::cout << "cat Not found\n";

  if (SearchWord(pRoot, "hello"))
    std::cout << "hello found\n";
  else
    std::cout << "hello Not found\n";

  return 0;
}
$ ./a.out
can Found
cat found
hello Not found
```

## 2. Approach-2(using pointer array)
- **Logic for storage of 'ant':**
- Allocate trie node, which contains 26 pointers and bool.
- Caculate ascii value difference of character to be stored. eg: n-'a'=13
- Allocate a new trie node and place address on 13th index.
```c++
struct TrieNode{
    struct TrieNode *children[ALPHABET_SIZE];           //ALPHABET_SIZE = 26;
    bool isEndOfWord;
};      //26 pointers present on every trie node.
```
### Code
```c++
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
```
