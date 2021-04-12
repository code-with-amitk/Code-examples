## Rehashing
- Let's consider `unordered_map<int,string>` storing unique keys.
- At start of program sizeof hash table=3
```c
  Key | Value
  ----------
  01  | amit
  02  | never
  03  | give
```
- Now, (4, up) need to be stored, but hash table has no space so size of hash table is increased to 6.
- (old Hash function = %3) we can only goto index number=2. But we want to reach 5. Hence Hash function is changed (old Hash function = %6). So hash is again calculated for existing values.
