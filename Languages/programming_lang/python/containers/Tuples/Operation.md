## 1. Tuples are immutable
- values inside tuples cannot be changed
```
a = [1,2,3,4]
a[0]=5                 #'tuple' object does not support item assignment
```

## 2. Packing/Unpacking of Tuples:
- PACKING: Filling the values inside tuple
- UNPACKING: Unpacking the tuple to variables
```
f = 12345, 54321, 'hello!'      #PACKING
x,y,z = f                       #UNPACKING to values
print(x,y,z)                    #12345 54321 hello
```

## 3. Single Valued tuple
- A tuple with one item is constructed by following a value with a comma (it is not sufficient to enclose a single value in parentheses). Ugly, but effective.
```
e1 = 'test',
print(e1)       #('test',)
print(len(e1))  #1
```

## 4. Empty Tuple
```
e = ()
print(e)        #()
print(len(e))   #0
```

## 5. Nested Tuples
-  Tuples can be combined.
```
n = a,(4,5,'h')
print(n)        #((1, 3, 'f', 'my'), (4, 5, 'h'))
```
