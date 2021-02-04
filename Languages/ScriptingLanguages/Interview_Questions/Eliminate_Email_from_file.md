## SED Command
```txt
# cat email.com
test@tes.com hello my namd@gmail.com is amit
fight@fgt.com and i will win

# sed -r 's/[a-zA-Z0-9]+@[a-zA-Z]+\.[a-zA-Z]*//g' email1.txt > output

# cat output
 hello my is amit
 and i will win
``` 
