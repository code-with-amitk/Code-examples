## for break continue
```bash
#!/usr/bin/env bash         #if present should be 1st line of bash(else it will be ignored like comment). Tell which interpreter should be used to interpret the file

NAMES=$@                    #$@ stores all input parameters in an Array

for VAR in $NAMES
do
  if [ $VAR = "google" ]
  then
    echo "Hello" $VAR "(break) statement"
    break
  elif [ $VAR = "vivek" ]
  then
    echo "Hello" $VAR "(continue) statement"
    continue
  else
    echo "Hello" $VAR "How are you?"
  fi
done

$ ./for.sh amit vivek google facebook
Hello amit How are you?
Hello vivek (continue) statement
Hello google (break) statement
```
