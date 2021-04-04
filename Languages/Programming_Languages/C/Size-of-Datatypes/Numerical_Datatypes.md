## Numerical Datatypes
- Its of 2 types:
  - Scalar
  - Packed

### Scalar datatypes
- **What?** Perform calculations with discrete values
```html
Type                  Size-in-Bytes   Equivalent_C/C++
Signed integers           8                 char
                         16                 short
                         32              int, long
                         64              long long
                         
Unsigned integers         8            unsigned char
                         16            unsigned short
                         32        unsigned int, unsigned long
                         64           unsigned long long
                         
Floating-point           32             float
                         64             double
                         80             long double
```

### Packed Data Types
- **What?** These are used to perform SIMD calculations using either integers or floating-point values. Example
  - A 64-bit wide packed data type can be used to hold:
    - 8 8-bit integers OR
    - 4 16-bit integers OR 
    - 2 32-bit integers.
```html
Packed_Size_(Bits)      Data_Element_Type     Number_of_Items
64                      8-bit integers             8
                        16-bit integers            4
                        32-bit integers            2

128                     8-bit integers            16
                        16-bit integers            8
                        32-bit integers            4
                        64-bit integers            2
                  Single-precision floating-point  4
                Double-precision floating-point    2

256                     8-bit integers             32
                        16-bit integers            16
                        32-bit integers             8
                        64-bit integers             4
              Single-precision floating-point       8
              Double-precision floating-point       4
```
