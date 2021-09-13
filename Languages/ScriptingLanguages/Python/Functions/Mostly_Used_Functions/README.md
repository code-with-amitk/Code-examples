- [format()](#f)
- [input(str)](#i)
- [ord()](#o)
- [range()](#r)
- **split() & rsplit()**
  - [split()](#s)
  - [rsplit()](#rs)
- [strip(`[char]`)](#st)
- [type()](#t)

<a name=f></a>
### format()
Helps in positional and value formatting of string. string.format()
```py
print ('The {} who says {}'.format('person','Hello')) #The person who says Hello.
print ('The {0} who says {1}'.format('person', 'Hello'))   #The person who says Hello
print ('The {1} who says {0}.'.format("person",'Hello')) #The Hello who says Person
```

<a name=i></a>
### input(str)
This allows user to input until new line is pressed. input() returns string
- *raw_input()* This was older function replaced by input()
```py
r = float(input('Enter radius'))
print('Area=' + 3.14*r**2)                                     //** is Exponetial. ie x^y
```

<a name=o></a>
### ord(char)
converts character to its Unicode code value.

<a name=r></a>
### range()
Produces continuous sequence
```py
print(list(range(5,8)))         #5,6,7
print(list(range(5,10,2)))      #5,7,9      #3rd argument tells interval of sequence
```

### Split() & rsplit
- **split:** splits into tokens from start to end
- **rsplit()** splits into tokens from end to start
```py
list[] = str.split(seperator = None, maxsplit = -1)
list[] = str.rsplit(seperator = None, maxsplit = -1)

- seperator: if separator is not provide WHITESPACE is taken as separator
- maxsplit:
    - If maxsplit is provided, at most maxsplit splits are done
    - If maxsplit is not provided or -1, there is no limit on the number of splits 
Return: A list of strings.
```
<a name=s></a>
#### split example
```
word = 'Amit, will, achieve'
li = word.split(', ')
print(li)                    #['Amit', 'will', 'achieve']   //1

l2 = word.split(', ',1)      #['Amit', 'will, achieve']     //2
print(l2)
```
<a name=rs></a>
#### rsplit example
```
word = 'Amit, will, achieve'
li = word.rsplit(', ')
print(li)                    #['Amit', 'will', 'achieve']   //Same as 1

l2 = word.rsplit(', ',1)      #['Amit, will', 'achieve']    //Different from 2
print(l2)
```

<a name=st></a>
### 1.2 string.strip(`[char]`)
Removes characters from both left and right based on the argument (a string specifying the set of characters to be removed)
```py
def test(gpLink):
    ret = []
    if gpLink.strip() == "":
        print("gpLink is empty")
        return 4;
    return;
print("value=",test(" "))        #gpLink is empty=4
```

<a name=t></a>
### type()
Returns type of Object being passed  
```py
print(type(3))                                #<class 'int'>
print(type(['foo', 'bar', 'baz']))       #<class 'list'>
#print(type(1, 2, 3))                #<class 'tuple'>
class X:
    pass
print(type(X))
```  


