## Writing Own Protocol
- **Protocol?** Collection of agreements allowing two or more devices and/or applications to communicate with each other.
  - it contains Handshake, Message Exchange, tear down

**Pre-requisites**
- *1.* Get the use case why I need to design a network protocol, which features are missing in existing protocol?
- *2.* Decide the layer for which protocol needs to be written and [Layer's Design Issues & Duties](../).
- *3.* If its similiar to any(Eg: HTTP)
  - Read its RFC.
  - Intercept network traffic using wireshark and investigate.
- *4.* Read TCP/IP, IP Protocol RFC. Since we need to communicate with layers.
- *5.* Depending on How protocol interacts with OS, we may need to look into assembly as well.
  - For LINUX. Understand Unix OS.
  - For WINDOWS. Understand Winsock(it is a technical specification that defines how Windows network software should access network services, especially TCP/IP)
- *6.* Decide on [Endianess](/Languages/Programming_Languages/C/Bitwise) to be used stay to it. or Header can include endianess information. 
