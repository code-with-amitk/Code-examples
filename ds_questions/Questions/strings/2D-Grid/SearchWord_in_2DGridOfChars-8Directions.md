### [Search a Word in a 2D Grid of characters](https://www.geeksforgeeks.org/search-a-word-in-a-2d-grid-of-characters/)
- Given a word search word in 8 directions in grid.
![ImgURL](https://media.geeksforgeeks.org/wp-content/cdn-uploads/Search_a_Word.png)

### Logic
- *1.* From every cell, find matching character in 8 directions. if found move to that direction.
```c++
//                N(-1,0)
//      NW(-1,-1)          NE(-1,1)
//W(0,-1)          x,y           E(0,1)
//      SW(1,-1)          SE(1,1)
//                S(1,0)

vec1d x = {-1,-1,0,1,1,1,0,-1};   //X coordinates
vec1d y = {0,1,1,1,0,-1,-1,-1};   //y coordinates
```
- *2.* Compare next character in word, when (length of word == present character to be compared). return true

### Complexity
- **Space:** `2xvector<int>(8)`
- **Time:** m:rows, n:cols. k:length of word to searched, l:Number of words to be searched
  - O(mn) + O(kl)

### Code
```c++
#include<iostream>
#include<vector>
using vec1d = std::vector<int>;
using vec2d = std::vector<vec1d>;
using String = std::string;

//              N(-1,0)
//    NW(-1,-1)       NE(-1,1)
//W(0,-1)       x,y         E(0,1)
//    SW(1,-1)        SE(1,1)
//              S(1,0)
vec1d x = {-1,-1,0,1,1,1,0,-1};   //X coordinates
vec1d y = {0,1,1,1,0,-1,-1,-1};   //y coordinates

bool Search(vec2d& v, int i, int j, String& word,int k){
  bool ret = false;
  if(v[i][j] != word[0])
    return false;

  int len = word.size();
  int ROWS = v.size();
  int COLS = v[0].size();

  if (k == len)
    return true;

  //check 8 directions
  for(int k=0;k<8;++k){
    int r = i+x[k], c = j+x[k];
    if(r >= ROWS || r <0 || c <0 || c>=COLS)
      continue;

    if(v[r][c] == word[k])
      ret = Search(v,r,c,word,k+1);
  }
  return ret;
}

bool SearchWord(vec2d& v, String& word){
  int k=0;
  int row = v.size();
  int col = v[0].size();
  int wordLen = word.size();
  for (int i=0; i<v.size(); ++i)
    for (int j=0; j<v[0].size(); ++j)
      if (v[i][j] == word[k]){
        if(Search(v,i,j,word,0))
          return true;
      }
}

int main(){
  vec2d v = {
    {'t','s','e','d','e'},
    {'f','g','t','e','h'},
    {'i','e','j','k','s'},
    {'l','s','n','t','o'},
    {'p','q','r','s','t'}
  };
  String word = "test";
  std::cout<<SearchWord(v, word);
}
```
