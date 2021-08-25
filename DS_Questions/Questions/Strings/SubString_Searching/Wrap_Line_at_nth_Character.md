- Problem
- [Logic](#log)
- [Complexity](#comp)
- [Code](#cpp)


## Wrap Line at nth Character
- Wrap line at nth character, use greedy approach, if new line breaks word keep word on separate line.
- Examples
```c
input="Hello World Test Amit", n=13
Output="
Hello World
Test Amit
 H e l l o  W o r l  d  T  e  s  t  A  m  i  t
 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18
```

<a name=log></a>
### Logic
- _1._ iterate every alphabet in input from i=0 to last
- _2._ Create word from every character in input.
```c
  if `word[i]` != ' '     //if word is not space
    push character to word
  if `word[i]` == ' '     //if word is space
    push word to line
    clear word
```
- _3._ Step 2 is performed if (j<n)
```c
  if j==n
    j = 1
    clear line
```

<a name=comp></a>
### Complexity
- **Time:** O(n)
- **Space:** O(m). m:size of largest word

<a name=cpp></a>
### Code
```cpp
void wrap (string& a, int n) {        //n:wrap line at nth letter
  int i = 0, j = 1;
  string word, line;

  if (a.size() <= n) {
    cout << a;
    return;
  }

  while (a[i] != '\0'){
    if (j < n) {
      if (a[i] != ' ')
        word += a[i];
      else {
        line += word;
        line += a[i];
        word.clear();
      }
    }
    else {    //j==k
      j=1;
      cout << line << "\n";
      word += a[i];
      line.clear();
    }
    ++i; ++j;
  }
  if (!word.empty()) {
    line += word;
  }
  cout << line << "\n";
}

int main() {
  string a = "Hello world Test Amit";
  wrap(a, 13);
}

$ ./a.out
Hello World
Test Amit
```
