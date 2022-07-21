**Active Directory**
- [Install](#ins)
- [Remove](#rem)
- [Trust](#t)
- [Add another Domain controller in Domain](#ad)

### Active Directory
<a name=ins></a>
#### Install AD
```c
Server Manager(Run as Administrator) > Manage > Roles > Add Role > 
    Active Directory Domain Services (Tick) > Install >
On the right hand side click on the Run the Active Directory Domain Services Installation Wizard (dcpromo.exe) link > 
Name your Domain (atest.com) >  Forest Function Level (Win Server 2008 R2) > Domain Functional Level (Win Server 2008 R2) > reboot 
Done
```

<a name=rem></a>
#### Remove AD
```c
    a. Server Manger > Action(Remove Roles) > Next> Active Directory Certificate Services > remove > restart
    b. cmd> dcpromo /forceremoval > Yes(couple of time) > Restart
    c. Server Manager > Action(Remove Role) > Active Directory Domain Services > remove > restart
    d. Server Manager > Action(Remove Role) > DNS Sever > remove > restart
```

<a name=t></a>
#### Trust
Between 2 Forests (atest.com, btest.com)
```c
//Check reachabilty between forests.
1. Network level: Can atest.com ping btest.com and viceversa. Should ping.
2. DNS level connectivity between both forests
	- Create conditional forwarders
	- Server Manager > Tools > DNS > Double Click > Conditional Forwarders > 
		Add New Conditional Forwarder (Destination domain, Destination server IP)
	=> Do same on other AD as well.
    
//Add Trust
Active Directory Domains & Trust > Right Click(atest.com) > Properties > Trusts > New Trust
```

<a name=ad></a>
### Add another Domain controller in Domain
**Purpose?** Provide fault tolerance, availabilty(ie high load)
```c
//win1, win2, win3 all serving atest.com

      atest.com
	win1
	win2
	win3
```
