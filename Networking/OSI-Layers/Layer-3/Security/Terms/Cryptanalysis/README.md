## Crytanalysis
- **What?** Means breaking ciphers.

### Methods
- **1. Method-1. Comprehending**
  - *a.* Read bits in cipher-text, Guess the pattern if bits differ is small.

- **2. Method-2**
  - *a.* XOR predicted plain-text with cipher-text. It can break weak cipher in only 2<sup>43</sup> combinations.
  - *b.* When done repeatedly, helf bits becomes 0 and other 1s.

- **3. Method-3: Measuring electrical power**
  - Computers typically use around 3 volts to represent a 1 bit and 0 volts to represent a 0 bit.
  - Attcker replaces the main n-GHz clock with a slow (e.g., 100-Hz) clock and puts alligator clips on the CPU’s power and ground pins can precisely monitor the power consumed by each machine instruction.
    - **Beating this attack**  coding the algorithm in assembly language to make sure power consumption is independent of the key and also independent of all the individual round key.
  
- **4. Method-4: Timing Analysis**
  - Cryptographic algorithms are made of if statements that test bits then perform operation on the incoming block.
  - By slowing clock round keys which encrypt blocks can be predicted.
