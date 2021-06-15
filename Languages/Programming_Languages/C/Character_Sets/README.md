## Character Sets
- **What/Why?**
  - Computers only deal in numbers and not letters, so it’s important that all computers agree on which numbers represent which letters. Example:
    - Let’s say Comp-A uses (A=1,B=2,C=3) & Computer-B(A=0,B=1,C=2). If message `ABC` is sent from Comp-A to Comp-B, numbers 1,2,3 would travel thru wire. 
    - Comp-B receives and decodes as `BCD`. 
  - Hence, to communicate effectively, we would need to agree on a standard way of encoding the characters.

### Encoding Formats
- Way of representing and transmitting information

||[ASCII](ASCII)|[Unicode](Unicode)|[UTF-8](UTF-8)|
|---|---|---|---|
|Bits|7. Can represent (2<sup>7</sup>=0-127) characters.|21 bits. Can represent 2<sup>21</sup> characters.||
|Characters|0=48,1=49,A=65,B=66,..a=97||
