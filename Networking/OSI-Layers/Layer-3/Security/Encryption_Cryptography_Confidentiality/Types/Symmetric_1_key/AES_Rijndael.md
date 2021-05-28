## AES / Rijndael
- There are 10 rounds for 128-bit keys, 12 rounds for 192-bit keys and 14 rounds for 256-bit keys.

```c

#define LENGTH 16                     //Input,Output in bytes. 16x8=128
#define NROWS 4                         //For internal use
#define NCOLS 4                          //For algo's internal use
#define ROUNDS 10                     //number of iterations/stages
typedef unsigned char byte;           /// unsigned 8-bit integer

AES(byte plaintext[LENGTH], byte ciphertext[LENGTH], byte key[LENGTH]) {
  int r;
  byte state[4][4];                                     // current state
  struct {byte k[4][4];} rk[10 + 1];          // round keys
  expand key(key, rk);                             // construct the round keys
  copy plaintext to state(state, plaintext); // init current state
  xor roundkey into state(state, rk[0]);     // XOR key into state
  for (r = 1; r <= ROUNDS; r++) {
  substitute(state);                             // apply S-box to each byte
  rotate rows(state);                          // rotate row i by i bytes
  if (r < ROUNDS) mix columns(state); // mix function
    xor roundkey into state(state, rk[r]); / XOR key into state
  }
  copy state to ciphertext(ciphertext, state); / return result
}
```
