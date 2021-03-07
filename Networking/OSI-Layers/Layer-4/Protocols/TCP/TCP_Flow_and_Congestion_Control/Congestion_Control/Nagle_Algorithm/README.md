### Small Packet Problem(Eg in telnet)?
  - Application sends 1 byte packet repeatedly, with 40 byte overhead(20 byte TCP + 20 byte IP). 
  - Now packet size=41 bytes. In telnet where most keypresses generate a single byte of data that is transmitted immediately.  
  - If a process is causing many small packets to be transmitted, it may be creating undue network congestion. its similar to a big truck carrying a mango carton and roaming in city.

### NAGLE ALGORITHM:
- Solves Small packet problem.
- Combines small packets and sends at once all sent data is acknowledged. Nagle's algorithm is undesirable in highly interactive environments.
- **Turning off nagling.** TCP_NODELAY = false
