"""     dictionary.py
WHAT? 
 - These are Associative arrays, {key:value} pairs.
 - Dictionaries are indexed by keys
 - Keys in Dictionary: Are immutable/RO/Unchangable/Unique
   Example of keys: 
      (i) strings and numbers
      (ii) Tuples if they contain only strings, numbers, or tuple
      (iii) Lists cannot be used as keys as lists can be modified in place using index assignments
 - Values in Dictionary:
   If we try entering value of existant key, the old value associated with that key is overwritten.

OPERATION ON DICTIONARY: Storing a value with some key and extracting the value given the key
 A. Building & Accessing:
    A1. Initialize & Create
    A2. Using dict() constructor: Creates dictionary from sequences of key-value pairs
 B. Delete Entry:   del(a[key])
 C. List of keys:   list(a)  lists all keys present in dictionary
 D. Sorted keys:    sorted(a)    Printing sorted keys present in dictionary
 E. Comprehension: Make new dictionary where each element is the result of some operation in just 1 line or few lines, rather than writing whole function
 F. METHODS:
    F1. items(): Used to retrieve (key,value) both from dictionary
    F2. enumerate(): To retrieve (index,key) of dictionary
    F3. zip(): 2 or more sequneces can be paired
"""

#Builing & Accessing#
dic = {'a':10, 'b':20}      #A1
dic['c']=30
print(dic)                #{'a': 10, 'b': 20, 'c': 30}
print(dic['a'])           #10
print('a' in dic)         #True

f = dict([('ab', 4), ('cd', 5), ('ef', 6)])     #A2
print(f)                            #{'ab': 4, 'cd': 5, 'ef': 6}


#Delete entry#
del(dic['c'])
print(dic)              #{'a': 10, 'b': 20}     B


#Print List of Keys#
print(list(dic))        #['a', 'b']     C


#Print Sorted Keys#
print(sorted(dic))      #['a', 'b']     D


#Dictionary Comprehension#
print({i: i**2 for i in (2, 3, 4)})     #{2: 4, 3: 9, 4: 16}    E


#METHODS#
#items()#       F1
for i, j in f.items():
    print(i,j)          #ab 4   cd 5    ef 6    

#enumerate()#   F2
for i, j in enumerate(f):
    print(i,j)          #0 ab   1 cd    2 ef

#zip()#         F3
questions=['a','b','c']
answers=['x','y','z']
for i, j in zip(questions, answers):
    print(format('Question:{0} Answer:{1}'.format(i,j)))    #Question:a Answer:x
