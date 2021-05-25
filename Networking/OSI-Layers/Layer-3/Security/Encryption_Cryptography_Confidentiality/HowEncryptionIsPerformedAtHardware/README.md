### How Encryption is performed at H/W Level?
> ONLY POSITION OF BITS ARE CHANGED
- **A. PERMUTATION/P-BOX/TRANSPOSITION BOX:** Perform internal transposition(change place) and do it at practically the speed of light since no computation is involved, just signal propagation. Internal wiring is not known to world.
- **B. SUBSTITUTION/S-BOX:** This can have multiple stages of P-box inside providing more complex method bit position shifting. 
  - Product Cipher
    - Actual Cipher can use multiple P,S box stages inside to provide better cryptography. With large number of stages output can be a complicated function of the input. 
    - Actual implementations have minimum of 10 stages.
    - There are more P-boxes at start and end, called Rounds.

<img src="https://i.ibb.co/nLZb6Cq/Encryption-at-hardware-level.png" width=1000 />
