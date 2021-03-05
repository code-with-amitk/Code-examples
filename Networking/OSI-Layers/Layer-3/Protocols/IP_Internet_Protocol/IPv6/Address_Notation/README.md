## IPv6 Address Notation
- 128/8 = 16 bytes. IPv6 has 8 blocks seperated by colon(:). Each block contains 2 bytes(16 bits). 4 bits create 1 character.
- Example:
```c
//4 bits create 1 decimal representation.
0010000000000001 0000000000000000 0011001000111000 1101111111100001 0000000001100011 0000000000000000 0000000000000000 1111111011111011 
  2001          :        0000    :      3238      :     DFE1       :    0063        :    0000        :   0000         :    FEFB         //hex format
```                

### Rules of Shrinking IPv6 Address
- Despite conversion to Hex format, IPv6 remains bit longer these rules can be applied to shorten the IPv6 address.
  - *1.* Discard Leading Zeros: Example: discard 00 from front of 0063.
```c
2001:0000:3238:DFE1:0063:0000:0000:FEFB
shrinks to
2001:0000:3238:DFE1:63:0000:0000:FEFB 
```
  - *2.* Omit consecutive blocks that have all Zeros, Replace with (::).
```c
2001:0000:0000:0000:0000:0000:0001:d456
shrinks to
2001::1:d456
```
  - *3.* Shrink to 1 0: If all digits are Zero in block, It can be shrunk to 0. 2nd block shrunken to 0. 
```c
2001:0000:3238:DFE1:63::FEFB 
to
2001:0:3238:DFE1:63::FEFB 
```
