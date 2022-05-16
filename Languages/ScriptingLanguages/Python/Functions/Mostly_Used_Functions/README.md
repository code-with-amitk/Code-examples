- [format()](#f)
- [input(str), raw_input()](#i)
- [join](#j)
- [ord()](#o)
- [range(), xrange()](#r)
- [split() & rsplit()](#sr)
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
### input(str), raw_input()
This allows user to input until new line is pressed. input() returns string
- Python 3.x, use input(str)
- Python 2.x, use raw_input().
```py
r = float(input('Enter radius'))
print('Area=' + 3.14*r**2)                                     //** is Exponetial. ie x^y
```

<a name=j></a>
### join()
joins all items from iterable into 1 string.
```py
myTuple = ("a", "b", "c")
x = "@".join(myTuple)
print(x)                      # a@b@c

myTuple = ("a", "b", "c")
x = "".join(myTuple)
print(x)                      # abc
```

<a name=o></a>
### ord(char)
converts character to its Unicode code value.

<a name=r></a>
### range(), xrange()
|Function|What|Return|
|---|---|---|
|range()|generate integer sequence|list|
|xrange()|generate integer sequence|xrange object|

**xrange():** it does not generate a static list, but creates the value on the go. This technique is used in object-type generator and has been termed as "yielding".
```py
print(list(range(5,8)))         #5,6,7
print(list(range(5,10,2)))      #5,7,9      #3rd argument tells interval of sequence
```

<a name=sr></a>
### Split() & rsplit
```py
list[] = str.split(seperator = None, maxsplit = -1)
list[] = str.rsplit(seperator = None, maxsplit = -1)

- seperator: if separator is not provide WHITESPACE is taken as separator
- maxsplit:
    - If maxsplit is provided, at most maxsplit splits are done
    - If maxsplit is not provided or -1, there is no limit on the number of splits 
Return: A list of strings.
```
**split:** splits into tokens from start to end
```py
word = 'Amit, will, achieve'
li = word.split(', ')
print(li)                    #['Amit', 'will', 'achieve']   //1

l2 = word.split(', ',1)      #['Amit', 'will, achieve']     //2
print(l2)
```
**rsplit()** splits into tokens from end to start
```py
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


