## Integer Type
- Integers can be signed(-ve, +ve  both) and unsigned(takes +ve values).
- Signed Number are stored using [2's Compliment](/Languages/Programming_Languages/C/Bitwise/Representation_of_Numbers).
- **Sizes of Integers**

|Length(bits)|Signed|Unsigned|
|---|---|---|
|8  (2<sup>8</sup> -1 = 255)|i8 (-128 to 127)|u8(0 to 255)|
|16 |i16|	u16|
|32	|i32	|u32|
|64	|i64	|u64|
|128	|i128	|u128|
|arch (Depends on computer architecture. 32bit on 32bit Arch. 64bit on 64bit Arch)	|isize	|usize|

- **Writing Integer Literals**

|Number literals|	Example|
|---|---|
|Decimal can be written as|98_222|
|Hex	|0xff|
|Octal	|0o77|
|Binary	|0b1111_0000|
|Byte (u8 only)|	b'A'|

- **[Integer Overflow](Integer_Overflow)**
