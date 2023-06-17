- [Permutations/Arragement (Greater than comb)](#p)
  - Questions
- [Combinations/Choice (Smaller than Perm)](#c)
  - Questions
    - [Pascal Traingle = Combination Tree](DS_Questions/Questions/vectors_arrays/2d-grid/Pascal_Traingle.md)
    - [Number of Ways to Reorder Array to Get Same BST](/DS_Questions/Data_Structures/Trees/binary-search-tree/Number_of_Ways_to_Reorder_Array_to_Get_Same_BST.md)

### [My Video](https://youtu.be/ijLshCenMEk)

<a name=p></a>
### Permutation/Arrangement
> [Good Video](https://www.youtube.com/watch?v=DROZVHObeko)
- <sup>n</sup>P<sub>r</sub> = n!/(n-r)!
- Never look at formula, always count.
- Examples
```c
1. In how many ways 5 persons (p1,p2..p5) can sit on 5 chairs?
_ _ _ _ _ 
5 4 3 2 1 <- ways.  5! = 5x4x3x2x1 = 120 ways

2. In how many ways 5 persons (p1,p2..p5) can sit on 3 chairs?
_ _ _ 
5 4 3 <- 5x4x3 = 60 ways
```

<a name=c></a>
### Combination/Choose. Repetition not allowed
> [Good Video](https://www.youtube.com/watch?v=p8vIcmr_Pqo)
- <sup>n</sup>C<sub>r</sub> = n!/(n-r)!r! 
```c
1. In how many ways 3 persons can be choosen from 5(p1,p2..p5) to sit on 3 chairs? <sup>5</sup>C<sub>3</sub> = 10
_  _  _ 
p1 p2 p3    //These are considered as 1 way. All the same.
p1 p3 p2
p2 p1 p3
p2 p3 p1
p3 p1 p2
p3 p2 p1

Permutations / 3!

2. Combination/Choosing of 2 numbers out of 4. <sup>4</sup>C<sub>2</sub> = 4!/2!2! = 6
[1,2,3,4]
12    //21 is not taken, 12 21 are same. Since its not arragement
13
14
23
24
34

3. Combination/Choosing of 3 numbers out of 4. <sup>4</sup>C<sub>3</sub> = 4!/3!1! = 4
[1,2,3,4]
123    //321 is not taken, 123 = 321 are same. Since its not arragement
124
234
134     //or 431 both are same
```
