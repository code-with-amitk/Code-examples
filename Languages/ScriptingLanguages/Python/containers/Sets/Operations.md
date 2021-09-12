- [Set Difference](#d)
- [Union](#u)
- [Intersection](#i)
- [XOR (^). Letters in set-a or set-b but not both](#x)

<a name=sd></a>
### Set Difference
a1=set(''), b1=set(''). a1-b1 are those letters in a1 but not in b1
```py
a1 = set('abcde')
b1 = set('abcdf')
print(a1-b1)                        #{'e'}  B
```
<a name=u></a>
### Union (|)
```py
a1 = set('abcde')
b1 = set('abcdf')
print(a1|b1)                        #{'b', 'c', 'f', 'e', 'd', 'a'}
```
<a name=i></a>
### Intersection (&)
Common elements in set-a, set-b
```py
a1 = set('abcde')
b1 = set('abcdf')
print(a1&b1)                        #{'a', 'c', 'b', 'd'}
```
<a name=x></a>
### XOR (^). Letters in set-a or set-b but not both
```py
a1 = set('abcde')
b1 = set('abcdf')
print(a1^b1)                        #{'f', 'e'} E
```
