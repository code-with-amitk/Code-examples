- [Recommended Videos by Google Recruiters](#r)
- **[Interview Sep/2021](#i)**

<a name=r></a>
### Recommended Videos by Google Recruiters
#### 1. [Chris Jereza, How I Passed Coding Interviews at Facebook, Google, Lyft, Bloomberg](https://www.youtube.com/watch?v=lDTKnzrX6qU&feature=youtu.be)
  - Know Iteration,recursion,arrays,linked lists,queues,stacks,heap,set,hash-map,tree,binary-search,graphs,bfs,dfs,tries
  - **Sorting(Important)** Merge Sort, Quick Sort(Memorize Implementations)
  - sliding Windows
  - Greedy Algorithms
  - **Resource to learn from:** 1. CS 61 A    2. CS 61 B
  - **Practice portal** Leetcode(premium, as per company category)
  - **After Doing every question:** WRITE Down, 1 thing that would I have done/known to make this thing easier. CHANGE it and DONOT Repeat again.
    - Everytime, you Repeat Punish yourself. When done celebrate donot forget it.
  - DO LOT OF MOCK INTERVIEWS.  
  - **Method(ASK LOT OF QUESTIONS TO YOURSELF)**
    - *1.* Ask few set of questions to yourself. How can i implement this, what's Big-O notation, where is repetative work happening?
    - *2.* Explain solution in plain english to yourself. (Step-by-step bullets)
    - *3.* Pseudo code
    - *4.* Functions
    - *5.* implement
  - **Make your self Smart**
    - *1.* Be Creative (Ask your self lot of questions). Write down atleast 2 and try solve them.
    - *2.* Self Awareness: When going on wrong path and Correcting. MEDITATION
    - *3.* Intensity: Feel how you would feel after passing interview. Enjoy shout at mirror and do it.
 
<a name=i></a>
### Interview sep/2021
Round-1
```c
1. Toughest problem you solved?
  Ans- ospfv2 memory leak
  
2. Code: No of on bits in 64 bit number?  [Languages/Programming_Languages/C/Bitwise/Count_on_Bits/]
Ans: 
  Approach-1: 64 iterations. Asked to optimize
  Approach-2: Hamming weight. Asked to optmize more
  Approach-3: Lookup table, cannot tell.
```
**Round-2**
[Rope/cord Binary Tree](/DS_Questions/Data_Structures/Trees/BinaryTree/Rope_Cord)
```c
Find Character in ROPE/CORD (Binary Tree)
binary tree nodes represent length
leaf nodes contains element and length.
All other nodes contains (length of right child + length of left child)
Problem:
	1. Find character at nth index.		findNthChar(root, int n).	findNthChar(root, 6) => c
	2. return substring from n to m  
	3. Delete substring from n to m

testabcdefam
01234567891011
                      14
                    /     \
	      	 1        13
                /       /     \		 
             t,1       5        6
                     /  \     /   \ 
	            2    3   cde,3 fam,3
                   / \    \
                 e,1 s,1  tab,3	
```
