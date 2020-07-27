## Definition of Iterator Pattern

## PROBLEM/TASK
- Company X acquired over 2 resturants
  - LunchSpecialistResturant
    - This Resturant has his own implementation using `ArrayList`
  - DinnerMenuHotel
    - This Hotel has internal implementation in `Arrays`
- Problem is:
  - Company X wants *Waitress* to present both menus to customers without problems.
    - For waitress to cater both menus she has to write 2 functions to displaying both menus seperately by iterating through each item.
    - Again, if Company X acquires new hotel, new function needs to be written.
    - For displaying the menu, writing code again and again is not a good idea.
    
## Solution
- How about asking each resturant to implement 2 additional methods.
  - `size()`: Returns size of the container.
  - `get(i)`: Returns each item from the container.
```
for (int i = 0; i < breakfastItems.size(); i++) {
  MenuItem menuItem = (MenuItem)breakfastItems.get(i);
}
```
