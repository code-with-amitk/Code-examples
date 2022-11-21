**Number System**
- [Base 62 Number System](#b62)

## Number System
Technique to represent numbers in the computer system architecture, every value that you are saving or getting into/from computer memory has a defined number system.

## Types of Number Systems
### Binary(Base 2)
- Uses 2 digits(0, 1). Every number is represented using 0 and 1. Base of binary number system is 2, because it has only two digits.
- **Converting number to Binary format**
  - Divisor=Base. Reminders=Converted to New number system
<image src=images/dec_to_binary.jpg width=300/>

### 2. Octal(Base 8)
Has 8 digits(0 to 7). Every number represents with 0,1,2,3,4,5,6 and 7 in this number system. Base of octal number system is 8, because it has only 8 digits.
### 3. Decimal(Base 10)
  - Has only 10 digits(0 to 9). Every number represents with 0,1,2,3,4,5,6, 7,8 and 9 in this number system. The base of decimal number system is 10, because it has only 10 digits. Most popular since we have 10 fingers.
### 4. Hexadecimal(Base 16)
  - Has (16) alphanumeric values (0-9 & A-F). Every number represents with 0,1,2,3,4,5,6, 7,8,9,A,B,C,D,E, F in this number system. 

<a name=b62></a>
### Base 62 Number System
- Has 62 values(a-z,A-Z,0-9) to represent a number.
- How many different numbers can be created if we take 6 (base62 numbers).
```c
_    _    _    _    _    _   //Every place can be filled with 62 values
p1   p2   p3   p4   p5   p6
62 x 62 x 62 x 62 x 62 x 62   = 62pow6 ways
```
- 62<sup>6</sup> = 56,800,235,584 = 56 Billion URLs
- **Converting Decimal to Base62 format**
<img src=images/dec_to_base62.jpg width=800/>

### 5. BASE 64 NUMBER SYSTEM
  - Has 62 values (a-z,A-Z,0-9) and 2 other values(!@) to represent a number.
### 6. BASE 256
  - ASCII chart defines 256 different letters alltogether.
