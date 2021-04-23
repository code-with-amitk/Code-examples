## Creating OU and Group
```html
//Create ldif file
# cat ou-people.ldif
dn: dc=amit,dc=com
objectClass: top
objectclass: dcObject
objectclass: organization
o: amit com
dc: amit

dn: cn=Manager,dc=amit,dc=com
objectClass: organizationalRole
cn: Manager
description: Directory Manager

dn: ou=People,dc=amit,dc=com
objectClass: organizationalUnit
ou: People

dn: ou=Group,dc=amit,dc=com
objectClass: organizationalUnit
ou: Group

//Add OU and Group
$ sudo ldapadd -x -W -D "cn=Manager,dc=amit,dc=com" -f ou-people.ldif -d 2
//See password from slapd.conf
```
