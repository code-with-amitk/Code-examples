### Turn on mth to nth bit of a number
- **Example**
```c
Example-1
input a = 4   //0000 0100
                8765 4321
start=5, end=7
output        //0111 0100

Example-2
input a = 4   //0000 0100
                8765 4321
start=2, end=5
output        //0001 1110
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
