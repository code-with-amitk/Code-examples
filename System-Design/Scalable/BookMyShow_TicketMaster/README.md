**BookMyShow.com / TicketMaster.com / Online Ticket Booking system**

| Mega/Million 10<sup>6</sup> | Giga/Billion 10<sup>9</sup> | Tera/Trillion 10<sup>12</sup> | Peta/Quadrillion 10<sup>15</sup> | Exa/Quintillion 10<sup>18</sup> | Zeta/Sextillion 10<sup>21</sup> |
| --- | --- | --- | --- | --- | --- |

- [Requirments](#r)
- [BOE](#b)
- [HLD](#hld)
- [DB Schema](#db)


<a name=r></a>
### 1. Requirements
> When user logs into portal.. Portal should..
- *1.* Show Movies in City. 
  - *a.* Option to select Country > State > City > Show Movies in City
  - *b.* Ask permission from user to detect location
- *2.* Show Theater names, showtimings after Clicking on Movie name.
```c
Movie: Rambo
PVR-Select-Delhi  1:41pm  4:45pm  8pm
PVR-Naraina-Delhi 2pm   5pm   9pm
..
```
- *3.* Show seat layout to user to select seats. Seat can be holded for 5 minutes.
- *4.* After seat selection, take payment.
- *5.* Send E-Ticket on Phone, Email.

<a name=b></a>
## 2. BOE Calculations
[Self Video](https://youtu.be/oOPEeP1gSwA)
### *2a.* Traffic Estimates/Connections to be served/second.

|World Population|Using internet|Booking ticket on bookmyshow/month|PerDay|PerSecond|
|---|---|---|---|---|
|7 x 10<sup>9</sup>|40% = 28 x 10<sup>8</sup>|1% = 28 x 10<sup>6</sup>|9 x 10<sup>5</sup>|10<sup>4</sup> / 16 = 625|

### *2b.* Storage Estimates/Bytes to be stored for 5 years
- **Theater Data** Every theater information(name,address,number of seats) are stored inside bookmyshow.com's DB.
  - Theater will be base class. All derived classes are objects of theater base class.
  - All derived classes are created at start of Application(ie nothing created at runtime).
```c++
  class Theater {                         //Total size = 15+15+100+5700 = around 6000 bytes
    string TheaterName;                       //Max=30 characters. 1 character=4bit(Hex no system). 30 characters = 120bit = 15 byte
    string TheaterState;                      //15 byte
    string TheaterAddress(including PIN);     //200 characters. 800 bits. 100 bytes
    bool seats [row][col];                    //Each theater will have different. Assumed row=15, col=10
    struct userInformation[row][col];         //Each seat will have associated user DataStructure.  150x38 = 5700 bytes
  };
  struct userInformation{                   //38 bytes
    string name;                            //Max 30 characters. 15 bytes
    string email;                           //Max 30 characters. 15 bytes
    uint64_t phoneNumber;                   //64 bit. 8 byte
  };
  
-> For all 3600 Theaters. 5700x3600 = 20 MB
```

||Theater+User Data|Photos|Blogs|Videos|
|---|---|---|---|---|
|PerDay|20 MB|<ul><li>1 photo=5KB</li></ul>1 lac photos anytime. 5x10<sup>9</sup></li></ul>|<ul><li>1 blog=100KB</li></ul>1 lac blogs anytime. 100x10<sup>9</sup></li></ul>|<ul><li>1 Video=1GB</li></ul>50K videos anytime. 5x10<sup>13</sup></li></ul>|
|5 years|20 MB|5x10<sup>9</sup>|100x10<sup>9</sup>|5x10<sup>13</sup>|

- {For 5 years} 20 MB + 5x10<sup>9</sup> + 100x10<sup>9</sup> + 5x10<sup>13</sup> = 6 x 10<sup>13</sup> = 60 Tera Bytes / 5 years
- At anytime website will have 1 lac photos, blogs, 50k movies. Old will be deleted and new will be added.

<a name=hld></a>
### 3. HLD 
#### A. 1 User
```c
          Server
Stores all seats,theater listing
of worldwide theaters                               User
            <--Logs into server, does seat booking--
                                              Prints seatno, date
```

#### B. 100-1Million Users
[Self Video](https://youtu.be/NIEP7wdJOMA)
#### Steps
- *1.*
  - *a.* BMS representative comes to Theater owner, creates theater layout on bookmyshow.com.
  - *b.* Provides URL to Theater Owner to which Theater Owner can login and:
    - Assign shows, show-timings,  Cost per seat, Book a seat(it gets update in bookmyshow DB)
- *2.* User enters https://bms.com in browser. Browser gets IP-Address using DNS.
- *3.* Browser opens a "[Web socket](https://github.com/amitkumar50/Code-examples/blob/master/networking/OSI-Layers/Layer5/LongPooling_WebSockets.md)" connection to IP-Address of BMS via Forward Proxy.
- *4.* CDN provides homepage to user.
  - If user is registered and tries login, authenticated using s3 auth.
- *5.* User selects theater,show,seat. Browser sends Theater-UniqueId, Show,seats to CDN.
- *6.* CDN forwards message nearest in Data-center.
- *7.* SSL Terminator decrypts HTTPS Packet to HTTP packet, sends to load balancer.
- *8.* Load balancer selects Application server based on Hash based scheduling algorithm.
- *9.* Finds the datacenter which stores the information of Theater-1. 
- *10.* Responds back to CDN > User. Please wait we are processing
- *11.* Application server sends logs to log storage
- *12.* Real time data is sent for analysis using kinetics
- *13.* AI powered Sagemaker helps admins to derive meaning and write new rules
- *14.* Application server sends message to DB updater found in Step-9
- *15.* RDS updates the theater-SQL DB, user-SQL DB. (RDS: This is a web service running "in the cloud" for setup, operation, and scaling of a relational/SQL databases. This itself is not SQL Database.)
- *16.* Movie-Code, Theater-Code, ClientIP, Number of tickets are filled in Amazon-SQS(Simple Queue Service)
- *17.* Price Calculator service, calculates the cost and sends to AWS PAYGATE(payment gateway).
- *18.* Payment gateway(Paygate) converts the dollars to INR(local currency) & sends to pay.

<img src="./bookmyshow-hld.png" width=1000 />

<a name=db></a>
### 4. DB Schema

- **Movie-DB**

|varchar title|varchar language|datetime ReleaseDate|varchar Country|varchar Genre|
|---|---|---|---|---|

- **Theater-DB**

|varchar name|int seats`[row][col]`|int TheaterId|int NumberOfShow|map<string(moviename), <float(showstarttime), float(showendtime)>> MovieInfo;|float cost`[row][col]`|UserInformation us`[rows][cols]`;|
|---|---|---|---|---|---|---|
- **UserInformation-DB**

|varchar name|varchar email|uint64_t phoneNo|
|---|---|---|

- **Multiplex-DB**

|varchar name|varchar address|struct Theater theater`[6]` //6 screens|
|---|---|---|

```c++
  struct Movie{
    float duration;
    map<string, string> Characters;           //<Hero, Amit>|<Villian, Amit>|..
    float ThisWeekRating;
  };
  struct Theater{
    int seats[rows][cols];
    string TheaterName;                       //Audi-1,2,3,4
    int numberOfShows;
    map<string, <float, float>> MovieInfo;    //<movie-name, [showStartTime, showEndTime]>
    float cost[rows][cols];
    UserInformation us[rows][cols];
  };
  class Multiplex {
    string Name;
    string Address(including PIN);
    struct Theater theater[6];             //Assuming 6 theaters inside multiplex
  };
  struct UserInformation{
    string name;         
    string email;        
    uint64_t phoneNumber;
  };
```
