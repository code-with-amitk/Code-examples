"""     memory_profiler.py

- Just decorate the function with profile
- Execute the code passing the option -m memory_profiler to the python interpreter 
  will load the memory_profiler module and print to stdout the line-by-line analysis.

"""

@profile        #Decorate any function with this decorator
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

Understanding coloumns:
Col-1: line number of the code that has been profiled
Col-2(Mem usage): Memory usage of the Python interpreter after that line has been executed.
Col-3(Increment): difference in memory of the current line with respect to the last one. ie how much memory current 
instruction took.
Col-4((Line Contents); prints the code that has been profiled.
"""
