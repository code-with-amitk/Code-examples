- [Check nth bit](#c)
- Find 
  - [jth bit](#f1)
  - [1st on bit from LSB](#f2)
- [Multiply/Divide by 2](#md)
- Toggle
  - [nth Bit](#tn)
  - [All Bits](#ta)
  - [nth to mth Bit(Both inclusive)](#tnm)
- [Turn on/off nth bit](#tof)

<a name=c></a>
### Check 5th bit
```c
   0000 0110   //6
&  0001 0000   (1<<5) 
--------------
   0000 0000    //off
```

### Find 
<a name=f1></a>
#### jth bit  //Find 5th bit of 42
```c
    00101010   //42
  & 00010000   
  -----------
     ans     //if ans=0,bit=0   else 1
```
<a name=f2></a>
#### 1st on bit from LSB
```c
Ans:2nd bit is on from LSB of 42

        00101010   //42
~42     11010101   //1's complement
~42+1   11010110   //2's complement

        00101010   //42
 &      11010110   //2's complement
  ----------------
        00000010
```

<a name=md></a>
### Multiply/Divide by 2
```c
  0000 0110   //6
  0000 1100   //6*2=12 = Left shift by 1
  0000 0011   //6/2=3  = Right shift by 1
```



### Toggle (XOR)
<a name=tn></a>
#### 5th bit
```c
xor: same=0, diff=1
       0000 0110   //6
^xor   0001 0000  //(1<<5)
      -----------
       0001 0110

void Toggle_nth_Bit(int a, int n){
  int b = 1;
  b <<= n-1;
  a = a ^ b;
  PrintBinary(a);
}
```
<a name=ta></a>
#### Toggle all
- [PrintBinary()](/Languages/Programming_Languages/C/Bitwise/Print_Binary_Representation.md)
```c
void ToggleReverseAll(int a){
  a = ~a;
  PrintBinary(a);
}
```
<a name=tnm></a>
#### Toggle nth to mth bit(Both inclusive)
- **Logic**
  - Let's suppose input number=4 and we need to toggle 2nd to 5th bit(both inclusive)
```c
Input a = 4 = 00100000000000000000000000000000, n=2,m=5.
Output: 0 1 0 1 1 0 0 0 000000000000000000000000    //2nd to 5th bit toggled
        1 2 3 4 5 6
```
  - *1.* Create a number with all bits on from n to mth position.
```c
  b = 01111000000000000000000000000000
```
  - *2.* XOR the number with original number.
- **Code**
```c
void ToggleFrom_n_to_m(int a, int n, int m){
  int b=1, i=1, c=0;
  
  b <<= n-1;              //1
  c = b;
  while(i++<m-n){
    c <<= 1;
    b |= c;
  }
   
  a ^= b;                 //2
  PrintBinary(a);
}
```


<a name=tof></a>
### Turn On/Off
#### Turn on 5th bit
```c
   0000 0110   //6
|  0001 0000   (1<<5)
--------------
   0001 0110
```
#### Turn off 3rd bit
```c
   0000 0110   //6
&  1111 1011   ~(1<<3) 
--------------
   0000 0010
```
