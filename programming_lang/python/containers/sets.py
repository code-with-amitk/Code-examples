"""    sets.py

What? Unordered collection with no duplicates.

OPERATIONS
  A. Set objects support mathematical operations like union, intersection, difference, and symmetric difference
  B. a1=set(''), b1=set('').
    a1-b1 are those letters in a1 but not in b1
  C. UNION(|). Letter in set-a and set-b both
  D. INTERSECTION(&). Letters common in set-a and set-b.
  E. (^). Letters in set-a or set-b but not both
  F. Set Comprehension:
  make new set where each element is the result of some operation in just 1 line or few lines, rather than writing whole function.
"""
a = {'a', 'b', 'a', 'c', 'd', 'c'}
print(a)                            #{'a', 'c', 'b', 'd'} //Duplicates removed.   A

a1 = set('abcde')
b1 = set('abcdf')
print(a1-b1)                        #{'e'}  B

print(a1|b1)                        #{'b', 'c', 'f', 'e', 'd', 'a'} C. Union

print(a1&b1)                        #{'a', 'c', 'b', 'd'}   D. Intersection

print(a1^b1)                        #{'f', 'e'} E

s = {i for i in 'abcdefghiab' if i not in 'abc'}    #F
print(s)
