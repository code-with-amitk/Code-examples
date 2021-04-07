## Accounts Merge
- Given a list of accounts where first element is a name, and the rest of the elements are emails representing emails of the account.
- Task is to Merge these accounts. 2 accounts belong to the same person if there is some common email to both accounts. 
- Note that even if two accounts have the same name, they may belong to different people as people.
- After merging the accounts, return the accounts in the following format: 
  - First element of each account is the name, rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.
- **Examples:**
```c
Input: 
accounts = {  
  {"John","john1@m.com","john2@m.com"},
  {"John","john2@m.com","john0@m.com"},
  {"Mary","mary@m.com"},
  {"John","john3@m.com"}
};
Output: {
  {"John","john0@m.com","john1@m.com","john2@m.com"},
  {"Mary","mary@m.com"},
  {"John","john3@m.com"}
};  

Explanation:
 - First and third John's are the same person as they have the common email "john2@m.com".
 - Second John and Mary are different people as none of their email addresses are used by other accounts.
```

### Approach-1  //Graph
#### Logic
- *1.* We can assume emails as nodes of graph and hence emails of same person are connected. Nodes which are not connected form a disjoint graph and will be present in our graph data structure.
```c
  john1@m.com ----  john2@m.com --- john0@m.com

  mary@m.com        john3@m.com
  
How this graph represented?
unordered_map
| key = email | value = set<string> |
| john1@m.com | john2@m.com
| john2@m.com | john0@m.com, john1@m.com
| john0@m.com | john2@m.com
```
- *2.* We need to remember the name to which email address belong.
```c
unordered_map
| key = email | value = NameOfPerson
| john0@m.com | john
| john1@m.com | john
| john2@m.com | john
| mary@m.com  | mary
| john3@m.com | john
```
- *3.* We keep track of visited nodes in graph. Intially all nodes are unvisited, but as we traverse the graph and try finding connected nodes, we mark entry as visited.
```c
Initially:
unordered_map visited
| key = string | value = bool
| john0@m.com | false
| john1@m.com | false
| john2@m.com | false
| john3@m.com | false
| mary@m.com | false
```

#### Complexity?
- **Time?**
- **Space**

#### Code
