## Advantages
> poll was mainly created to fix the pending problems select

- *1. No hard limit on the number of descriptors poll can monitor:*
  - so the limit of 1024(which select() has) does not apply here.
- *2. Does not modify the data passed in the struct pollfd data:*    
  - Therefore it could be reused between the poll() calls as long as set to zero the revents member for those descriptors which generated the events.
- *3. more fine-grained control of events comparing to select:*    
  - For example, it can detect remote peer shutdown without monitoring for read events.
