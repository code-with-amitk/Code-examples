## Pipe
- **What?** it takes output of 1 program and pass to other.

### Example-1 
- Display 3 files in pwd in alphabetical decending order.
  - **ls -1** Runs ls command and limits output to 1
  - **sort -r** sort output in reverse order
  - **head -3** Only 3 items from output.
```bash
#!/usr/bin/env bash       #SHEBANG: if present should be 1st line of bash(else it will be ignored like comment). This tell which interpreter should be used to interpret the file.   

FILES=`ls -1 | sort -r | head -3`
COUNT=1

for VAR in $FILES
do
  echo "FILE $COUNT = $VAR"
  ((COUNT++))
done

$ ./test.sh
FILE 1 = while.sh
FILE 2 = var.sh
FILE 3 = test.sh
```
