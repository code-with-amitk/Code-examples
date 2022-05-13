### Encode/Decode using ASCII
- Given a input string that can be encoded or not encoded. if input string is not encoded(encode it), if its encoded(decode it).
- Valid input characters:
```c
"A" 65    "a" 97    " " 32
"B" 66    "b" 98    "!" 33
. .                 "," 44
. .                 "." 46
. .                 ":" 58
"Y" 89    "y" 121   ";" 59
"Z" 90    "z" 122   "?" 63
```
- Algorithm to encode:
  - Reverse input string
  - Calculate ASCII of every character, Reverse ASCII Value also while creating output string.
- Example-1
```c
input = "Day !"   //not encoded message

ASCII Chart
  ascii   decimal
  !         33
  space     32
  y         121
  a         97
  D         68

Output = 33231217986
      ! yaD
     33321219768      
     33231217986
```
- Example-2: input is not encoded text
```c
Input: abc
Output: 998979
```
- Example-3: input is encoded text
```c
Input: 798999
Output: cba
```
- Example-4: Input is not encoded.
```c
Input: Have a Nice Day !
Output: 332312179862310199501872379231018117927
```

### Logic
- _1._ Check whether input is encoded or not-encoded string. if 1st character is digit then its encoded else not encoded
- _2._ Input = Not encoded string
```c
Input = Have a Nice Day !
        
Rev   = ! yaD eciN a evaH   //Reverse input string

        33321219768         //Calculate ASCII
        
        33231217986         //Reverse ASCII while storage
```
- _3._ Input = Encoded string. Steps opposite to not encoded string
```c
Input:    798999

          979899           //Reverse ASCII
          abc              //Calculate string
          cba              //Reverse string
```
