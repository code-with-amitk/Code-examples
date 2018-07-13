What is Tree Data Structure?
	Data Structure that simulates hierarchical tree structure, with root & subtrees of parent node represented as set of linked nodes

General Tree Representation?
	struct node{
		int value;
		struct node *leftChild;
		struct node *ImmediateRightSibling;
	};

Terms:
	- Each node has Arbitrary number of children
	- External Nodes/Leaves: nodes which donot have any children. 
	- Internal Nodes: Nodes which are not leaves. they have atleast 1 child
	- Siblings: nodes with same parent.
	- Depth of Node: Number of edges from Root to Node. 
	- Depth/Diameter of Tree: Number of nodes on longest path between 2 nodes of Tree.
	- Height of node: Number of Edges from Node to deepest Leaf. 

Tree Types:
	- Binary Tree: 2 children (left & right) 
	- Binary Search Tree: Mainly used for Searching. Properties: (Left child <= parent), (right child >= parent)
	- Full/Proper/2 Tree: Every node except leaves has 2 children.
	- Height Balanced/AVL Tree: Depth or Left & right differs by 1 or less
	- Sum Tree: Each node is sum of all nodes in its tree
	- M-Tree: Max m children of any node
	- Perfect Tree: Every parent has 2 children. All leaves at same level.
	- Complete Tree: Every  level except deepest is completely filled.
