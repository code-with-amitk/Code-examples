
NumPy has its own submodule for pseudo-random number generation called **np.random**

This is similar to python's **random** module

### 1. Generating pseudo random numbers
> np.random.randint(n): Choose a random integer uniformly from the range [0, n)

> np.random.randint(low,high): Choose a random integer uniformly from the range [low, high).

```
print(np.random.randint(5))             #Any random number less than 5
print(np.random.randint(5))           
print(np.random.randint(5, high=6))     

random_arr = np.random.randint(-3, high=14,size=(2, 2))
print(repr(random_arr))                 #array([[-2,  0],[ 8, -3]])
```
