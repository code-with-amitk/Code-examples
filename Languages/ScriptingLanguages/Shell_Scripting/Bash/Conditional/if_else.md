## if else statement
```bash
#!/usr/bin/env bash

COLOR=$1                                //Variables are taken as caps

if [ $COLOR = "blue" ]
then
  echo "sky is blue"
fi

TEMPRATURE=$2
MAX=50

if [ $TEMPRATURE -lt $MAX ]         //-lt:less than, -nt:Not equal, -gt:Greater than, -ge:Greater than or equal to
then
  echo "it's cold"
else
  echo "it's hot"
fi 

$ ./test.sh blue 100
sky is blue
it's hot
```
