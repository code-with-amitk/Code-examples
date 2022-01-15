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
```c

|-------------------| 0..*    |---------------|1..*         |--------------|
| Meeting_Scheduler |---------| Meeting rooms |-------------| Meetings     |
|-------------------|         |---------------|             |--------------|
    |                                                         |
|-------|         |---------------|                           |
| User  |---------| notifications |                           |
|-------|         |---------------|                           |
   |1..*  //Bcoz 1 user can schedule 1 to many meetings.      |
   |----------------------------------------------------------|
```
