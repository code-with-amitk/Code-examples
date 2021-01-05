### Command Line Parameters
```bash
# atom hello.sh
!#/usr/bin/env bash   //Shebang
echo Hello $1 $2              //$1:1st parameter, $2:2nd
echo Today's Date $(Date)     //Commands are kept in ()
echo Path $(pwd)

# ./hello.sh Amit Kumar
Hello Amit Kumar
Today's Date ..
Path ..

# echo $?                     //$? returns exit status of last executed command
0   
# echo $?                     //exit status of echo
0
```
