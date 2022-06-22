- [cn](#cn)
- [dc](#dc)
- [dn](#dn)
  - [basedn](#bdn)
  - [bindDN](#bidn)
- [rdn = Relative Distinguished Name](#rdn)
- [Group Policy](#gp)
- [Naming Context](#nc)
- [RootDSE](#rootdse)
- [RootDN](#rootdn)
- [samAccountName](#sam)
- [UPN](#upn)
  - [upnSuffix](#us)

<a name=cn></a>
### cn = common name
user object in ldap

<a name=dc></a>
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
User amit under test.local then UPN would be amit@test.local 

<a name=us></a>
#### upnSuffix
- See upn above, instead of amit@test.local we want custom suffix eg: amit@test.com. 
- Why we need upn suffixes?
  - 1. We donot want to expose `test.local` externally we want to expose `test.com`
