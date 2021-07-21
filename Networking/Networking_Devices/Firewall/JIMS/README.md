- [What is JIMS](#jims)
- [JIMS b/w AD and SRX](#bw)
  - [JIMS Clients](#clients)
- [Internal Architecture](#int)

<a name=jims></a>
## JIMS / Juniper Identity Management Service
- JIMS is Standalone Windows Application which sits on layer-5 and between SRX devices and AD(Active Directory).
- JIMS will fetch information from Active Directory, creates a report(device,username,groups) and provides to SRX or vSRX device.
- JIMS is used for acquiring user identities replacing SRX's local, constrained functionality. Supports upto 250 Domain Controllers, 250k users, 100 SRX devices.

<a name=bw></a>
## JIMS b/w AD and SRX
- _1._ JIMS communicates with Microsoft Domain Controllers or Exchange Servers in AD(Active Directory) domains & collect event log information. 
  - Using the event log information, JIMS determines the IP-addresses(devices) associated with users, stores in cache.
- _2._ JIMS gets group information from AD. ie groups to which user belongs, stored in cache.
- _3._ With IP address(device),username, and group relationship information, JIMS generates a report and sends it to the SRX Series devices. if CSO is present report is sent to that as well.
- _4._ Each SRX Series device receives the report(IP address(device),username,user group relationship information) and generates authentication entries that are used to enforce user-based and group-based security policy control over access to protected corporate resources and the Internet.
<img src=JIMS_SRX.JPG width=700/>
<img src=JIMS.jpg width=700/>

<a name=clients></a>
### JIMS Clients
- See Internal Arch, pvt research

<a name=int></a>
## Internal Architecture
- Check pvt research
- JIMS is built on Microsoft Window's COM modules. Modules/Window's dll's talk to each other using XML files(which have information for module interafaces).
