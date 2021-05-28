## SPI / SECURITY PARAMETER INDEX)
> eg:7C123A9C. 
- This tag helps the Peers to distinguish between two IPSec streams. 
- For Example: if there were 2 different IPSEC flows between 2 peers, each using a different secret key, the SPI would allow each peer to determine which key to use on each packet. 
- **Can SPI be same as cookie?** Yes
- **Where is used?** It should be present in IPSec SA. An SPI has only local significance, since it is defined by the creator of the SA.
