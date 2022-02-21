- BTreeSet
- [Insert, Search, Remove](#i)

## [BTreeSet](https://doc.rust-lang.org/std/collections/struct.BTreeSet.html)
- A set based on a Btree.
- ie a [BTree](/DS_Questions/Data_Structures/Trees/SelfBalancedBST/BTree) having unique elements.
- **Benefits of BTreeSet?**
  - Ordered/sorted elements
  - Unique elements
```r
//pub struct BTreeSet<T> { /* fields omitted */ }
```

<a name=i></a>
### Insert, Search, Remove
```rs
use std::collections::BTreeSet;

let mut books = BTreeSet::new();
books.insert("A Dance With Dragons");
books.insert("To Kill a Mockingbird");
books.insert("The Odyssey");
books.insert("The Great Gatsby");

if !books.contains("The Winds of Winter") {     //Search
    println!("We have {} books, but The Winds of Winter ain't one.",
             books.len());
}

books.remove("The Odyssey");

// Iterate over everything.
for book in &books {
    println!("{}", book);
}
```
