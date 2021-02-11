## 1. Reverse/Toggle all bits
- [PrintBinary()](/Languages/Programming_Languages/C/Bitwise/Print_Binary_Representation.md)
```c
void ToggleReverseAll(int a){
  a = ~a;
  PrintBinary(a);
}
```

## 2. Toggle nth bit
- **Logic**
  - Create a number `b` by shifting 1 to nth place.
  - XOR `^` b and a. same bit=0, diff=1
```c
Eg:
  a: 00000100000000000000000000000000
  n: 3
  
Step-1:  b=00100000000000000000000000000000
Step-2:   a = 00000100000000000000000000000000
        ^ b = 00100000000000000000000000000000
        --------------------------------------
              0010010000000000000000000000000
  
void Toggle_nth_Bit(int a, int n){
  int b = 1;
  b <<= n-1;
  a = a ^ b;
  PrintBinary(a);
}
```

## 3. Toggle n to mth bit
```c

```
