### Problem
- Given 3 HTML files.
- Read the files, parse email, URL from files and change them.
```c++
Email change example:
  support@test.com  --change to-->  support@fb.com
  
URL change example:  
  test.com  --changed to-->  test.fb.com
  test.org  --changed to-->  test.fb.org
```

### Logic
- *1.* Pass html file as command line argument.
- *2.* open input file. Read every line
  - Tokenize using space character and read the word.
  - if `@` is found in word, this is Email modify it as per above rule.
  - if `.com or .org` is found in word, this is URL modify it as per above rule.
- *3.* Keep writing the content to a seperate file.
- *4.* Rename the file after complete input file is read.

### Code
```c++

```
