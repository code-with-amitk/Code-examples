## Observer Design Pattern
- There is 1 SUBJECT & N OBSERVERS. 
- Whenever there is change in any value/state of Subject, then that must be notified to Observers. This duty of notification is done by Subject itself. 
- Subject maintains list of observer objects with itself.

### Terms
- **Observer?** Object that wants to receive events.
- **Subject?** Receives events and will inform observers. Subject can: register observers, deregister/remove observers.
- **How it works?**
  - Observer will register to subject
  - subject will inform observer.

### Examples
- [Whether Display Device](Whether_Display_Device)
