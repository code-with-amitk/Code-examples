## Symbols

|Symbol|Meaning|
|---|---|
|$1(global)|$1:1st Command line argument, $2:2nd command line argument so on|
|$1(inside function)|$1:1st function parameter $2: 2nd parameter so on|
|$@(global)|Accepts all command line arguments in an array|
|$@(inside Function)|Accepts all function parameters in an array|
|$?|Exit status of last executed Command/script|
|$#|Total number of command line arguments|

## shebang
> #!/usr/bin/env bash
- **What** if present should be 1st line of bash(else it will be ignored like comment). This tell which interpreter should be used to interpret the file.   
```c
  #!/usr/bin/env bash       //shebang for bash 
  #!/usr/bin/env python     //shebang for python
  #!/usr/bin/env node       //shebang for nodejs
```    
