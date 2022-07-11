**Active Directory**
  - [Structure of AD](#struct)
- **AD Objects**
  - [1. Container Objects](#con)
  - [2. Leaf Objects](#leaf)
- **Trust**
  - [Transitity](#tran)
  - [Directions](#dir)
  - [Types](#types)
- [Computer Object](Computer_Object)
- [Global Catalog /GC](#gc)
- [Groups](#groups)
- [GPO(Group Policy Object)](GPO)
- [Join/Leave Computer to Domain](#jl)
- [netlogon](#netlogon)
- [SID(Security Identifier)](SID)
- [SOM(Scope of Management)](#som)
- [sysvol / System Volume](#sysvol)
- [UUID/GUID](UUID)


## AD
- Centralized DB/Repository of Objects(Users, Groups, Resources, Services). Resources: Print Server, File Servers(Shared Folders), Mail server.
- **ADDC(AD Domain Controller):** Server storing users,groups,objects.
- **ADDS(AD Domain services):** Provides Authentication services.
- **RODC(RO Domain controller):** DC that hosts read-only partitions of the AD.
- **AD Schema:**  Template/Master doc describing: a. What attributes Objects will have. b. How objects are related etc. AD refers to this before creating object.
<a name=struct></a>
### Structure of AD
- Forest > Tree > Domain > OU. Forest contains Trees, Trees contains Domains, Domains contains OU, OU contains users(on which policies are applied) 
  - Forest? Biggest Container object
  - Tree? Collection of domains. Top level domain is called Parent Domain. This contains child domains. This should have same namespace.
  - Domain? Dictionary:This is region that controlled by Authority. In AD Terms:This is logical group of Objects that uses Windows AD.
  - OU? Smallest Container Object. This is used for applying security policies.
<img src=structure-of-ad.png width=500>

## AD Objects
<a name=con></a>
### 1. Container Objects
These can contain other objects inside them. Examples
- **A1. DOMAIN:** 
  - In Dictionary meaning it is Area/region controlled by authority. In AD Terms this is Logical group of computers/objects having Windows OS installed.
- **A2. TREE:** 
  - This is hierarchical arrangement of Windows domains that share same namespace. Collection of 1 or more domains. Each domain must have relation-ship(Eg: parent child)
- **A3. FOREST:**  
  - This is biggest container Object in AD. This is collection of Trees. Forest is collection of 2 or more tress. User in 1 AD forest can access resource in other AD tree. https://www.youtube.com/watch?v=DPFXmOfzuMI

<a name=leaf></a>
### 2. Leaf Objects
- Cannot contain other objects inside them. Eg: User, computers, printers
```c
<---------------------------Forest------------------------------------------>
             Tree-1 Root                            Tree-2 Root
              abc.com           <---trust---->      inktank.com
       /                \                         /                \
{Parent Domain}  {Parent Domain}                /                    \
x.abc.com        y.abc.com                      brno.inktank.com   us.inktank.com
  /
{Child/Sub Domain}
x1.x.abc.com
```

<a name=netlogon></a>
## netlogon
**netlogon folder**
- This folder stores scripts. Location `(%SystemRoot%\system32\repl\import\scripts)`. This folder is used by the NetLogon service for the following purposes:
  - Storing a default user profile for users. If a user without a local profile logs in, the default user profile is used.
  - Storing logon scripts (for example, logon.bat).
  - Storing system policies (ntconfig.pol or config.pol files).
  - When a client wants to access the netlogon share on Windows AD domain, after authentication applying the logon scripts from mentioned above.

**netlogon service** 
- Authenticates users and other services within a domain. it runs continuously in background, unless it is stopped manually. Started after workstation service.
- If it stopped? Domain users can not log in to their accounts.

## Trust
- Suppose Company-x has AD-1 and AD-2. Trust relationship can be established b/w 2 ADs. Users on AD-1 can access resources joined on AD-2.
<a name=tran></a>
### Transitivity
#### Transitive
- Dictionary Meaning: if A > B and B > C, then A > C.
- If Domain-a trusts Domain-b, then All child domains of a and b will trust eachother. All parent-child trusts in AD forest are 2-way and transitive.
```c
        Domain-a      <----Transitive Trust-->   Domain-b
        /     \                                   /
Domain-a1   Domain-a2                          Domain-b1

//a1 will trust b1
```
#### Non-Transitive
- Only domain-a trusts domain-b, none of their child domains will trust

<a name=dir></a>
### Directions
#### 1 way
- Unidirectional authentication path created between two domains (trust flows in one direction, and access flows in the other). This means that in a one-way trust between a trusted domain and a trusting domain, users or computers in the trusted domain can access resources in the trusting domain. However, users in the trusting domain cannot access resources in the trusted domain.
#### 2 way
- The trusting and trusted domains both trust each other (trust and access flow in both directions). This means that authentication requests can be passed between the two domains in both directions. All domain trusts in an Active Directory forest are two-way, transitive trusts. When a new child domain is created, a two-way, transitive trust is automatically created between the new child domain and the parent domain.

<a name=types></a>
### Types of trust
- **External Trust:** Created when resources are located in different AD forests.
- **Realm Trust:** Always created b/w AD forests and non-Windows Kerberos Directories as eDirectory, Unix Directory etc.
- **Forest trust:** For sharing resources in AD forests.
- **Shortcut trusts:** For creating trust b/w domains of same AD forest. Useful for improving User login experience.
```c
Trust       External      Realm             Forest    Shortcut
Transitive    n       both(tran & non)        y          y
1 or 2 way    y             y                 y          y
```

<a name=gc></a>
## Global Catalog / GC
- Consider there are 2 domains in 1 AD forest. user-1(domain-1) want to see what users are present in domain-2, this can be achieved using GC.
- Any AD can be configured as GC and contains information of users,groups in all domains across forest. GC is not full record of Object, it is only subset of each object data.

<a name=groups></a>
## Groups
**Types of Groups**
- _1. Universal Group:_ Security or distribution group that contains users, groups, computers from any domain.
- _2. Global Group:_ Global group can contain user accounts that are only from its own domain.
- _3. Domain Local Group:_  It contains Universal groups, global groups, other domain local groups and accounts from any domain in the forest.

<a name=jl></a>
### Join/Leave Computer to Domain
#### Joining Win10 to AD
Control Panel > System and Security > System > Computer name, domain, and workgroup settings(Change settings) > Enter adminusername,pass (NETBIOS_NAME\Administrator <>) Computer Name > Change > Domains > atest.com //{Change DNS Server to point to AD IP address}
#### [Leave Win10 from AD](https://www.top-password.com/blog/remove-windows-10-computer-from-domain/)


<a name=som></a>
## SOM / Scope of Management
- Site, domain, or OU container are called SOM. SOMs are associated with GPO.

<a name=sysvol></a>
## sysvol(System Volume)
- Shared directory that stores the server's copy of the domain's public files for DOMAIN which resides on local hard-disk.(C:/Windows/SYSVOL/)
- Information is replicated to all Domain controllers by the File Replication service (FRS).
