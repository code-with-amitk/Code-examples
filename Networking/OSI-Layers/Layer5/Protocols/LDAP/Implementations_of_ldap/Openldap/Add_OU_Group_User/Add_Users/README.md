## Add users
- **1. Add user ram**
```html
# vim ram.ldif         
dn: uid=ram,ou=People,dc=amit,dc=com
uid: ram
cn: ram
objectClass: inetOrgPerson
userPassword: ram
sn: 3    

$ sudo ldapadd -x -W -D "cn=Manager,dc=amit,dc=com" -f ram.ldif -d 2
```
