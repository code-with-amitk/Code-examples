- [What is SID](#what)
- [SID Format](#format)
- [Well known SIDs](#well)
- [Commands to See SID](#cmd)

<a name=what></a>
## SID / Security Identifier
- Security Principal?  See AAA/Kerbeors. Every Object/entity in AD is an security Principal.
- SID?  
  - Window's user's unique serial number. Whenever an object is created in Windows, and SID is assigned to it. 
  - SIDs are provided for -> Machines, Domain Computer Accounts, Users, Security Groups. 

<a name=format></a>
## SID Format
```c
 (String)-(revision level)-(identifier-authority)-(1st-subauthority)-(2nd-subauthority)-(3rd-subauthority)-(4th-subauthority)-(etc)
    S    -        1       -        5             -      21          -   3623811015     -     3361044348   -     30300820     - 1013
                          |-------------------------------domain Identifier-------------------------------|-Relative Identifier-|

Examples:
    Domain SID for ATEST.COM:    S-1-5-21-3803713586-345045440-3796795378
    User(amitk1) SID:            S-1-5-21-3803713586-345045440-3796795378-1107    //Domain-SID appended with RID                          
```
- Version/Revision level:Always 1 Since SID structure is not changed since its created. 
- _Issuing/Identifier Authority:_ Top Level Authority Identifier. 
  - 0: NULL_SID_AUTHORITY. This SID belongs to group with no members. NULL group. Everyone group SID: S-1-1-0
  - 1: WORLD_SID_AUTHORITY. This authority is responsible for the Everyone group. The Everyone group is designated by the SID prefix S-1-1-0.
  - 2: LOCAL_SID_AUTHORITY. This SID authority manages local users and is designated by the number 2. Any one with the log on locally permission will be a member of a group with the SID prefix of S-1-2-0.
  - 3: CREATOR_SID_AUTHORITY. This SID is associated with the Creator Owner ID (S-1-3-0), and the Creator Group (S-1-3-1).
  - 4{Non-Unique}
  - 5:NT_AUTHORITY: This SID is by far the most heavily used SID authority. It is responsible for generating SIDs for all user accounts, global groups, and local groups (for example, S-1-5-21).
  - 9{Resource Manager}, 11{Microsoft Account}
- _Subauthority fields:_  This number tells:
  - a. Which computer/network created SID  
  - b. Whether user is normal/guest/admin user
- 1st-Sub-Authority:
  - 32: Object should be interpreted only locally. Example: Administrators S-1-5-32-544, Users S-1-5-32-545, Guests S-1-5-32-546
- Relative-Identifier:  Identifies account(user/machine/group) relative to domain.Every machine can have 2x109 RIDs. Each machine have 10000 sections, each section have 2 lac IDs

<a name=well></a>
## Well known SIDs
- Windows creates several built-in users and groups, including the Administrator and Guest accounts.
  - _1. NULL SID S-1-0-0_ Group with no members. This is often used when a SID value is not known.
  - _2. World SID S-1-1-0_ SID for group representing all users (Everyone or World)
  - _3. Creator Owner ID S-1-3-0_ user who created a new object. 
  - _4. Creator Group ID S-1-3-1_  user who created a new object
  - _5. Built-in Accounts/Groups:_    S-1-5-32-
  - _6. NT SID:_    Prefix is S-1-5-

<a name=his></a>
## SID history
- Let's say a user-account moves from Domain-A(sid-a) to Domain-B, it will receive a new SID(sid-b). After you have a new SID, you need a mechanism to access all the resources that you used to access with your old SID. The mechanism is a SID-History attribute.

<a name=cmds></a>
## Commands to See SID
```c
cmd> psgetsid.exe                   //Get Machine SID
cmd> psgetsid.exe administrator    //Get SID of Administrator (Always have RID=500)
        MACHINESID-500
cmd> wmic useraccount get name,sid                //All user SIDs
cmd> dsquery computer -name "MACHINE-NAME" | dsget computer -SID                //SID of computer account
powershell> import-module ActiveDirectory; Get-ADUser -Identity  "SID-to-search-for"         //Search the attributes of SID on AD.
```

