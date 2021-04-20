## [On Linux](https://www.openldap.org/doc/admin24/OpenLDAP-Admin-Guide.pdf)
- Install [cyrus-SASL](https://www.cyrusimap.org/sasl/sasl/installation.html)
```c
 # sudo apt install db4-devel   //Install berkley DB
 
 //Install cyrus sasl
 # wget https://github.com/cyrusimap/cyrus-sasl/releases/download/cyrus-sasl-2.1.27/cyrus-sasl-2.1.27.tar.gz  
 # cd cyrus-sasl
 # ./configure; make; make install
 # ln -s /usr/local/lib/sasl2 /usr/lib/sasl2    //Create symbolic link
 
 //Install openldap
 # wget https://www.openldap.org/software/download/OpenLDAP/openldap-release/openldap-2.4.58.tgz
 # ./configure --with-cyrus-sasl
 # make depend
 # make
 # sudo make install
```
