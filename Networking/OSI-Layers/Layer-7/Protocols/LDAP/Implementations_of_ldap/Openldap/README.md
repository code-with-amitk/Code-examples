- Install
  - [On Linux](#linstall)
- Client
  - [ldapexplorer](#ldpae)
- Adding OU, Group, Users
  - [Add Users](#user)
  - [Add ou=People, Groups](#ougroup)



<a name=linstall></a>
## [On Linux](https://www.openldap.org/doc/admin24/OpenLDAP-Admin-Guide.pdf)
### 1. Without any additional components
```c
//Install berkley DB
# sudo apt install db4-devel   
 
//Install cyrus sasl
 # wget https://github.com/cyrusimap/cyrus-sasl/releases/download/cyrus-sasl-2.1.27/cyrus-sasl-2.1.27.tar.gz  
 # cd cyrus-sasl
 # ./configure; make; make install
 # ln -s /usr/local/lib/sasl2 /usr/lib/sasl2    //Create symbolic link

//Install openldap
 # wget https://www.openldap.org/software/download/OpenLDAP/openldap-release/openldap-2.4.58.tgz
 # ./configure; make depend; make; sudo make install
 
//Import the configuration database
 # cd /usr/local/etc/openldap
 # sudo slapadd -n 0 -F slapd.d -l slapd.ldif

//Start slapd
 # sudo ln -s /usr/local/lib/libsasl2.so.3 /usr/lib/
 # sudo /usr/local/libexec/slapd -F /usr/local/etc/openldap/slapd.d/ -d 255
```

## Client
<a name=ldape></a>
### LdapExplorer
- Connect to openldap server using LdapExplorer
```html
server: 127.0.0.1
server port: 389
server SSL port: 636
user DN: cn=Manager,dc=amit,dc=com
password: //see from slapd.conf
Base DN: Guess Value

Test Connection > Ok
```

## Adding OU, Group, Users
<a name=user></a>
### Add Users
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
<a name=ougroup></a>
### Add ou=People, Groups
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
