## [Browser history](https://leetcode.com/problems/design-browser-history/)

You have a browser of one tab where you start on the homepage and you can visit another url, 
get back in the history number of steps or move forward in the history number of steps.

### Implement the BrowserHistory class:
  - `BrowserHistory(string homepage)` Initializes the object with the homepage of the browser.
  - `void visit(string url)` visits url from the current page. It clears up all the forward history.
  - `string back(int steps)` Move steps back in history. If you can only return x steps in the history and steps > x, 
      you will return only x steps. Return the current url after moving back in history at most steps.
  - `string forward(int steps)` Move steps forward in history. If you can only forward x steps in the history and 
      steps > x, you will forward only x steps. Return the current url after forwarding in history at most steps.
      
## Logic (C++)
  1. Use Doubly linked list.
  2. Take iterator to store current position.
  3. `visit(url)`
    - if there are elements in dll after iterator. Remove them all and insert url
  4. `back(steps)`
    - decrement iterator by number of steps and return page
    - if iterator reaches start, return 1st page
  5. `forward(steps)`
    - Same as back
```c++
class BrowserHistory {
    list<string> dll;
    list<string>::iterator it;
public:
    BrowserHistory(string homepage) {
        it = dll.insert(dll.end(), homepage);
    }
  void visit(string url){
    if(!dll.empty()){ //List not empty

      if(dll.end() == it)   //Incoming url is already present at end
        return;

      if(it != dll.end()){  //Delete all elements till end
        ++it;
        dll.erase(it, dll.end());
      }
    }
    it = dll.insert(dll.end(), url);  //Insert at end
  }
  string back(int steps) {
    while(steps--){
            if(*it == dll.front())
                    return dll.front();
            it--;
    }
    return *it;
  }
  string forward(int steps) {
        while(steps--) {
            if(*it == dll.back())
              return dll.back();
            it++;
        }
        return *it;
  }
};
int main(){
  BrowserHistory *b = new BrowserHistory("leetcode.com");
  b->visit("google.com");
  b->visit("facebook.com");
  b->visit("youtube.com");
  cout<<"inserted\n";
  b->back(1);
}

```
