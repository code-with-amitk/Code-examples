## [Longest String Chain](https://leetcode.com/problems/longest-string-chain/)
- Given a list of words, each word consists of English lowercase letters.
- We say word1 is a predecessor of word2 if and only if we can add exactly one letter anywhere in word1 to make it equal to word2. For example, "abc" is a predecessor of "abac".
- A word chain is a sequence of words `[word_1, word_2, ..., word_k]` with k >= 1, where word_1 is a predecessor of word_2, word_2 is a predecessor of word_3, and so on.
- Return the longest possible length of a word chain with words chosen from the given list of words.
- **Examples**
 ```console
Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chain is "a","ba","bda","bdca".

Example 2:
Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
```

### Approach-1    //Graph DFS
- **Logic**
  - Create a graph where each node differs from its neighbour by 1 character.
  - From each node, find its neighbour by removing each character and checking whether word exists or not.
```c
Input = {"a","b","ba","bca","bda","bdca", "dca"}
       bdca ---- dca 
       /   \
     bda   bca        
        \  / 
         ba
        / \    
       b   a 
//Finding next connected node to bdca.
1. Remove b. dca. Yes exist. Perform DFS on it
2. Remove d. bca. Yes exist. Perform DFS on it
3. Remove c. bda. Yes exist. Perform DFS on it
4. Remove a. bdc. Does not exist move to next word

//Length of longest chain = 4
  bdca -> bda -> ba -> b      OR
  bdca -> bda -> ba -> a      OR
  bdca -> bca -> ba -> a      OR
  bdca -> bca -> ba -> b
```
- **Complexity**
  - **Time:** O(NL<sup>2</sup>) = O(N + NL<sup>2</sup>)
    - N=number of words, L=length of longest word
    - O(N): We create a `unordered_set<string>` of words for fast searching.
    - O(N): Iterate thru each word to find neighbour
    - O(L): Find next connected word for each word
- **Space:** O(N) ie creating unordered_set of words
