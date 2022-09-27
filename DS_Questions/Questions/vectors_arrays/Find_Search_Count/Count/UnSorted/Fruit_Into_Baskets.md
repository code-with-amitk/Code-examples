**Fruit Into Baskets**
- [Approach-1, Brute Force. O(n<sup>2</sup>)](#a1)
- [Approach-2, Sliding Window](#a1)

### [Fruit Into Baskets](https://leetcode.com/problems/fruit-into-baskets/)
- You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where `fruits[i]` is the type of fruit the ith tree produces.
- You want to collect as much fruit as possible. However, there some Restrictions:
  - You only have 2 baskets, and each basket can only 1 type of fruit. Example: all 0's or all 1's etc. no limit on amount of fruits in basket.
  - Fruits should be consecutive.
  - Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
- Given the integer array fruits, **return the maximum number of fruits** you can pick.
- Examples
```c
Example-1
Input: fruits = [1,2,1]
Output: 3
Explanation:
i  basket1  count_basket1   basket2    count_basket2
0   1         1
1                            2          1              //we cannot place fruit=1 in basket=1
2             2                                        //Place in basket=1
Total count=3

Example-2
Input: fruits = [1,2,3,2,2]
Output: 4
Explanation:
i  basket1  count_basket1   basket2    count_basket2    count
0   1         1
1                            2          1                 2   //we cannot place fruit=1 in basket=1
2   3         1                                               //We need to empty any 1 basket, since same type of fruit is allowed
3                                       2
4                                       3                 4
```

<a name=a1></a>
### Approach-1, Brute Force = O(n<sup>2</sup>)
- 2 for loops
- Outer for loop, select 1 fruit
- Inner for loop, check all fruits until 3rd is found

<a name=a2></a>
### Approach-2, Sliding Window
#### Logic
- _1._ Assign `fruit[0]` to basket1
```c
fruits  = 1	0	1	4	1	4	1	2	3
```
- _2._ if next fruit is not same as fruit in basket1, assign to basket2, keep on increcementing count until either fruit in basket1 or basket2 is found.
- _3._ As We find a new fruit.
  - Check whether new fruit existent in any basket, if it is, traverse backward to see count of fruits.
#### Code
```cpp
class Solution {
public:
    int totalFruit(vecI& fruits) {
        int basket1 = fruits[0], basket2 = -1, countb1 = 1, countb2 = 0, count = 0;
        for (int i=1;i<fruits.size();++i){
            if (fruits[i] == basket1 || fruits[i] == basket2 || basket2==-1) {
                if (fruits[i] == basket1)
                    countb1++;
                else {
                    basket2 = fruits[i];
                    countb2++;
                }
            } else {
                count = std::max(count, (countb1 + countb2));
                int j = i-1, temp=0;
                if (fruits[i-1] == basket1){
                    basket2 = fruits[i];
                    countb2 = 1;

                    //Count same fruits backward
                    while (fruits[j--] == basket1)
                        temp++;
                    countb1 = temp;
                }else if(fruits[i-1] == basket2){
                    basket1 = fruits[i];
                    countb1 = 1;

                    //Count same fruits backward
                    while (fruits[j--] == basket2)
                        temp++;
                    countb2 = temp;
                }else{
                    basket1 = fruits[i-1];
                    basket2 = fruits[i];
                    countb1 = countb2 = 1;
                }
            }
        }
        return std::max(count, countb1+countb2);
    }
};
```
#### Complexity
- **Time:** O(nm).  n=Total fruits, m=max consecutive same kind of fruits
- **Space:** O(1)
