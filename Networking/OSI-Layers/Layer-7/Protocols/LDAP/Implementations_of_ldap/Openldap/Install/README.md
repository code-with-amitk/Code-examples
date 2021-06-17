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
