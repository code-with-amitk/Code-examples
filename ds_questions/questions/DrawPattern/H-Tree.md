## [H-Tree Construction]()
- An H-tree is a geometric shape that consists of a repeating pattern resembles the letter “H”. 
- It can be constructed by starting with a line segment of arbitrary length, drawing two segments of the same length at right angles to the first through its endpoints, and continuing in the same vein, reducing (dividing) the length of the line segments drawn at each stage by √2.
- Examples
```c++
depth=1   |-|   //1 HTree
depth=2         //5 HTrees
         |-| |-|
          |---|
         |-| |-|

depth=3         //21 HTrees
         |-|   |-|  |-|   |-|
          |-----|    |-----|
         |-| | |-|  |-| | |-|
             |----------|
         |-| | |-|  |-| | |-|
          |-----|    |-----|
         |-|   |-|  |-|   |-|
```
