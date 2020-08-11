[Other functions](https://docs.python.org/3/tutorial/datastructures.html)

### 1. list.append(x)
- Appends elements at end of list
### 2. list.len()
- Finds length of list
```
a.append(21)
print(a)        #[1,2,3,4,5,6,7,21]
print(len(a))   #8
```

### 3. Del statement
- Delete a value or complete slice or list
- Return: None, just deletes the value
```
a1 = ['a','b',1,2,5,'p']
del a1[0]               #delete 'a', return None
print(a1)               #['b',1,2,5,'p']
del a1[2:4]             # deletes [1,2]
print(a1)               #b['b',5,'p']
del a1[:]               #delete everything
print(a1)               #[]
del a1                  # Deleting variable, referencing will give error
#print(a1)              #name 'a1' is not defined
```
