## Extract mth to nth bits of number
> Input = 171 = 1010 1011
- m = 5, n = 1. Extract 5th to 1st bit of number.

```c
Input = 171 = 1 0 1 0 1 0 1 1
position      7 6 5 4 3 2 1 0

Output:           1 0 1 0 1
```

### Logic
- *1. Shift bits to be extracted on right most*
```c
Input = 171 = 1 0 1 0 1 0 1 1
Shift (171 >> 1)
number =      0 1 0 1 0 1 0 1 
```
- *2. Extract last 5 bits.*
```c
a = 1               //0 0 0 0  0 0 0 1
a <<= 5             //0 1 0 0  0 0 0 0
a = a - 1           //0 0 1 1  1 1 1 1
```
- *3. AND number with a*
```c
number =      0 1 0 1 0 1 0 1 
a      =      0 0 0 1 1 1 1 1
              ________________
              0 0 0 1 0 1 0 1
```
### Code
```c
int main(){
    int number = 171, k = 5, p = 1;
    int a = 1 << 5;
    a -= 1;
    number >>= 1;
    printf ("%d", a & number);
}    
```
