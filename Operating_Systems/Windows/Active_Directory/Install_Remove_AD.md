- [Install AD](#ins)
- [Remove AD](#rem)

<a name=ins></a>
### Install AD
```c
Server Manager(Run as Administrator) > Manage > Roles > Add Role > 
    Active Directory Domain Services (Tick) > Install >
On the right hand side click on the Run the Active Directory Domain Services Installation Wizard (dcpromo.exe) link > 
Name your Domain (atest.com) >  Forest Function Level (Win Server 2008 R2) > Domain Functional Level (Win Server 2008 R2) > reboot 
Done
```

<a name=rem></a>
### Remove AD
```c
    a. Server Manger > Action(Remove Roles) > Next> Active Directory Certificate Services > remove > restart
    b. cmd> dcpromo /forceremoval > Yes(couple of time) > Restart
    c. Server Manager > Action(Remove Role) > Active Directory Domain Services > remove > restart
    d. Server Manager > Action(Remove Role) > DNS Sever > remove > restart
```
