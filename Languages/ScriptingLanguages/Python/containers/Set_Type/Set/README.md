**Sets**
- [Comprehension](#com)
- Operations
  - [Set Difference](#d)
  - [Union](#u)
  - [Intersection](#i)
  - [XOR (^). Letters in set-a or set-b but not both](#x)


## Sets
Unordered collection of key, Duplicates not stored
```py
a = {'a', 'b', 'a', 'c', 'd', 'c'}
print(a)                            #{'a', 'c', 'b', 'd'}       #Duplicates not stored
```

<a name=com></a>
### Set Comprehension
Make new set where each element is the result of some operation in just 1 line or few lines, rather than writing whole function.
- Example-1: Create set without a,b,c
```py
s = {i for i in 'abcdefghiab' if i not in 'abc'} 
print(s)
```

## Operations
<a name=sd></a>
#### Set Difference
a1=set(''), b1=set(''). a1-b1 are those letters in a1 but not in b1
```py
a1 = set('abcde')
b1 = set('abcdf')
print(a1-b1)                        #{'e'}  B
```
<a name=u></a>
#### Union (|)
```py
a1 = set('abcde')
b1 = set('abcdf')
print(a1|b1)                        #{'b', 'c', 'f', 'e', 'd', 'a'}
```
<a name=i></a>
#### Intersection (&)
Common elements in set-a, set-b
```py
a1 = set('abcde')
b1 = set('abcdf')
print(a1&b1)                        #{'a', 'c', 'b', 'd'}
```
<a name=x></a>
#### XOR (^). Letters in set-a or set-b but not both
```py
a1 = set('abcde')
b1 = set('abcdf')
print(a1^b1)                        #{'f', 'e'} E
```
