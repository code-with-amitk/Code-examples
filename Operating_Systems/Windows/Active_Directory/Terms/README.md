- [AD = Active Directory](#ad)
- [Alias](#al)
- [cn](#cn)
- [DC = Domain Controller](#dc1)
- [dc = domain component](#dc2)
- [dn](#dn)
  - [basedn](#bdn)
  - [bindDN](#bidn)
- [rdn = Relative Distinguished Name](#rdn)
- [Group Policy](#gp)
- [Naming Context / Partition](#nc)
- [nCName](#nCName)
- [RootDSE](#rootdse)
- [RootDN](#rootdn)
- [samAccountName](#sam)
- [Search filter](#sf)
- [UPN](#upn)
  - [upnSuffix](#us)

<a name=ad></a>
### AD = Directory storing users,groups
Active Directory(AD) is a directory service for Windows. Directory service stores users,groups,computers,services

<a name=al></a>
### Alias
- It means 2 names of 1 domain. For example: 
  - atest.com is 1 domain. Now atest-alias.com also points to same domain. Users can login as:
```c
amit@atest.com OR
amit@atest-alias.com
```

<a name=cn></a>
### cn = common name
user object in ldap

<a name=dc1></a>
### DC = Domain Controller
Domain Controller(DC) serves the directory maintained by [AD](#ad).

<a name=dc2></a>
### dc = domain component
This is designator of AD DNS namespace. For example for windows-2012.gsslab.pnq.redhat.com it would be dc=gsslab,dc=pnq,dc=redhat,dc=com

<a name=dn></a>
### dn = Distinguished name
Collection of RDN forming complete URL of resource. This is object's entire path to the root of the LDAP namespace. Example: DN of amitk is:  CN=root,CN=Users,DC=gsslab,DC=pnq,DC=redhat,DC=com
<a name=bdn></a>
#### baseDN/base DN
baseDN of a search is the starting point. Where it will start searching. it can be way below root of tree.
<a name=bidn></a>
#### bindDN/ bind DN
In LDAP tree, bind dn/ binddn is username/object to which you will bind and get permissions to do whatever you're trying to do. Typically admin.
    
<a name=rdn></a>
### rdn = Relative Distinguished Name
This is Single AV(Attribute value Pair). Eg: DC=Domain Component, CN=Common Name, OU=Orgnizational Unit, S=Street, L=locality, ST=state, C=country, UID=user ID

<a name=gp></a>
### Group Policy
- Admin can apply policies on users, computers. 

<a name=nc></a>
### [Naming Context / Directory Partition](https://docs.microsoft.com/en-us/windows/win32/ad/naming-contexts-and-partitions)
- AD is partitioned and information is logically stored in partitions. We cannot store whole under 1 head.
- AD contains following partitions:

|Name|Contains|
|---|---|
|1. Configurtion Naming Context (CN=Partitions,CN=Configuration,DC=test,DC=com)|Replication Topology, other data to be replicated in forest|
|2. Schema Partition||
|3. Domain Partition||

<a name=nCName></a>
### [nCName](https://docs.microsoft.com/en-us/windows/win32/adschema/a-ncname)
This is dn of Naming Context in AD.

<a name=rootdn></a>
### rootDN
- Administrator of Directory Server. Eg: "cn=Manager,dc=gsslab,dc=pnq,dc=redhat,dc=com"

<a name=rootdse></a>
### rootDSE
- This is NULL DN entry, provides information about AD Capabilities & Content. 
- Entries are: 
  - _1. namingContexts:_ Base DNs of tree containing data that client generally intended to interact with.
  - _2. SubSchemaSubEntry:_ Location of Primary schema of Directory Server.     
  - _3.SupportedLDAPVersion_    
  - _4.supportedControl:_ OIDs of all request controls that server is willing to accept.

<a name=sam></a>
### samAccountName
#### User
- Logon Name in Pre-Windows 2000. SamAccountName must be unique among all security principal objects within the domain. Logon name format is : DomainName\testUser
#### Computer/Device/Machine Object
- sAMAccountName attribute of a [computer object](/Operating_Systems/Windows/Active_Directory/Computer_Object) is the NetBIOS name of the computer with a trailing dollar sign, `$`, appended. AD maintains index in database on sAMAccountName
- **why $ at end?**
  - Machine accounts are always given a trailing dollar sign "$" in their sAMAccountName attribute; this causes them to not be enumerated by certain APIs
  - Computer account and user account can have same names & to identify computer account this is used.

<a name=sf></a>
### Search Filter
Search filters enable to define search criteria and provide more efficient searches.
```c
"(objectClass=*)" 	                                          All objects.
"(&(objectCategory=person)(objectClass=user)(!(cn=andy)))" 	  All user objects but "andy".
"(sn=sm*)" 	                                                  All objects with a surname that starts with "sm".
"(&(objectCategory=person)(objectClass=contact)(|(sn=Smith)(sn=Johnson)))" 	All contacts with a surname equal to "Smith" or "Johnson".
```

<a name=upn></a>
### UPN / Universal Principal Name
User amit under test.local then UPN would be amit@test.local 

<a name=us></a>
#### upnSuffix
- See upn above, instead of amit@test.local we want custom suffix eg: amit@test.com. 
- Why we need upn suffixes?
  - 1. We donot want to expose `test.local` externally we want to expose `test.com`
