## Key Questions About Chunks
- Let's consider we have a file of 25 words, chunk size=5 words. Total 5 chunks.
```c
file  abcde ghijk lmnop qrstu wvwxy
chunk  1      2     3     4     5
```
### Question-1
- _a._ if user adds text in beggining/mid of file, or updates how chunker will find, so that whole file need not to be re-hashed and sent again.
  - _a1._ New chunk is added? //111
  - _a2._ old chunk updated?  //wvw333xy
- _b._ Also drop-box does saves every small edit, will client application recalculate whole file's hash, resend whole file again?
```c
 111 abcde ghijk lmnop 222 qrstu wvw333xy
```
### Answer-1
- *1. [How fopen keeps track of offset while reading file?](/Operating_Systems/Linux/Kernel/System_Calls/APIs)*
