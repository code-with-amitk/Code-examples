### Round-1 //Coding
- _1._ About last 2-3 projects
- _2._ sizeof struct
```c
  struct {
    int a;    //4
    char b;
    short c;  //4
    char d;   //4
    int e;    //4
  };    //16    
```
- _3._ if we have 265 switches. all turned off. After below operations, count number of switches turned on?
```c
  flip every 2nd switch.
  flip every 3rd switch.
  flip every 5th switch.
  flip every 7th switch.
  flip every 13th switch.
  
  bool a[266] = {0};          //skipping 1st place
  for (int i=0;i<266;++i){
    if (!a[i]%2)  a[i]=!a[i];
    if (!a[i]%3)  a[i]=!a[i];
    if (!a[i]%5)  a[i]=!a[i];
    if (!a[i]%7)  a[i]=!a[i];
    if (!a[i]%13)  a[i]=!a[i];
    if(a[i])  ++count;
  }
  cout << count;
```
- _3._ Turning on bits from postition=n to m in 1 go without loop.
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
//Macro
#define CreateMask(start,end) \
  ((1 << (start-1)) - 1) ^ \
  ((1 << end) - 1)

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
  //OR
  printf("%d", a|CreateMask(start,end));
}
```
