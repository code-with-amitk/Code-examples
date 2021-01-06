## Pipe
- **What?** it takes output of 1 program and pass to other.

### Example-1 (Function, Pipes)
- Create 2 functions `GetFiles(), ShowFiles()`
  - `GetFiles():` RETURNS 1st 3 files in current directory
  - `ShowFiles():` Takes files as argument(from pwd) and shows each with counter in alphabetical decending order.
- **ls -1 | sort -r | head -3**
```c
# ls -1             //Limits ls output to 1
pipe.sh
test.sh
var.sh
while.sh

$ ls -1 | sort -r   //sort output in reverse order
while.sh
var.sh
test.sh
pipe.sh

$ ls -1 | sort -r | head -3   //Only 3 items
while.sh
var.sh
test.sh
```
- **SCRIPT:**
```bash
# vim test.sh
#!/usr/bin/env bash       #SHEBANG: if present should be 1st line of bash(else it will be ignored like comment). This tell which interpreter should be used to interpret the file.

GetFiles(){                                       # RETURNS 1st 10 files in current directory
  local FILELIST=`ls -1 | sort -r| head -3`       # Local variable storing file list
  ShowFiles $FILELIST                             # Calling function with argument
}

function ShowFiles(){                             # Takes files as argument and shows each with counter
  local COUNT=1                                   # Local variable for Counter
  for VAR in $@                                   # $@: Takes all arguments passed to function in array
  do
    echo "File-$COUNT: $VAR"                      # show array passed as argument
    ((++COUNT))                                   # Increment counter
  done
}

GetFiles                                          # Call function named GetFiles

$ ./test.sh
File-1: while.sh
File-2: var.sh
File-3: test.sh
```
