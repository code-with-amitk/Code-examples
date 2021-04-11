## Extract last 4 bits of a number
> Input = 171 = 1010 1011

### Logic
- *1. Get all 1's for bits to be extracted*
```c
1          = 0000 0001
a = 1 << 4 = 0001 0000      //Left shift 1 by 4
b = a - 1  = 0000 1111      //Subtract 1 to get 4 1s
```
- *2. AND number with b*
```c
b       = 0000 1111
              &
number  = 1010 1011
          __________
          0000 1011       <<< Extracted last 4 bits
```
### Code
```c
int main() {
    int number = 171              //1010 1011
    int a = 1 << 4;
    a -= 1;                       //0000 1111

    printf ("%d", a & number);    //0000 1011
    return 0;
}
```
