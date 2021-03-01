## Closest Binary Search Tree Value
- Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.
- Given target value is a floating point. You are guaranteed to have only one unique value in the BST that is closest to the target.
- Example
```html
Input: root = [4,2,5,1,3], target = 3.714286

    4
   / \
  2   5
 / \
1   3

Output: 4
```

### Approach-1  //Recursive Inorder
- **Logic**
  - *1.* Traverse BST inorder and store in vector.
  - *2.* Find nearest value to target from stored vector using linear search
- **Complexity**
  - Time: O(n)
    - O(n): Storing value in vector after inorder traversal
    - O(n): Finding nearest value from target.
  - Space: O(n)
- **Code**
```c++
void inorder(TreeNode* root, vector<double>& v) {
	if (root->left)
		inorder(root->left, v);
	v.push_back(root->val);
	if (root->right)
		inorder(root->right, v);
}

int closestValue(TreeNode* root, double target) {
	vector<double> v;
	inorder(root, v);

	double mini=0, val= INT_MAX;
	//Find neareset in vector. Linear Search
	for (auto i : v) {
		if (abs(i - target) <= val) {
			mini = i;
			val = abs(i - target);
		}
	}
	return mini;
}
```
