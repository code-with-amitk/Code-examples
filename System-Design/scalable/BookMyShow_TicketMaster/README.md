## BookMyShow.com / TicketMaster.com / Online Ticket Booking system

### 1. Requirements
> When user logs into portal.. Portal should..
- *1.* Show Movies in City. 
  - *a.* Option to select Country > State > City > Show Movies in City
  - *b.* Ask permission from user to detect location
- *2.* Show Theater names, showtimings after Clicking on Movie name.
```c
Movie: Rambo
PVR-Select-Delhi  1.41pm  4.45pm  8pm
PVR-Naraina-Delhi 2pm   5pm   9pm
..
```
- *3.* Show seat layout to user to select seats. Seat can be holded for 5 minutes.
- *4.* After seat selection, take payment.
- *5.* Send E-Ticket on Phone, Email.

### 2. BOE Calculations
#### Connections to be served/second. Traffic Estimates

|World Population|Using internet|Booking ticket on bookmyshow/month|PerDay|PerSecond|
|---|---|---|---|---|
|7 x 10<sup>9</sup>|40%|1% = 28 x 10<sup>6</sup>|9 x 10<sup>5</sup>|10<sup>4</sup> / 16 = 625|

#### Bytes to be stored for 5 years. Storage Estimates.

||User Data|Photos|Blogs|Videos|
|---|---|---|---|---|
|PerDay|2KB x 1KB (assuming 1 user data=2KB)|<ul><li>1 photo=5KB</li></ul><1 lac photos anytime. 5x10<sup>9</sup></li></ul>||||
|5 years|3 x 10<sup>9</sup>|5x10<sup>9</sup>||||
