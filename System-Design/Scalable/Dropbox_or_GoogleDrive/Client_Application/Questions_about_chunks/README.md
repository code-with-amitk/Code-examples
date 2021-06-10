## Questions?
- Let's consider we have a file of 9 words, chunk size=3 words. Total 3 chunks.
```c
file  abc def hij
chunk  1   2   3
hash  h1  h2  h3 
```
### Question-1
- _a._ if user adds text in mid(Usually add happens at mid or end, not much at beggining) of file, how chunker will find, so that whole file need not to be re-hashed and sent again.
```c
file  abc xdef hij
       1    2   3
```
- _b._ Also drop-box does saves every small edit, will client application recalculate whole file's hash, resend whole file again?
### Answer-1
> *[How fopen keeps track of offset while reading file?](/Operating_Systems/Linux/Kernel/System_Calls/APIs)*
- _1._ Chunker will calculate newly added characters.
- _2._ Chunker will start calculating hash from start_of_file based on chunk size
  - _2a._ When new hash matches old, move on
  - _2b._ For mismatch, take substrings and find hash and try match h2 (ie expected hash at that position).
    - _2b1._ Send only newly added character to dropbox server.
    - _2b2._ Send position/offset of newly added character from beggining.
```c
    CLIENT APPLICATION
Earlier file size=11
New file size=15
Newly added Characters = 4                                    //1

//2
Read chunk_size, 3 letters. abc -> |Hash| -> h1               //2a
Read chunk_size, `xde` letters. Mimatch. Should be h2
  xde -> |Hash| -> not h2
  def -> |Hash| -> h2
  Change is at substring[0]=x                                                   DROPBOX SERVER
  send x -----------------------------------------------------------------------> 
  position/offset of x=4  -----------offset=4----------------------------------->
  
//3  
Sliently recalculate the hash and store                                Server also calculates hashes and store
file  abc xde fhi j
chunk  1   2   3  4                                                         
hash  h1  h2  h3  h4 
```
