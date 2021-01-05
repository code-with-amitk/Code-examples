### While loop
```bash
#!/usr/bin/env bash     #Shebang if present should be 1st line of bash(else it will be ignored like comment). This tell which interpreter should be used to interpret the file

INPUT=$1
START=0                     #Local variable, there should be no gap around =

while [ $START -lt $INPUT ]
do
  echo "Value: $START"
  ((++START))               #Variable is increated inside double (())
done

$ test.sh 5
Value: 0
Value: 1
Value: 2
Value: 3
Value: 4
```
