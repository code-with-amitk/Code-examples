
## Modules as scripts
- Means passing command line arguments to module. This code needed to be added at end of module:
```python
    # vim mult_sum.py
        def mult1(a,b):
            print('Mult:',a*b)
        def sum1(a,b):
            print('Sum:',a+b)    
        if __name__ == "__main__":
            import sys
            mult1(int(sys.argv[1]),int(sys.argv[2]))

    # python3.6 mult_sum.py 2 3         #6
```
