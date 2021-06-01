## DH (Diffe Helman)
- DH Keys can be of following sizes:

|Group|No of Bits|Combinations|Strong|
|---|---|---|---|
|1|768|2<sup>768</sup>||
|2|1024|||
|5|1536||Strongest|

- **Algorithm**
```html
    Host-A                                        Host B 
        ----------Prime=p=13, Integer=q=6------->      //p is prime of min 600 digits
    Random-no=r=3                              Random-no=r=10
    
  Public-Key=qPow(r)modp 
  6pow(3)mod(13) = 8                           6pow(10)mod13 = 4
        -----------Public Key = 8----------------->
        <---------Public Key = 4------------------
        
  Private-Key = (Public Key)pow(Random No) mod(p)             
  4 pow(3)mod(13) = 12                        8pow(10)mod(13) = 12 
```            
