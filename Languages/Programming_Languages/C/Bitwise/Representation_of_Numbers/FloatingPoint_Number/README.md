## Representing Floating Point Number
### 32 bit Representation
  - 1 Sign Bit: MSB. 1 for -ve, 0 for +ve
  - 8 bits: Exponent
  - 23 bits: Fraction
```c
31    30 29 28 27 26 25 24 23    22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
s       biased exponent                Fraction/Mantissa
```
#### Examples
- **a. 4.625 = 100.101**
```c
4 = 100
.625 = 101
.625 x 2 = 1.25 //Note 1
.25 x 2 = 0.5   //Note 0
.5 x 2  = 1.0   //Note 1
```
- **b. -7.75 = C0F8 0000**
```c
Sign = 1 (Since -ve)
7 = 111
.75 = 11
.75 x 2 = 1.5   //Note 1
0.5 x 2 = 1.0   //Note 1

-7.75 = -111.11

111.11  = 1.1111 x 2pow2    //Step-1: Convert to scientific notation.
Scientific notation means something as a.bcdef 

//Step-2: Calculating Exponent: Add 127 to power number
2 + 127 = 129 = 10000001

//Step-3: Calculating Mantissa: Drop leading 1 from scientific notation
1.1111 => 1111

sign  exponent    mantissa
 1    10000001    11110000000000000000000
 
Representing in Hex
1100 0000 1111 1000 0000 0000 0000 0000
  C   0     F   8     0   0     0   0     =>    C0F8 0000
```
- **c. -0.125 = BE00 0000**
```c
Sign = 1 (Since -ve)
0 = 0
.125 x 2 = 0.25   //Note 0
.25 x 2  = 0.5    //Note 0
0.5 x 2  = 1.0    //Note 1

-0.125 = -0.001

-0.001 = 1.00 x 2pow-3    //Step-1: Convert to scientific notation.

//Step-2: Calculating Exponent: Add 127 to power number
-3 + 127 = 124 = 01111100

//Step-3: Calculating Mantissa: Drop leading 1 from scientific notation
1.000 => 000

sign  exponent    mantissa
 1    01111100    00000000000000000000000
 
Representing in Hex
1011 1110 0000 0000 0000 0000 0000 0000
  B   E     0   0     0   0     0   0     =>    BE00 0000
```

### 64 bit Representation
- 1 bit: sign
- 52 bits: Fraction
- 11 bits: Exponent
```
63    62    52         51              0
s     Exponent         fraction/Mantissa
```
