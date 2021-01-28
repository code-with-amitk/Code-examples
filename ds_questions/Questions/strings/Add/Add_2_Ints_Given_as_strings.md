## [Add Strings](https://leetcode.com/problems/add-strings/)
- Two integers are given as string, add them as ints and return string again.
- Examples:
```c
  Input a = "237", b = "234".
  Output = "471"

  Input a = "100", b = "9".
  Output = "109"
```

### 1. Approach //Keep adding ints from end
- **Logic**
  - *1.* Start from end of both strings. Parse indivisual characters.
  - *2.* Convert parsed character into int.
  - *3.* Perform sum. Note carry(if generated).
  - *4.* Take a output string, Keep inserting at start of output string.
  - *5.* Perform (Step 1-4) until a or b are non-empty. As soon a or b becomes empty, perform same operation on remaining string.
- **Complexity**
  - **Time:** O(max(n,m)). n=Length of a, m=Length of b.
  - **Space:** O(max(n,m)). Output string.
- **Code-1:** Show this first
```c
std::string addStrings(std::string num1, std::string num2) {
  int i = num1.size()-1, j = num2.size() - 1;
  std::string out;
  int ia = -1, ib = -1, carry = 0, sum = 0;

  while(i>-1 and j>-1){
    ia = num1.at(i) - '0';
    ib = num2.at(j) - '0';
    sum = ia+ib+carry;

    if (sum>9){
      carry = 1;
      sum -= 10;
    }else
      carry = 0;
    out.insert(0,std::to_string(sum));
    --i; --j;
  }

  while(i>-1){
    sum = carry + (num1.at(i)-'0');
    if (sum>9){
      carry = 1;
      sum -= 10;
    }else
      carry = 0;
    out.insert(0,std::to_string(sum));
    --i;
  }
  
  while(j>-1){
    sum = carry + (num2.at(j)-'0');
    if (sum>9){
      carry = 1;
      sum -= 10;
    }else
      carry = 0;
    out.insert(0,std::to_string(sum));
    --j;
  }
  if (carry)
    out.insert(0,std::to_string(carry));

  return out;
}  
```
- **Code-2:** Repeated operations taken at 1 place
```c++
std::string addStrings(std::string num1, std::string num2) {
  int i = num1.size()-1, j = num2.size() - 1;
  std::string out;
  int ia = -1, ib = -1, carry = 0, sum = 0;

  while(i>-1 or j>-1){
    i>-1 ? ia = num1.at(i) - '0' : ia = 0;
    j > -1 ? ib = num2.at(j) - '0' : ib = 0;

    sum = (ia+ib+carry)%10;
    carry = (ia+ib+carry)/10;

    out.insert(0,std::to_string(sum));
      --i;
      --j;
  }

  if (carry)
    out.insert(0,std::to_string(carry));

  return out;
}
``` 
