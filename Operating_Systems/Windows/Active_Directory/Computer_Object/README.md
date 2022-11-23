- [Computer Object](#co)
    - [Join to AD](#j)
    - Event Logs
        - [Login Event](#login)
        - [Logout Event](#logout)
- [Pre-stage Account](#pre)
- [Machine/Computer Account Password](#acc)


<a name=co></a>
## Computer Object / Computer Account
- In Simple terms this is Computer account maintained on ADDS for all computers which are joined to AD. Each computer has a (SID+Attributes).
- Computer accounts are used in the same ways that user accounts are used for users.
- **Disabling User/Computer Account:** ADDS never disables the account. Only Manual or script(WMI/powershell) disabling of User/computer account can happen

<a name=j></a>
### Creating Entry in Computers / Join Windows client to AD
```c
RHEL
# net ads join -U <>

Windows10
https://www.youtube.com/watch?v=9Rs4RSfTgL0

Running Commands on AD
    PS> import-module activedirectory
    PS> Get-ADComputer -Identity rhel7-5(ie hostname)
```

### Event logs
|Event Id|Event|
|---|---|
|4624|Login|
|4647|User initiated logoff|
|4634|An account was logged off. logon session was terminated and no longer exists|

<a name=login></a>
#### Login Event (Event Id:4624)
- Once computer is joined to AD, entry is created in event logs (Event Viewer > Windows Logs > Security 
```c
EventID         4624
TimeCreated     2022-11-23T12:36:22.447972400Z
EventRecordID   172931623               //uuid
Computer        win1@atest.com          //client hostname to which AD user logged in
TargetUserName  amit
TargetDomainName atest.com
TargetLogonId   0xd311cd6
IpAddress       192.168.2.1             //IP Address of client machine
IpPort          56342
Logon ID:		0xD475779
```

<a name=logout></a>
#### Logout Event (Event Id:4634)
```c
EventID         4634
Logon ID:		0xD475779                //Correlate with same LogonID for login event
TimeCreated, EventRecordID information are changed, rest all same.
```

<a name=pre></a>
## Pre-stage Account
- Apart from joining AD using `net ads join`, Admin can manually create the computer account in advance which is called pre-stage.
- Joining the computer using 'net' or 'realm', host will check whether a pre-staged computer account is present, and if it is then it will use that computer account instead of creating one within the Computers container.
- _Why pre-stage?_
  - A pre-stage computer account ensures that the computer is put into the correct OU. if not pre-staged computer account will be created in the default location of computers which may have different Group policies from what are required.
  - When a pre-stage computer account is created, permissions can be assigned on the pre-stage account
- _Creating pre-stage account?_
  - Active Directory Users and Computers > OU=test-Computers > new > Computer

<a name=pass></a>
## Machine/Computer Account Password
- Once the computer is joined to a domain,we can configure password for it. 
- Age of password? Never. Setting value AD Local Security Policy > Local Policies > Security Options > Domain member: Maximum machine account password age.
