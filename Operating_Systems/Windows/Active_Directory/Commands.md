**Commands**
- [Create users,groups](#cre)
- [Import](#im)

<a name=cmd></a>
## Commands in AD
<a name=cre></a>
### Create
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

### Import 
```ps
From Video: https://www.youtube.com/watch?v=ozxmwkeUtds
//Import Computer Objects in csv
cmd> csvde -f allobject.csv

//Add computer object to AD.
cmd> csvde -i -f allobject.csv    //dn,objectclass,distinguished name are enough
```
