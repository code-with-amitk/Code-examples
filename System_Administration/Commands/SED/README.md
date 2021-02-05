## SED(Stream Editor)
- For performing file operations(Search Text, Find and replace, Insert, delete) without opening files.
### Replace Commands
```linux
  $ sed 's/unix/linux/g' test.txt       //Replace all occurence of unix with linux from file test.txt
    
  $ sed 's/unix/linux/2' test.txt       //Replace 2nd occurence of unix with linux
    
  $ sed '3 s/unix/linux/' test.txt      //Replace occurence only on 3rd line
    
  $ sed '1,3 s/unix/linux/' test.txt    //Replace occurence only on 1st,3rd line
```    
