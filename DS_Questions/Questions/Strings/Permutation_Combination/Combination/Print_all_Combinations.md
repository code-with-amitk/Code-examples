## Question
- Find all combinations of given string.
- Formula: 
<sup>n</sup>C<sub>r</sub> = n!/r!(n-r)!
```c
Input = abcd
Output:
a     //Taken 1 at time
b
c
d

ab    //Taken 2 at a time
bc
cd
da
ac
bd

abc   //Taken 3 at a time
bcd
cda
acd
abd

abcd  //Taken 4 a time
```
