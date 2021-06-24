- [1. Data Types](#datatypes)
  - [1.1 Scalar Data Type](#scalardatatypes)
    - [1.1.a int](#intdatatype)
      - [int overflow](#intoverflow)
      - [Array slice](#arrayslice)
    - [1.1.b float](#floatdatatypes)
    - [1.1.c bool](#booldatatype)
    - [1.1.d char](#chardatatype)


<a name="datatypes"></a>
# Data Types
- *Type Annotation?*  When many types are possible. Eg: String converted to a int using parse(), we must add a type annotation to tell type to complier.
```rust
  let a = 1;        //a inferred int
  let b = "get";    //b inferred string
  
  let c:u32 = "42".parse().expect("Not a number!");            //Type Annotation u32
```

<a name="scalardatatypes"></a>
## 1.1 Scalar Data Type
- A scalar type represents a single value. Rust has 4 primary scalar types: int, float, bool, char

<a name="intdatatype"></a>
### 1.1.a int
- Integers can be signed(-ve, +ve  both) and unsigned(takes +ve values).
- Signed Number are stored using [2's Compliment](/Languages/Programming_Languages/C/Bitwise/Representation_of_Numbers). 
- **Size of Integers:**
```c
Length(bits)	Signed	            Unsigned
  8           	i8 (-128 to 127)	u8(0 to 255)
  16	          i16	              u16
  32	          i32	              u32
  64	          i64	              u64
  128   	      i128	            u128
  arch 	        isize	            usize
//arch: Depends on computer architecture. 32bit on 32bit Arch. 64bit on 64bit Arch
```
- **Writing Integer Literals**
```c
Number literals 	          Example
Decimal can be written as   98_222
Hex	                        0xff
Octal	                      0o77
Binary	                    0b1111_0000
Byte (u8 only)            	b'A'
```

<a name="intoverflow"></a>
#### Integer Overflow
- Assigning value outside of allowed range. Example:
```rust
  let a:u8 = 256      //This is integer overflow, because u8 0-255 values can be assigned
```  
- *Compiled in debug mode?* When program is compiled in debug mode, Rust includes checks for integer overflow & program will PANIC(exit with error) at runtime.
- *Compiled in release mode(--release flag)*
  - When program is compiled in release mode, Rust DOES NOT include checks for integer overflow. At runtime, overflow occurs Rust performs 2’s complement wrapping. 
  - *2’s complement wrapping?* Values greater than 255 gets wrapped around. 256 becomes 0. 257 becomes 1 and so on. No PANIC happens.

<a name="arrayslice"></a>
#### Array Slice
- Read [String Slice](../) to understand How slices are stored and their type. Array Slice is taking piece of array.
- Type of Array slice is `&i[32]`
```rust
fn main() {
    let a = [1,2,3,4,5];
    let b = &a[1..3];             //Type of b is &[i32]
    println!("{}",b[0]);
}
```

<a name="floatdatatype"></a>
### 1.1.b Floating-Point Types
- Floating point are of 2 sizes f32(32 bit), f64(64 bit). 
- f64 is default. Why f64 is default, because on modern CPUs f64 is roughly the same speed as f32 but is capable of more precision.
```rust
fn main() {
    let x = 2.0;          //f64
    let y: f32 = 3.0;     //f32
}
```
- *All operations are supported on float*
```rust
fn main() {
    let sum = 5.2 + 10.1;               //addition
    let difference = 95.5 - 4.3;        //subtraction
    let product = 4 * 30;               //multiplication
    let quotient = 56.7 / 32.2;         //division
    let remainder = 43 % 5;             //remainder
}
```

<a name="booldatatype"></a>
### 1.1.c Boolean type
- Booleans are one byte in size. Can have 2 values: true, false.
```rust
fn main() {
    let a = true;
    let b: bool = false;      //with explicit type annotation
}
```

<a name="chardatatype"></a>
### 1.1.d Character Type
- char literals are specified with single quotes and string literals use double quotes.
- Size of char type = 4 bytes
- Letters: Chinese, Japanese, and Korean characters; emoji; and zero-width spaces are all valid char values in Rust
```rust
fn main() {
    let c = 'z';
    let z = 'ℤ';
    let heart_eyed_cat = '😻';
}
```
