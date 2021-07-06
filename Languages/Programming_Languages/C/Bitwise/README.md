- [1. Extract Bits](#extract)
  - [1.1 Extract mth to nth bits of number](#exmton)
  - [1.1 Extract last 4 bits](#last4)
- [2. Turn on Bits](#turnon)
- [3. Toggle bits](Toggle_Switch_Bits_XOR.md)
- [4. Count On Bits](#count)
  - [4.1 Iterative Approach](#iterative)


<a name=extract></a>
## 1.1 Extract Bits
<a name=exmton></a>
### 1.1 Extract mth to nth bits of number
> Input = 171 = 1010 1011
- m = 5, n = 1. Extract 5th to 1st bit of number.
```c
Input = 171 = 1 0 1 0 1 0 1 1
position      7 6 5 4 3 2 1 0
Output:           1 0 1 0 1
```
- **Logic**
  - _1._ Shift bits to be extracted on right most. ie shift number by 1
```c
Input = 171 = 1 0 1 0 1 0 1 1
number =      0 1 0 1 0 1 0 1   (171 >> 1) 
```
- _2._ Create mask with last 5 1's
```c
a = 1               //0 0 0 0  0 0 0 1
a <<= 5             //0 1 0 0  0 0 0 0
a = a - 1           //0 0 1 1  1 1 1 1
```
- _3._ AND number with mask
```c
number =      0 1 0 1 0 1 0 1 
a      =      0 0 0 1 1 1 1 1
              ________________
              0 0 0 1 0 1 0 1
```
- **Code**
```c
int main(){
    int number = 171, k = 5, p = 1;
    int a = 1 << 5;
    a -= 1;
    number >>= 1;
    printf ("%d", a & number);
}    
```
<a name=last4></a>
### 1.2 Extract last 4 bits
```c
int main() {
    int number = 171              //1010 1011
    int a = 1 << 4;
    a -= 1;                       //0000 1111

    printf ("%d", a & number);    //0000 1011
    return 0;
}
```

<a name=turonon></a>
## 2. Turn on mth to nth bit of a number
- Example
```c
input a = 4   //0000 0100
                8765 4321
start=5, end=7
output        //0111 0100
```
- **Logic**
  - _1._ Create mask. start=5,end=7. mask = 0111 0000
  - _2._ OR with number.
- **Code**
```c
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

<a name=count></a>
## 4. Count On Bits
<a name=iterative></a>
### 4.1 Iterative Approach
```c
    int CountOnes(int a){
        int i = 1, k = 1;
        int ones = 0;
        while (k++ != sizeof(int)*8) {
            if (a & i)
                ones++;
            i = i<<1;
        }
        return ones;
    }
```
