## Observer Design Pattern
```c
          --  observer-1
subject --    observer-2
          --  observer-3
```
- There is 1 SUBJECT & N OBSERVERS. 
- Whenever there is change in any value/state of Subject, then subject notifies it to Observers. Subject maintains list of observer objects with itself.

### Terms
- **Observer?** Object that wants to receive events.
- **Subject?** Receives events and will inform observers. Subject can: register observers, deregister/remove observers.

### Examples
- [Whether Display Device](Whether_Display_Device)
