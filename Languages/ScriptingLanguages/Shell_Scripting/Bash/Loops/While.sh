### While loop
```bash
#!/usr/bin/env bash

COUNT=0                     //Local variable, there should be no gap around =

while [ $COUNT -lt 5 ]
do
  echo "count= $COUNT"
  ((COUNT++))               //Variable is increated inside double (())
done

$ test.sh
count= 0
count= 1
count= 2
count= 3
count= 4
```
