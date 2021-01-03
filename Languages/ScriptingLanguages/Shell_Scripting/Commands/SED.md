## SED(STREAM EDITOR) Command
- **What** For performing file operations(Search Text, Find and replace, Insert, delete) without opening files.

## Examples
```c++
# cat test.txt
unix is great os. linux is opensource. linux is free os.
learn operating system.
unix linux which one you choose.
unix is easy to learn.linux is a multiuser os.Learn linux .linux is a powerful.
```
### Replacing
```c
$ sed 's/unix/linux/g' test.txt       //Replace all occurence of unix with linux
$ sed 's/unix/linux/2' test.txt       //Replace 2nd occurence of unix with linux
$ sed '3 s/unix/linux/' test.txt      //Replace occurence only on 3rd line
$ sed '1,3 s/unix/linux/' test.txt    //Replace occurence only on 1st,3rd line

### Deleting
$ sed 'nd' test.txt                   //Delete nth line from file
$ sed '$d' test.txt                   //Delete last line from file
$ sed '/pattern/d' test.txt           //Delete pattern matching line
```
