### [Search a Word in a 2D Grid of characters](https://www.geeksforgeeks.org/search-a-word-in-a-2d-grid-of-characters/)
- Given a word search word in 8 directions in grid.
![ImgURL](https://media.geeksforgeeks.org/wp-content/cdn-uploads/Search_a_Word.png)

### Logic
```c++
//                N(-1,0)
//      NW(-1,-1)          NE(-1,1)
//W(0,-1)          x,y           E(0,1)
//      SW(1,-1)          SE(1,1)
//                S(1,0)

vec1d x = {-1,-1,0,1,1,1,0,-1};   //X coordinates
vec1d y = {0,1,1,1,0,-1,-1,-1};   //y coordinates
```
