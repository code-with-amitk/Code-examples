## ICMP Header

```html
| MAC | IP | ICMP-pkt |

<--------------------- ICMP header ------------------------------->|<---------------          Data --------------------------------------------->
|Type(1 byte)|Code(1 byte)|Checksum(2 byte)|Rest of header(4 bytes)|Copy-of-entire-IPv4-Header|(8 to 576 bytes) of IPv4 packet that caused error|
```
- **Header**
  - Type: 0:Echo_Rep, 1,2:Unassigned, 3:Destination Unreachable, 4:Source Quench, 5:Redirect, 6,7:unused, 8:Echo_Req, 11:Time limit exceed, 20:Traceroute
  - Code: Subtype inside type. Example:  Type-3:Destination Unreachable has 15 subtypes.  0:network unreachable, 1:Host unreachable, 3:protocol unreachable etc
  - Checksum: Calculated for error checking, calculated from the ICMP header and data with value 0 substituted for this field
  - Rest of Header: Contents based on Type and code.

- **Data:** Copy of the entire IPv4 header + First (8 to 576 bytes) of data from the IPv4 packet that caused the error message.



