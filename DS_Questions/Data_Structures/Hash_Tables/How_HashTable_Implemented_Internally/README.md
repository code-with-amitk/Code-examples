## How Hash Table is implemented internally
- Files are organized into buckets(Size is power of 2) stored either in RAM or disk or distributed servers.
- Hash function generates the bucket number which stores the key.
- **Formula**
  - addr(l, k) <- h(k) mod 2<sup>l</sup>m
  - h:hash function, k is the key, and l is the level (or split round).
```html
  key  -> hash_function ->  Bucket-3

	server1			server2			server3
	bucket-1		bucket-2		bucket-3
	key1			  key5			key9
	key2			  key6			key10
	key3			  key7			key12
	key4			  key8			key13
```
