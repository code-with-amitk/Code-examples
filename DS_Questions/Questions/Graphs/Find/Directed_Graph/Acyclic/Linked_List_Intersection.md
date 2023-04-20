## Linked List Intersection Question.
- Find whether we visit, already visited node or not.
- Segment-1: strings of inputs seperated by ->, showing directed nodes of graph
- Segment-2: Nodes seperated by comma. Write true of false for every single line.
```c
Input:
    a->b
    b->c
    x->c
    y->x
    q->r
    r->s
    w->z
    a,q,w   //f
    y,z,a   //t
    a,w     //f

    a -> b -> c <- x <- y
    q -> r -> s
    w -> z

Output:
    false
    true
    false

    false for a,q,w?
        a:Start from "a" and traverse all nodes a -> b -> c
        q:Start from "q" and traverse all nodes q -> r -> s
        w:Start from "w" and traverse all nodes w -> z
        No intersection

    true for y,z,a?
        y:Start from "y" and traverse all nodes y -> x -> c
        z:
        a:Start from "a" and traverse all nodes a -> b -> c
        There is a intersection at a.
```

### Code
**CPP**
```cpp
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
using namespace std;

class LinkedListIntersection {
                  //src   connected nodes
    unordered_map<string, vector<string>> graph;
    unordered_set<string> us;
    queue<string> q;
public:
    // Tokenizes and returns tokens
    void Tokenize(string& str, string& delim, vector<string>& tokens) {
        string token;
        size_t pos = 0;
        bool bInput = false;

        while (pos = str.find(delim) != string::npos) {
            bInput = true;
            token = str.substr(0,pos);
            tokens.push_back(token);
            str.erase (0, pos + delim.size());
        }
        tokens.push_back(str);
    }

    bool ValidInput(string& str) {
        if (str.find("->") != string::npos || str.find(",") != string::npos)
            return true;
        return false;
    }

    bool InputLine(string& str) {
        if (str.find("->") != string::npos)
            return true;
        return false;
    }

    void TraverseGraph(vector<string>& nodes) {
        us.clear();
        q = {};

        for (auto&node: nodes) {

            q.push(node);

            while (!q.empty()) {
                string n = q.front();
                q.pop();

                auto it_unique = us.find(n);
                if (it_unique != us.end()) {
                    // Intersection found
                    cout << "true\n";
                    return;
                }
                us.insert(n);

                auto it = graph.find(n);
                if (it != graph.end()) {
                    for(auto&i:it->second)
                        q.push(i);
                }
            }
        }
        cout << "false\n";
    }

    void createGraph (string src, string dst) {
        auto it = graph.find(src);
        if (it != graph.end()) {
            it->second.push_back(dst);
        } else {
            vector<string> temp;
            temp.push_back(dst);
            graph[src] = temp;
        }
    }

    void printGraph() {
        cout << "\nGraph:\n";
        for (auto& i:graph) {
            for (auto&it: i.second)
                cout << i.first << "->" << it << "\n";
        }
        cout << "\n";
    }

    inline std::string trim(std::string& str) {
        str.erase(str.find_last_not_of(' ')+1);         //suffixing spaces
        str.erase(0, str.find_first_not_of(' '));       //prefixing spaces
        return str;
    }
};

int main() {
    LinkedListIntersection obj;
    string line;
    string delim;
    while (getline(cin, line)) {
        vector<string> tokens;

        // if it blank line continue
        if (obj.trim(line) == "" || !obj.ValidInput(line)) {
            cout << "Enter valid line\n";
            continue;
        }

        if (obj.InputLine(line)) {
            // Input Line "->". Tokenize and create graph
            delim = "->";
            obj.Tokenize(line, delim, tokens);
            obj.createGraph(tokens[0], tokens[1]);
            obj.printGraph();
        } else {
            // Output Line. Tokenize and Traverse graph
            delim = ",";
            obj.Tokenize(line, delim, tokens);
            obj.TraverseGraph(tokens);
        }

    }
}
```
