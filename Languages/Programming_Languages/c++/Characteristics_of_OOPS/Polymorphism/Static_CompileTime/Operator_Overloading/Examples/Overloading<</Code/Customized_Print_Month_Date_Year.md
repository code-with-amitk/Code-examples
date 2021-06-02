## Printing Month Date Year in Customized manner
```c++
#include <iostream>
using namespace std;

class Date{
  int month, date, year;
public:
  Date(int m, int d, int y):month(m),date(d),year(yr) {}
  friend ostream& operator<<(ostream& os, const Date& dt);
};

/*Equivalent
return-type function(var = cout, o = obj)
*/
ostream& operator<<(ostream& var, const Date& o) { 
  var << o.date << '/' << o.month << '/' << o.year;         //Each call to << passes data to 'cout' which dumps on stdout
  return var;
}

int main(){
  Date obj(31, 7, 2012);                        //Creates object obj (date=31, month=7, year=2013)

  /*Equivalent    
    object.function(hidden-self-address, Object-on-which-operation-to-applied)
    cout.(operator<<)(this, obj)
  */
  cout << obj;                                //Output:   31/7/2012
}

$ a.out
31/7/2012
```
