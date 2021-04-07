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

### Approach-1  //Graph + DFS
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
unordered_map EmailToName
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
> ai is the length of `accounts[i]`
- **Time?** O(∑ai log(ai))
- **Space?** O(∑ai)

#### Code
```c++
class Solution{
    private:
    unordered_map<string, set<string>> graph;
    unordered_map<string, string> emailToName;
    unordered_map<string, bool> visited;

public:

    //if email is not visisted?
    //  mark as visited
    //  insert in set<string>, set is implemented as Balanced Binary Tree so emails are sorted
    //  Call dfs for other emails in graph
    void dfs(string email, set<string>& emailSet){
        if(visited[email] == true)
            return;
        visited[email] = true;
        emailSet.insert(email);
        for(string adj : graph[email]){
            dfs(adj, emailSet);
        }
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    
      //Create graph, visited array
      //EmailToName remembers names associated with particular email.
      
        for(vector<string> &account : accounts){
            string name = account[0];
            string firstemail = account[1];
            visited[firstemail] = false;
            emailToName[firstemail] = name;
            for(int i=2;i<(account.size());i++){
                visited[account[i]] = false;
                emailToName[account[i]] = name;

                    //key               value
                graph[account[i]].insert(firstemail);
                graph[firstemail].insert(account[i]);
            }
        }

        //All three datastructures(graph, visited array and EmailToName) are populated.
        
        vector<vector<string>> ans;
        
        for(int i=0;i<accounts.size();i++){
            
            for(int j=1;j<(accounts[i].size());j++){
            
                if(visited[accounts[i][j]] == false){
                
                    set<string> emailSet;
                    dfs(accounts[i][j], emailSet);
                    
                    vector<string> tmp(emailSet.begin(), emailSet.end());
                    
                    //Insert name at beggining of email vector<string>
                    tmp.insert(tmp.begin(), emailToName[accounts[i][j]]);
                    
                    //ans.emplace_back(tmp);
                    ans.push_back(tmp);
                }
            }
        }
        return ans;
    }
};    
    
int main(){
  Solution s;
  vector<VectorString> v = {
    {"John","johnsmith@mail.com","john_newyork@mail.com"},
    {"John","johnsmith@mail.com","john00@mail.com"},
    {"Mary","mary@mail.com","mary@mail.com"},
    {"John","johnnybravo@mail.com"}
  };
  vector<VectorString> out = s.accountsMerge(v);
  for (auto i:out) {
    for (auto j:i)
      cout<<j<<" ";
    cout<<"\n";
  }
}
```
