**Merkle / Merkal / Merkel Tree**
- [Usage/Advantages](#us)
  - [1. Retrieving lost/corrupted data in log(n) steps](#dv)
- **[Self youtube Video](https://youtu.be/J5tphidJ9Uk)**

## Merkle Tree
- Binary tree storing hash of data(big files(audio,video,txt) etc) as leaf node.
- All other nodes stores hash of their child nodes.
- **Examples:** git, bitcoin uses Merkle tree.
```html
Data: let's meet  at	8 	in 	tombstone 	back 	park

                        h15
                    /         \
                h13               h14
              /     \           /       \
            h9        h10     h11         h12
           /  \       / \    /   \        /  \
hash     h1    h2   h3  h4  h5    h6    h7     h8
data -> let's meet  at	8 	in 	  tom  	back 	park 

hash(let's) -> h1     hash(h1+h2) -> h9     hash(h9+h10) => h13
hash(meet)  -> h2     hash(h3+h4) -> h10    hash(h11+h12) => h14
hash(at)    -> h3     hash(h5+h6) -> h11    hash(h13+h14) => h15
hash(8)     -> h4     hash(h7+h8) -> h12
hash(in)    -> h5
hash(tom)   -> h6
hash(back)  -> h7
hash(park)  -> h8
```

<a name=us></a>
## Usage of Merkle Tree
### 1. Retrieving lost/corrupted data in log(n) steps
Suppose alice want to send Bob data="let's meet  at	8 	in 	  tom  	back 	park", But john(intruder) changes the data.
```html
          Alice                                           
|data="let's meet at 8 in tom back park"|
  {encrypted|Hashed_metadata|...h15...|}
  
             -----------------------------> John(Intruder)
                                 changes 7, But cannot change encrypted h15
                                |data="let's meet at 7 in tom back park"|
                                  {encrypted|Hashed_metadata|...h15...|}
                                                  ---------------------------------> Bob
                                                                                "let's meet at 7 in tom back park" -> hash -> h45
                                                                                Recieved hash = h15. HASH Mismatch
                                                                                
                                                                                h45                     <<< Level-0
                                                                            /         \
                                                                      h43               h14             <<< Level-1
                                                                   /     \           /       \
                                                                 h9        h40     h11         h12      <<< Level-2
                                                                /  \       / \    /   \        /  \
                                                      hash     h1    h2   h3  h41  h5    h6    h7     h8 <<< Level-3
                                                     data -> let's meet   at	7 	in 	  tom  	back 	park 
                                                                                
                                                                              Let me get corrupted packet
           <-------------------------Send level-1 hashes---------------------------
           ------------------------h13, h14-------------------------------------->
                                                                              h43 != h13, h14 == h14
           <-----------------------Send 1st 2 level-2 hashes----------------------
           ------------------------h9, h10--------------------------------------->
                                                                              h40 != h10
           <-----------------------Send 3rd,4th level-3 hashes--------------------
           ------------------------h3, h4--------------------------------------->
                                                                              h4 != h41
           <-----------------------Send word corresponding to h4----------
           ----------------------- 8 --------------------------------------->
                                                                          Correct data =
                                                                              "let's meet at 8 in tom back park"
```
- **Advantage: Saves bandwidth**
  - if we have huge file, then complete file need not to be sent, malformed chunk can be identified and sent.
