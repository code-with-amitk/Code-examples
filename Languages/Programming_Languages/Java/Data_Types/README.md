**Datatypes**
- [Primitive](#pr)
- **Non-Primitive**
  - [1. String](#st)
    - [compare](#com)
    - [Case convert](#cas)
    - [Substring](#sub)

## Datatypes
<a name=pr></a>
### Primitive Datatypes
```java
datatype| size (byte) | Range
  ------|-------------|--------------
  Byte  | 1   signed  | -128 to 127
  short | 2           | -32768 to 32767
  int   | 4           | -2pow31 to 2pow31-1
  long  | 8           | -2pow63 to 2pow63-1
  float | 4           | 
  double| 8           |
  bool  | 1           | 
  char  | 2           |
```

## Non-Primitive
<a name=st></a>
### 1. String
```java
String A = "test";
String B = "test1";
A.length();         //4
```
<a name=com></a>
#### compare
```java
String A = "test";
String B = "test1";

A.compareTo(B);     //-1
if s1 > s2, it returns positive number  
if s1 < s2, it returns negative number  
if s1 == s2, it returns 0  
```
<a name=cas></a>
#### Case convert
```java
//Convert "hello" to "Hello"
String A = "hello";
System.out.print(A.substring(0, 1).toUpperCase() + A.substring(1));
```
<a name=sub></a>
#### Substring
```c
//substring(start_index, end_index-1);
            0123456789
String A = "testisgood";
System.out.println(A.substring(3,8));     //tisgo (from 3 to 7)
```
