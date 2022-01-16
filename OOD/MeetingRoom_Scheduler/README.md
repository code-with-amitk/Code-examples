Meeting Room Scheduler OOD


## OOD
### 1. Requirements
- **Basic/Functional**
  - _1._ 1 Organizer can schedule m meetings.
  - _2._ There are n meeting rooms available. Meeting rooms can be added/removed dynamically.
  - _3._ Room capacity = 10 people. 
  - _4._ Notification would be sent to all attendees once meeting room is booked. Failure msg if invitee fails to book room.
- **Extended**
  - _1._ Meetings can be rescheduled.

### 2. Objects = Real World
```c
1. Meeting Scheduler: Wil lschedule the meetings
2. Meeting_Room
3. Meetings
4. Notification
5. User: Can be organizer or attendee
```
### 3. Relationship b/w objects
- **[`0..*`](/Languages/Modelling/UML/README.md#0ton):**
  - Meeting_Scheduler can hold atleast 0 and max n meeting rooms.
  - Meeting rooms can have atleast 0 or n meetings.
  - User to Meeting_Scheduler is 0 to n relationship, because user can use 0 or n meeting_scheduler class.
- **[`1..*`](/Languages/Modelling/UML/README.md#1ton):**
  - Meeting to Meeting room is 1ton relation, because only 1 meeting can be conducted at a time in meeting room.
```c
|-------------------| 0..*     |---------------|0..*          |--------------|
|                   |--------->|               |------------->|              |
| Meeting_Scheduler |          | Meeting room  |              |   Meeting    |
|                   |          |               |          1..*|              |
|-------------------|          |---------------|<-------------|--------------|
    /\                                                              /\   |1..n  //Meeting can have 1 or n attendees
    |                                                               |    |
    |0..*                                                           |    |
|-------|0..*     |---------------|                                 |    |
| User  |-------->| notifications |                                 |    |
|-------|         |---------------|                                 |    |
/\   | 0..*  //Bcoz 1 user can schedule 0 to many meetings.         |    |
|     |-------------------------------------------------------------|    |
|-------------------------------------------------------------------------     
   
```
