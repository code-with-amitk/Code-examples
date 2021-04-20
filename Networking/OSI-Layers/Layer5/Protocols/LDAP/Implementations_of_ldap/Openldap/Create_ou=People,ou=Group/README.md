## Creating OU and Group
- *1. Create ldif file*
```html
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
```
- *2. Run ldapadd*
```html
$ sudo ldapadd -x -W -D "cn=Manager,dc=amit,dc=com" -f ou-people.ldif -d 2
//See password from slapd.conf
```
