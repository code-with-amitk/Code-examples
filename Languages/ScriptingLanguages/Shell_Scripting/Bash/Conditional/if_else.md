## if else statement
```bash
#!/usr/bin/env bash

COLOR=$1                                //1st Command Line parameter. Note there should be no gap between words and `=`

if [ $COLOR = "blue" ]
then
  echo "sky is blue"
fi

TEMPRATURE=$2                       //2nd Commandline parameter.
MAX=50

if [ $TEMPRATURE -lt $MAX ]         //-lt:less than, -nt:Not equal, -gt:Greater than, -ge:Greater than or equal to
then
  echo "it's cold"
elif [ $TEMPRATURE -gt $MAX ]       //ELSE IF
then
  echo "it's too cold"  
else                                //ELSE
  echo "it's hot"
fi 

$ ./test.sh blue 100
sky is blue
it's hot
```
