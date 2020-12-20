## [H-Tree Construction]()
- **What is HTree?** An H-tree is a geometric shape that consists of a repeating pattern resembles the letter “H”. 
- **Task?** Write function which constructs HTree.
```c++  
  drawHTree(int x, int y, int depth, int length)
  x,y: center coordinates from where HTree contruction should begin
  depth: 
  
  drawLine(int x0, int y0, int x1, int y1)   //Function to draw line between (x0,y0) and (x1,y1)
```
- It can be constructed by starting with a line segment of arbitrary length, drawing two segments of the same length at right angles to the first through its endpoints, and continuing in the same vein, reducing (dividing) the length of the line segments drawn at each stage by √2.
- Examples
```c++

depth=1   |-|   //1 HTree. Line segment of length=l

depth=2         //5 HTrees. Length of line segment would be reduced by \/2.
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

## Logic
- *1.* Start from center point (x,y) Calculate coordinates of 4 tips of H.
```c++
 (x,y) = (4,4)
 x0 = 
```
