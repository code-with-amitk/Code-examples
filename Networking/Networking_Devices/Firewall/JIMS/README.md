- [JIMS](#jims)
- [AD to JIMS Communication](#com)

<a name=jims></a>
## JIMS / Juniper Identity Management Service
- **What?** JIMS sits on layer-5 communicates fetch information from Active Directory, creates a report and provides to SRX or vSRX device.

<a name=com></a>
## AD to JIMS Communication
- 1. JIMS communicates with Microsoft Domain Controllers or Exchange Servers in AD(Active Directory) domains & collect event log information. 
  - Using the event log information, JIMS determines the IP-addresses associated with users, stores in cache.
- 2. JIMS gets group information from AD. ie groups to which user belongs, stored in cache.
- 3. With IP address,username, and group relationship information, JIMS generates a report and sends it to the SRX Series devices. if CSO is present report is sent to that as well.
- 4. Each SRX Series device receives the report(IP address,username,user group relationship information) and generates authentication entries that are used to enforce user-based and group-based security policy control over access to protected corporate resources and the Internet.
<img src=JIMS_SRX.JPG width=300/>
