### Problem-1
- Read names from `names.txt` and print them with line numbers.
```c
# cat names.txt
amit
vivek
yogi
nitu singh
baba
```
### Solution-1
- *1. Shebang:* if present should be 1st line of bash(else it will be ignored like comment). This tell which interpreter should be used to interpret the file.
- *2.*
  - *a. IFS(Internal field Seperator):* How tokens are seperated in line we are reading. Here '' means tokens are seperated using space.
  - *b. read*: This is command to read file
  - *c. -r*: Read everything including backslashes
  - *d. PresentLine*: Variable name that holds current line read from file.
- *3.*
  - *$1* This 1st paramter passed to script, here filename=names.txt
  - *<* Redirection operator, pass names.txt as input.
```bash
#!/usr/bin/env bash                 #1 SHEBANG
COUNT=1                             #Counter variable

while IFS='' read -r PresentLine    #2
do
  echo "LINE $COUNT: $PresentLine"
  ((++COUNT))                       #Increment counter
done < "$1"                         #3

# ./test.sh names.txt
LINE 1: amit
LINE 2: vivek
LINE 3: yogi
LINE 4: nitu singh
LINE 5: baba
```
