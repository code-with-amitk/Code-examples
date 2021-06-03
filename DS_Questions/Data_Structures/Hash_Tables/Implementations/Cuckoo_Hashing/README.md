##  Cuckoo Hashing
- This is a [2-way hashing](..) ie uses 2 hash tables, 2 seperate hash functions(Hash1, Hash2) for 2 hash tables.
- **Insertion of key**
  - Always goes to Table1.
  - if place is already occupied, other key is moved to Table2.
  - Keys are moved back and forth until a key moves to an empty location or a limit is reached.
- **if limit reached?** If the limit is reached, new hash functions are chosen, and the tables are rehashed.
- **Name comes from cuckoo** who pushes her eggs out of the nest to other's nest.
