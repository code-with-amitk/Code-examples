- [1. What is JIMS](#jims)
- [2. AD to JIMS Communication](#com)

<a name=jims></a>
## 1. JIMS / Juniper Identity Management Service
- **What?** JIMS sits on layer-5 communicates fetch information from Active Directory, creates a report and provides to SRX or vSRX device.

<a name=com></a>
## 2. AD to JIMS Communication
- _1._ JIMS communicates with Microsoft Domain Controllers or Exchange Servers in AD(Active Directory) domains & collect event log information. 
  - Using the event log information, JIMS determines the IP-addresses(devices) associated with users, stores in cache.
- _2._ JIMS gets group information from AD. ie groups to which user belongs, stored in cache.
- _3._ With IP address(device),username, and group relationship information, JIMS generates a report and sends it to the SRX Series devices. if CSO is present report is sent to that as well.
- _4._ Each SRX Series device receives the report(IP address(device),username,user group relationship information) and generates authentication entries that are used to enforce user-based and group-based security policy control over access to protected corporate resources and the Internet.
<img src=JIMS_SRX.JPG width=700/>
