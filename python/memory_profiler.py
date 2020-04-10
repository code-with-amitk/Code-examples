"""     memory_profiler.py
- Just decorate the function with profile
"""

@profile
def fun():
    print('a')
    a=5
    b=6
    c=a+b
fun()

"""
# pip3 install memory_profiler
# python3.6 -m memory_profiler test.py 
a
Filename: test.py

Line #    Mem usage    Increment   Line Contents
================================================
     1   15.422 MiB   15.422 MiB   @profile
     2                             def fun():
     3   15.422 MiB    0.000 MiB       print('a')
     4   15.422 MiB    0.000 MiB       a=5
     5   15.422 MiB    0.000 MiB       b=6
     6   15.422 MiB    0.000 MiB       c=a+b

"""
