- **April, 2022**
  - [R1. Take home challenge](#r1)

### April, 2022
<a name=r1></a>
**Coding Challenge**
- _1._ Write `int smallest_missing_number_offline(std::vector<int> numbers);`
```c
which returns smallest non-negative integer missing in provided vector of numbers.
smallest_missing_number_offline({1, 0, 5}) == 2
smallest_missing_number_offline({1, 2, 3}) == 0
smallest_missing_number_offline({0, 1, 2}) == 3
```
- 2. Implement class which allows duplicate numbers as well
```c
class MissingStructure {
public:
  void insert(int number);
  void erase(int number);
  int smallest_missing_number() const;
}
```
- _3._ Implement `int smallest_missing_substring_number(std::string digits);`
```c
which returns smallest non-negative integer not occuring in digits as substring. 
For purpose of this challenge assume that substring is non-empty contigous subsequence of 
given string (from some position to some position). For example: `1`, `256` and `152569` are 
all substrings of `152569`, while `0` and `126` are not.
smallest_missing_substring_number("0110123456789") == 13
smallest_missing_substring_number("98765432") == 0
smallest_missing_substring_number("0987654321") == 10
smallest_missing_substring_number("23009401") == 5
```
- _4._ Implement function `std::string smallest_missing_subsequence_number(std::string digits);`
```c
smallest_missing_subsequence_number("0110123456789") == "20"
smallest_missing_subsequence_number("012345678901234567890") == "111"
smallest_missing_substring_number("98765432") == "0"
smallest_missing_substring_number("0987654321") == "10"
smallest_missing_substring_number("23009401") == "5"
```
