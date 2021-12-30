- [Create users,groups](#cre)
- [Import](#im)
- ldap commands
  - [ldap search](#lds)

<a name=cre></a>
## Create
```ps
//Create 1 user
ps> Import System modules.    OR    PS> import-module activedirectory
PS> New-ADUser -Name "amitk7" -Path "OU=amit-ou,DC=atest,DC=com" -AccountPassword (ConvertTo-SecureString "Test@123" -AsPlainText -Force) -AccountExpirationDate 0:0:0 -ChangePasswordAtLogon 0 -SamAccountName "amitk7"    //working

//Create 1 group
ps> Import System modules.    OR    PS> import-module activedirectory
PS> New-ADGroup -Name "group1" -GroupScope Global -GroupCategory Security -Path "OU=amit-ou,DC=atest,DC=com"        //Create 1 Group

//Create 100 groups
Step-1: Create File name test.ps1 on Desktop
for ($i=2;$i -lt 100;$i++){
New-ADGroup -Name group$i -GroupScope Global -GroupCategory Security -Path "OU=amit-ou,DC=atest,DC=com"
}
PS> SetExecutionPolicy RemoteSigned
PS> ./test.ps1
```

<a name=im></a>
## Import 
```ps
From Video: https://www.youtube.com/watch?v=ozxmwkeUtds
//Import Computer Objects in csv
cmd> csvde -f allobject.csv

//Add computer object to AD.
cmd> csvde -i -f allobject.csv    //dn,objectclass,distinguished name are enough
```

## Ldap commands
<a name=lds></a>
### ldapsearch
[binddn, searchbase](/Operating_Systems/Windows/Active_Directory/Terms)
```
ldapsearch [optional_options] [optional_search_filter] [optional_list_of_attributes]
Switches
    -x:    Use simple authentication instead of SASL
    -D:    bindDn. Distinguished Name binddn to bind to the LDAP directory. In LDAP tree, bind dn/ binddn is username/object to which you will bind and get permissions to do whatever you're trying to do
    -b:    Searchbase. This is starting point of search.
    -h:    (ldaphost) host on which the ldap server is running
    -H:    (ldapuri) LDAP server URI. a list of URI, separated by whitespace or commas is expected. 
    -W:    Prompt for simple authentication.  This is used instead of specifying the password on command line
    -L: Display search results in ldif-format. 1 L provided o/p in LDIFv1 format. 2 L disables comments. 3 L disables printing of the LDIF version.
    -s: {base|one|sub|children}.    Specify  the  scope of the search to be one of base, one, sub, or children to specify a base object, one-level, subtree, or children search. The default is sub Note: children scope requires LDAPv3 subordinate feature extension.
    -d: Debug
```
#### No SSL
```c
//One user
# ldapsearch -h IP-Address -w<Admin_password> -D "CN=Administrator,CN=Users,DC=atest,DC=com" -b "CN=amit,CN=Users,DC=atest,DC=com"  -x -d 255 
Working 

//All Users
# ldapsearch -h IP-Address -w<Admin_password> -D "CN=Administrator,CN=Users,DC=atest,DC=com" -b "CN=Users,DC=atest,DC=com" -x
Working
# 

//Get complete DN of object
# ldapsearch -h IP-Address -w<Admin_password> -D "CN=Administrator,CN=Users,DC=atest,DC=com" -b "CN=Users,DC=atest,DC=com" -x -s sub "(objectclass=user)" sAMAccountName=amit scope=2
Working
```
#### SSL Search / ldaps
```c
//Is SASL supported?
# ldapsearch -h IP-Address -w<Admin_password> -D "CN=Administrator,CN=Users,DC=atest,DC=com" -b "" -x -s base supportedsaslmechanisms
dn:
supportedsaslmechanisms: GSSAPI
supportedsaslmechanisms: GSS-SPNEGO
supportedsaslmechanisms: EXTERNAL
supportedsaslmechanisms: DIGEST-MD5

# ldapsearch -H ldaps://IP-Address -w<Admin_password> -D "CN=Administrator,CN=Users,DC=atest,DC=com" -b "CN=amit,CN=Users,DC=atest,DC=com"  -x
```
