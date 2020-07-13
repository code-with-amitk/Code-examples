## Size Of String

### str.length() & str.size()

| | str.length() | str.size() |
| --- | --- | --- |
| What | Returns no of characters in string | same |
| Why | inbuilt for string class | To make consistent with other STL container |
| Complexity | O(1) | O(1) |
> Both are same anyone can be used.

```c++
  string st = "LoveWork";
  cout<<st.size()<<endl;
  cout<<st.length()<<endl;
  /*O/P:
  8
  8 */
```
