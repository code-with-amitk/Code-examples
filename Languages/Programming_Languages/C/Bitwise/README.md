- [Check nth bit on or off](#c)
- Extract Bits
  - [Extract mth to nth bits](#emn)
  - [Extract last 4 bits](#el)
- Find 
  - [nth bit](#f1)
  - [1st on bit from LSB](#f2)
- [Multiply/Divide by 2](#md)
- Toggle
  - [nth Bit](#tn)
  - [All Bits](#ta)
  - [nth to mth Bit(Both inclusive)](#tnm)
- Turn on/off
  - [nth bit](#tof)
  - [nth to mth Bit](#tmn)


<a name=c></a>
### Check 5th bit
```c
   0000 0110   //6
&  0001 0000   (1<<5) 
--------------
   0000 0000    //off
```

### Extract Bits
<a name=emn></a>
#### Extract mth to nth bits
```c
  1010 1011               //171
  m = 6, n = 1. Extract 6th to 1nd bit of number = 101011

//////Logic/////
1. Shift bits to be extracted on right most. ie shift number by 1
  01010101   (171 >> 1) 

2. Create mask with last 5 1's
    0000 0001   a=1
    0100 0000   a<<5
    0011 1111   a=a-1
    
3. AND number with mask
    1010 1011
  & 0011 1111
  ------------
    0010 1011

////////Code///////////
int main(){
    int number = 171, k = 5, p = 1;
    int a = 1 << 5;
    a -= 1;
    number >>= 1;
    printf ("%d", a & number);
}    
```
<a name=el></a>
#### Extract last 4 bits
```c
int main() {
    int number = 171              //1010 1011
    int a = 1 << 4;
    a -= 1;                       //0000 1111

    printf ("%d", a & number);    //0000 1011
    return 0;
}
```

### Find 
<a name=f1></a>
#### nth bit  //Find 5th bit of 42
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

### Turn On/Off
<a name=tof></a>
#### 1. Turn on 5th bit
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
<a name=tmn></a>
#### 2. Turn on mth to nth bit
```c
    0000 0100     //4
    8765 4321
    
    0111 0100     //Turn on 5th to 7th bit

//////Logic///////
1. Create mask of on bits from 5th t0 7th. mask = 0111 0000
2. OR with number.

/////////////Code///////////////
int main() {
  int a = 4, start = 5, end = 7;

  //Creating mask
  int b = start-1;  //0000 0100
  b = 1<<b;         //0001 0000
  b = b - 1;        //0000 1111

  int c = 1<<end;   //1000 0000
  c = c - 1;        //0111 1111

  int mask = b ^ c; //0000 1111 = b
                    //0111 1111 = c
                    //0111 0000

  printf("%d", a|mask);
}
```

