## BookMyShow.com / TicketMaster.com / Online Ticket Booking system

| Mega/Million 10<sup>6</sup> | Giga/Billion 10<sup>9</sup> | Tera/Trillion 10<sup>12</sup> | Peta/Quadrillion 10<sup>15</sup> | Exa/Quintillion 10<sup>18</sup> | Zeta/Sextillion 10<sup>21</sup> |
| --- | --- | --- | --- | --- | --- |

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
|PerDay|2KB x 1KB (assuming 1 user data=2KB)|<ul><li>1 photo=5KB</li></ul>1 lac photos anytime. 5x10<sup>9</sup></li></ul>|<ul><li>1 blog=100KB</li></ul>1 lac blogs anytime. 100x10<sup>9</sup></li></ul>|<ul><li>1 Video=1GB</li></ul>50K videos anytime. 5x10<sup>13</sup></li></ul>|
|5 years|3 x 10<sup>9</sup>|5x10<sup>9</sup>|100x10<sup>9</sup>|5x10<sup>13</sup>|

- {For 5 years} 3 x 10<sup>9</sup> + 5x10<sup>9</sup> + 100x10<sup>9</sup> + 5x10<sup>13</sup> = 6 x 10<sup>13</sup> = 60 Tera Bytes / 5 years
- At anytime website will have 1 lac photos, blogs, 50k movies. Old will be deleted and new will be added.
