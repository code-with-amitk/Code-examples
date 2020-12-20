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
 x0,y0 = (3,4)  x0 = x - length/2, y0 = y - length/2
 x1,y1 = (6,4)  x1 = x - length/2, y1 = y - length/2
```
- *2.* Calculate 4 points from (x,y) (x0,y0) (x1,y1) & pass to DrawLine() function to draw 3 lines.
```c++
                                                    point1      point2
                                                     4,5        6,5
               5|            (4,5)     (6,5)          |         |
               4|             4,4  5,4  6,4        3,4|---------|6,4
               3|            (4,3)     (6,3)          |         |
               2|                                    4,3       6,3
               1|                                  point3      point4
    ------------0---1---2---3---4---5----6-----
               1|
               2| 
               3|
               4|
               5|               
               
 (x,y)=(5,4), (x0,y0)=(4,4), (x1,y1)=(6,4)
 Point1 = (x0,x) = (4,5)
 Point2 = (x1,x) = (6,5)
 Point3 = (y,x) = (4,3)
 Point2 = (x1,x) = (6,3)
 
               <--src------>   <---dst------>
 void drawLine(int x1, int y1, int x2, int y2)
 
 drawline(point1, point3)   =   drawline(x0, x, x1, x)
 drawline(point2, point4)   =   drawline(x1, x, x1, x)
 drawline(x0, y0, x1, y1)
```
- *3.* Call drawTree recursively to draw the trees at each depth.
## Code
```c++
void drawLine(int x0, int y0, int x1, int y1){
  std::cout<<x0<<" "<<y0<<" "<<x1<<" "<<y1<<std::endl;
}
void drawHTree(int x, int y, int length, int depth){
  
  if(!depth)
    return;
  
  int x0 = x - length/2;
  int x1 = x + length/2;
  int y0 = y - length/2;
  int y1 = y + length/2;
  
  //Draw 3 lines of H Tree using recursion
  drawLine (x0, y0, x0, y1);  //left line
  drawLine (x1, y0, x1, y); //right line
  drawLine (x0, y, x1, y);  //middle line
  
  //reducing (dividing) the length of the line segments drawn at each stage by √2.
  int newLength = length / sqrt(2);
  
  drawHTree (x0, y0, newLength, depth-1); //low left HTree
  drawHTree (x0, y1, newLength, depth-1); //upper left HTree  
  drawHTree (x1, y0, newLength, depth-1); //low right HTree
  drawHTree (x1, y1, newLength, depth-1); //upper right HTree  
}
```
## Complexity
- **Time** O(4<sup>Depth</sup>). 
- **Space** O(depth). Function stacks created = Recursive function calls.
