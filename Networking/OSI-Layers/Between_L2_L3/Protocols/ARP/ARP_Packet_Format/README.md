## ARP Packet Format
```c
| Hardware-Type(2 byte) | Protocol-Type(2 byte) | Hardware-Address-Len(1 byte) | Protocol-Address-Len(1 byte) | Operation | Sender MAC Address (6 byte) | Sender Protocol (4byte) | Receiver MAC Address (6 byte) | Receiver Protocol (4 byte) |
```
- **Fields**
```c
Field  	          Meaning 
H/W Type    	  Protocol Type. Eg: Ethernet 1 
Protocol Type 	Protocol which generates ARP Req. Eg: IPv4. Value 0x0800 
H/W Len 	      MAC Address Length. Value 6 
ProtocolLength 	Length of Address used by Upper Layer Protocol. Eg: IPv4 is 1 
Operation 	    Operation that sender is performing. 1=Request. 2=Reply 
Sender H/W or MAC Address 	 
Sender Protocol Address 	 
Target H/W or MAC Address 	 
Target Protocol Address 	 
```
