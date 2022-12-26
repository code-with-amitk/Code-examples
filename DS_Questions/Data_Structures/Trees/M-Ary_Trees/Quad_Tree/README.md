**Quad Tree / Q Tree**
- [Usage](#u)

## Quad Tree
- Each node has **EXACTLY 4 children**, except leaf node.
- It is used to partition a `two-dimensional space` by recursively subdividing it into four quadrants or regions.
- Quadtree can be constructured from a 2D area using the following steps:
  - Divide the current two dimensional space into four boxes.
  - If a box contains one or more points in it, create a child object, storing in it the 2D space of the box
  - If a box does not contain any points, do not create a child for it
  - Recurse for each of the children.
### Usage
- _1._ In image compression, where each node contains the average colour of each of its children. The deeper you traverse in the tree, the more the detail of the image.
-  Quadtrees are also used in searching for nodes in a two-dimensional area. For instance, if you wanted to find the closest point to given coordinates, you can do it using quadtrees.
