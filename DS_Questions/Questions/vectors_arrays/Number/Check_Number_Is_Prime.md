**Check number is prime?**
- [Logic](#l)
- [Code](#c)

<a name=l></a>
### Logic
```c
n = 47
```
1. Take square root of number. k = sqrt(n). Why sqrt? Smallest factor of number cannot be greater than sqrt(n).
```c
k = 6.8
```
2. Divide k by all numbers from (2 ... k), if reminder==0 it not prime.
```c
6.8/2 != 0 
6.8/3 != 0
6.8/4 != 0
6.8/5 != 0
Not prime
```
<a name=cpp></a>
 ### Code
 ```c
int main(){
  int n=49
  bool bPrime = false;
  cout << sqrt(n);    //6.85....

  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0){
      flag = true;
      break;
    }
  }

  if (flag)
    cout<<"not prime";
    else
  cout<<"prime";
}
```
