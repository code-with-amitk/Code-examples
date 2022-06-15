**format**

### format
`<format>` provides new text-formatting capabilities, earlier we need to use setprecision(), fixed()
```cpp
#include <iostream>
#include <cmath> // for pow function
#include <format>       // in C++20
using namespace std;

int main() {
	double principal{ 1000.00 }, rate {.5};

  /*{:>7.2f} 
    f - for a floating-point number
    > - right-aligned in a 7-character field width that has 
        two digits of precision (.2) to the right of the decimal point
  */
	cout << format("Initial principal: {:>7.2f}\n", principal);

	cout << format("\n{}{:>20}\n", "Year", "Amount on deposit");

	// calculate amount on deposit for each of ten years
	for (int year{ 1 }; year <= 3; ++year) {
		double amount = principal * pow(1.0 + rate, year);
		cout << format("{:>4d}{:>20.2f}\n", year, amount);
	}
}

$ ./a.out
Initial principal: 1000.00

Year   Amount on deposit
   1             1500.00
   2             2250.00
   3             3375.00
```

#### `{:>7.2f}`
<img src=format.jpg width=400 />
