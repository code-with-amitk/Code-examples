"""
TUPLES():
 - WITH OR WITHOUT (): Tuples can be defined with or without ()
 - RO/IMUTABLE: values inside tuples cannot be changed
 - NESTED: Tuples can be combined
 - MUTABLE TUPLES FROM LISTS: Tuples can be created from list, and because lists are mutable tuples can be made mutable as well
 - EMPTY TUPLE: e = ()
 - SINGLE VALUED TUPLE: a tuple with one item is constructed by following a value with a comma (it is not sufficient to enclose a single value in parentheses). Ugly, but effective.
 - PACKING/UNPACKING TUPLE:
    PACKING: Filling the values inside tuple
    UNPACKING: Unpacking the tuple to variables
"""

###WITH OR WITHOUT ()###
b = (1,3,'f','my')
a = 1,3,'f','my'
print(a)                #(1, 3, 'f', 'my')

###IMMUTABLE/RO###
#a[0]=5                 #'tuple' object does not support item assignment

##NESTED TUPLE##
n = a,(4,5,'h')
print(n)        #((1, 3, 'f', 'my'), (4, 5, 'h'))

##TUPLES FROM LIST##
c = ([1, 2, 3])
print(c)        #[1, 2, 3]
c[0]=4
print(c)        #[4, 2, 3]

##EMPTY TUPLE##
e = ()
print(e)        #()
print(len(e))   #0

##SINGLE VALUED TUPLE##
e1 = 'test',
print(e1)       #('test',)
print(len(e1))  #1

##PACKING/UNPACKING##
f = 12345, 54321, 'hello!'      #PACKING
x,y,z = f                       #UNPACKING to values
print(x,y,z)                    #12345 54321 hello
