### MD5
- *Step-1:* 
  - Take four 32-bit words, initialized to fixed constants. C1(01 23 45 67), C2:(89 ab cd ef), C3(fe dc ba 98), C4(76 54 32 10)
- *Step-2:* Take 4 Functions
```c
    f(x,y,z) = (x & y) | ((~x) & z)
    g(x,y,z) = (x & z)| (y & (~z))
    h(x,y,z) = x ^ y ^ z
    i(x,y,z) = y ^ (x | (~z))
```    
- *Step-3:* Break input into 32-bit words
```c
                Input(512 bits)  ->  |Break into 16 pieces| ->     m1 .. m16
if input is not 512 bit pad it
```
- *Step-4:* Perform 4 or 16 round Operations.
```
//AM: Addition Modulo
  Round-1:    F(K2,K3,K4) ->  AM ->  AM -> |Rotate left bit by s places| ->  AM -> K2        
        	                	  /\     /\				                               /\
                 			        C1     m1 				                              C2
  Round-2: For m2 and so on..
```    
- Message Digest=Hash = abcd
