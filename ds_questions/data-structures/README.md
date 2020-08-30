## DS Types
- 
| |Contigious|Linked|
|---|---|---|
|Based on|Arrays|Pointers|
||contigously allocated memory area|distinct chunks of memory bound together by pointers|
|Examples|arrays,matrices,heaps & hash tables|lists, trees, and graph adjacency lists|
|Advantages|<ul><li>Constant time access from index</li></ul><ul><li>No space wasted for storing links</li></ul>|<ul><li>Insertion,deletion is simpler wrt arrays. Bcoz arrays will require shifting.</li></ul><ul><li>Moving pointers is easier wrt moving record itself.</li></ul>|

		3. Excellent memory/Cache locality:
		- Physical continuity b/w successive data
		elements helps exploit high-speed cache mem.
Disadvantage	1. Size cannot be adjusted in mid of program	1. Space requirement is high. Pointer to next node takes 
		execution.					significant space.
		Solution: Dynamic Arrays			2. Random access not allowed.
								3. Cache locality not good, since jumps are done using ptrs.
		
DYNAMIC ARRAYS?
	array-size
t=t0	1
t=t1	1 exhausted, Double the allocation, Allocated:2
	- Every time space is exhausted, its doubled.
	- Allocate new contiguous array of size 2m, copy contents of old array to the lower half of the new one, return
How many times reallocation should be done?
1->2->4->8->16	For n elements logn
No of times movement happens for elements? Each of the n elements move only two times on average,

DATA STRUCTURES
1. Dictionary:data type permits access to data items by content.
	a. Search(D,k) – Given a search key k, return a pointer to the element in dictionary D 
	whose key value is k, if one exists.
	b. Insert(D,x) – Given a data item x, add it to the set in the dictionary D.
	c. Delete(D,x) – Given a pointer to a given data item x in the dictionary D, remove it from D.
	d. max(D),min(D) - return max element or min
	
