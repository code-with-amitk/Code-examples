## Disadvantages
- *1. Not present on Microsoft Windows older than Vista*
- *2. poll timeout has the 1millisec precision:*    
  - While select has nano-seconds
*3.  wasting CPU cycles in iterating through descriptors:*    
  - Same as select, need to iterate through whole list to find out which socket has event trig-erred on it. It will get slow when 1000+ descriptors are present.
  - Solution: 
