## Rules to check RBT or Not?
- *a.* Each node has color either red or black.
- *b.* Root is always black.   
- *c.* There can be no 2 adjacent red nodes, 2 adjacent black nodes can exist. ie No Red-Red parent child relationship.
- *d.* Every path from a node to its leaf NULL child has the same number of black nodes.
- *e.* Add null children at leaf. null children are always black(But donot consider null while considering rule-d).
```html
    B(not RBT                  B(RBT)              B(not RBT, violates rule-c)
   /  violates rule-d)       /    \               /
   B                        R      B             R
  /                        / \    /               \
 B                        B  B  R                  R
```
