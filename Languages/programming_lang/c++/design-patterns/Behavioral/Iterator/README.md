## Definition of Iterator Pattern

## PROBLEM/TASK
- Company X has taken over 2 resturants
  - LunchSpecialistResturant
    - This Resturant has his own implementation using `ArrayList`
  - DinnerMenuHotel
    - This Hotel has internal implementation in `Arrays`
- Problem is:
  - Company X wants *Waitress* to present both menus to customers without problems.
    - For waitress to cater both menus she has to write 2 functions to displaying both menus seperately by iterating through each item.
    - Again, if Company X acquires new hotel, new function needs to be written.
    - For displaying the menu, writing code again and again is not a good idea.
  
