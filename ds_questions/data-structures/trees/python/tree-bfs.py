"""
        1
       / \
      2   3
     /    /
    5    4

BFS: 1 2 3 5 4

Testing with docstring
>>> a = Node(1)
>>> a.left = Node(5)
>>> a.right = Node(8)
>>> a.bfs()
1
5
8
"""
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

    def bfs(self):
        if (self is None):
            return None
        queue = []                  #List
        queue.append(self)          #append() inserts element at back of list
        while (queue != []):
            try:                        #Catching Exception if trying to pop empty list
                test = queue.pop(0)     #pop(i) pops from index[i] of list.
            except:
                print("IndexError Exception")
            print (test.val)
            if (test.left is not None):
                queue.append(test.left)
            if (test.right is not None):
                queue.append(test.right)


obj = Node(1)
obj.left = Node(2)
obj.left.left = Node(5)
obj.right = Node(3)
obj.right.left = Node(4)
print('Tree created')
obj.bfs()

"""
# python3.6 -m doctest bfs.py
Tree created
1
2
3
5
4
"""
