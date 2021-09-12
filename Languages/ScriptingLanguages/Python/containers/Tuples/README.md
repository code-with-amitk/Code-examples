**Tuples**
  - [Empty Tuple](#e)
  - [Nested Tuples](#n)
- **Create**
  - [1. Input from user](#c1)
  - [2. Without ()](#c2)
  - [3. From List](#c3)
- [Packing, Unpacking](#pu)

## Tuples
RO/Immutable lists ie values inside tuples cannot be changed.
```py
a = [1,2,3,4]
a[0]=5                 #'tuple' object does not support item assignment
```
<a name=e></a>
#### Empty Tuple
```
e = ()
print(e)        #()
print(len(e))   #0
```
<a name=n></a>
#### Nested Tuples
Tuples can be combined.
```
n = a,(4,5,'h')
print(n)        #((1, 3, 'f', 'my'), (4, 5, 'h'))
```

### Create Tuple
<a name=c1></a>
#### 1. Input from user
```py
a = input("Input some comma seprated numbers : ")     #1,2,3,4
t = tuple(a)
print('Tuple:',t)                                     #(1,2,3,4)
```
<a name=c2></a>
#### 2. Created with or without `()`
```
b = (1,3,'f','my')
a = 1,3,'f','my'
print(a)                #(1, 3, 'f', 'my')
```
<a name=c3></a>
### 3. Creating Tuples from list
Tuples can be created from list, and because lists are mutable tuples can be made mutable as well
```
c = ([1, 2, 3])
print(c)        #[1, 2, 3]
c[0]=4
print(c)        #[4, 2, 3]
```

<a name=pu></a>
### Packing/Unpacking of Tuples
- **PACKING:** Filling the values inside tuple
- **UNPACKING:** Unpacking the tuple to variables
```py
f = 12345, 54321, 'hello!'      #PACKING
x,y,z = f                       #UNPACKING to values
print(x,y,z)                    #12345 54321 hello
```
