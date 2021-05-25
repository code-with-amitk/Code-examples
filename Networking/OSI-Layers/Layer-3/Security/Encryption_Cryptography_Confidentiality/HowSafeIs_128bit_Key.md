### How safe is 128 bit Key?
- The longer the key, higher work to be done by breaking algo.    {Email: 64-bit keys will do, Commercial applications: 128 bits, Govt org: 256 bits}
```c
    bits    No of Unique keys
    2                4
    3                8
    32            4,294,967,296    (4 billion)
    64            18,446,744,073,709,551,616 (18 Quintillion keys) = 18 x 1018
    128           340,282,366,920,938,463,463,374,607,431,768,211,456   ( 340,282,366,920,938,463,463 Quintillion keys) 
```    
- 1 super computer can perform 10<sup>17</sup> FLOPS (a hundred quadrillion FLOPS floating point operations per second)
  - Per Year = 3600(hour) x 24 x 30 x 12 = 31,104,000 x  10<sup>17</sup>= 31,104,00 Quintillion Operations.
  - 340,282,366,920,938,463,463 / 31,104,000 = 109,401,481,134,561 (approx) = 109 Trillion 
  
**109 Trillion super computers working parallelly for 1 year can produce all combinations of 128 bit key**
