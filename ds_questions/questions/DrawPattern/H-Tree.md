## [H-Tree Construction](https://www.pramp.com/challenge/EmYgnOgVd4IElnjAnQqn)
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
- *1.* Start from center point (x,y)=(5,4) and length=2 Calculate Left, right points of given point.
```c++
               5|
               4|            4,4  5,4  6,4
               3|         
               2|
               1|
    ------------0---1---2---3---4---5---6----
               1|
               2| 
               3|
               4|
               5|               
 (x,y) = (5,4), length=2
 x0,y0 = (4,4)  x0 = x - length/2, y0 = y - length/2
 x1,y1 = (6,4)  x1 = x - length/2, y1 = y - length/2
```
- *2.* Calculate 4 points from (x,y) (x0,y0) (x1,y1) & pass to DrawLine() function to draw 3 lines.
```c++
                                                point1      point2
                                                  3,5        5,5
               5|            (4,5)     (6,5)     |         |
               4|             4,4  5,4  6,4        3,4|---------|5,4
               3|            (4,3)     (6,3)           |         |
               2|                                  3,3       5,3
               1|                               point3      point4
    ------------0---1---2---3---4---5----6-----
               1|
               2| 
               3|
               4|
               5|               
               
 (x,y)=(4,4), (x0,y0)=(3,4), (x1,y1)=(5,4)
 Point1 = (x0,x1) = (3,5)
 Point2 = (x0,x0) = (x0=3,x0
 
 drawLine(
```
- *3.* P
