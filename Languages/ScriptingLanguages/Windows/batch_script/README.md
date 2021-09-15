- **loops**
  - [for](#for)
- [variables](#var)

## Batch Script
.bat, .cmd, .btm are file extension of windows shell script for DOS/Windows.


## loops
<a name=for></a>
### for()
**Iterating thru range**
```c
for /L %%variable IN (lowerlimit,Increment,Upperlimit) DO do_something
  - /L switch tells that loop is used to iterate through range
  - %%loop Variable. Variable is declared using %% at the beginning of the variable name.
  - IN list contains:
    lowerlimit, increment, upperlimit. Loop starts at lowerlimit & move to the upperlimit value, iterating each time by the Increment value.
    
@ECHO OFF 
FOR /L %%X IN (0,1,3) DO ECHO %%X
1
2
3
```

<a name=var></a>
### variables
```c
  Variable       |    Meaning
-----------------|-------------
  %%i            |  loop variable (see for above)
  ~ni            |  File name without extension
```
