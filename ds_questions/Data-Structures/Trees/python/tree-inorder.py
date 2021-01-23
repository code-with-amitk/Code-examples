"""     inorder.py
    -----SS------------HS----------
    |    --------->|10|-|--|      |
    |    |     |       |  |       |
    |  obj     |       | |3|N|N|  |
    |          |       \/         |
    |          |      |2|N|N|     |
     -----------------------------

Testing:
    >>> a = tree(10)
    >>> a.inorder(a)
    10
    >>> b = tree(10)
    >>> b.left = tree(20)
    >>> b.inorder(b)
    20
    10
"""

class tree:
    def __init__(self,a):
        self.left = None    #None=NULL
        self.right = None
        self.val = a

    def inorder(self,t):
        if (t is None):
            return None
        self.inorder(t.left)
        print(t.val)
        self.inorder(t.right)

obj = tree(1)
obj.left = tree(2)
obj.right = tree(3)
print("Tree created")
obj.inorder(obj)

"""
# python3.6 -m doctest create-tree.py       #doctest validates the test cases in docstring
Output:
    Tree Created
    2
    1
    3
"""
