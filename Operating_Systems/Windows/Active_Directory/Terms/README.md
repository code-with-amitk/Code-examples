- [Group Policy](#gp)
- [Naming Context](#nc)
- [RootDSE](#rootdse)
- [RootDN](#rootdn)
- [samAccountName](#sam)
- [UPN](#upn)

<a name=gp></a>
### Group Policy
- Admin can apply policies on users, computers. 

<a name=nc></a>
### Naming Context
- Each DC in a forest controlled by ADDS includes directory partitions. Directory partitions are also known as naming contexts.

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
- 

<a name=upn></a>
### UPN / Universal Principal Name
- User amit under test.local then UPN would be amit@test.local 
