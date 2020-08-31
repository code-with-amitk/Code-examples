## Print Value & Text of enum class

```c++
string aPlace[3] = {"agra","pune","delhi"};

int main() {
  enum class place { agra, pune, delhi };

  place p = place::pune;

  cout<<(int)p;                     //1     enum variable need to be typecasted before printing
  cout<<aPlace[(int)p];             //pune
}
```
