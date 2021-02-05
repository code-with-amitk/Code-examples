## SED Command
- **File**
```c
# cat input
test@tes.com hello my namd@gmail.com is amit
fight@fgt.com and i will win
```
- **Command:** Search alphanumeric before `@`, after `@`, after `.`. this is Email replace with ' '. 
 - [s is Replace command](https://github.com/amitkumar50/Code-examples/blob/master/System_Administration/Commands/SED/README.md)
 - `[a-zA-Z0-9]` Match any alphanumeric
 - `+` Add after
 - `//` Replace email with space
 - `g` means replace all occurences
```
# sed -r 's/[a-zA-Z0-9]+@[a-zA-Z]+\.[a-zA-Z]*//g' email1.txt > output
```
- **Output**
```c
# cat output
 hello my is amit
 and i will win
``` 
