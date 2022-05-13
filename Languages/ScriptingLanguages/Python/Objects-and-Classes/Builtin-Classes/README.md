- [Counter](#c)

<a name=c></a>
## Counter
This is a sub-class which is used to count hashable objects. It implicitly creates a hash table of an iterable when invoked.

#### 1. Counting most common words
```py
words = [
   'red', 'green', 'black', 'pink', 'black', 'white', 'black', 'eyes',
   'white', 'black', 'orange', 'pink', 'pink', 'red', 'red', 'white', 'orange',
   'white', "black", 'pink', 'green', 'green', 'pink', 'green', 'pink',
   'white', 'orange', "orange", 'red'
]
from collections import Counter
word_counts = Counter(words)        #({'pink': 6, 'black': 5, 'white': 5, 'red': 4, 'green': 4, 'orange': 4, 'eyes': 1})
top_four = word_counts.most_common(4)
print(top_four)                   #[('pink', 6), ('black', 5), ('white', 5), ('red', 4)]
```
