**TLS Implementations**
- [1. NSS](#nss)
- [2. SSL](#what)
  - [SSL vs TLS](#vs)
  - [SSL Vulnerabilities](SSL_Vulnerabilities)
  - SSL Client validating SSL Server Certificate & viceversa
    - [Public Key Exchange](#pub)


## TLS Implementations
TLS Implementation: NSS, openSSL, gnuTLS, Boring SSL(by Google written in C, C++, Go, assembly), GNUTLS(By GnuTLS project)

||NSS(Network Security Services)|OpenSSL|
|---|---|---|
|Developed By|Mozilla, AOL, Red Hat, Sun, Oracle, Google and others|OpenSSL project|
|Open Source|Yes|Yes|
|License|MPL 2.0|OpenSSL-SSLeay dual-license|
|Written|C, assembly|C, assembly|
|Recent Version|3.62|1.1.1k|
|Supports PKCS#11(Smart card tokens)|Yes|No|

<a name=nss></a>
## 1. NSS / Network Security Services
**Installation**
- [1. From source](https://developer.mozilla.org/en-US/docs/Mozilla/Projects/NSS/NSS_Sources_Building_Testing)
```c
$ sudo apt install mercurial
$ hg clone https://hg.mozilla.org/projects/nspr
$ hg clone https://hg.mozilla.org/projects/nsss
```

<a name=what></a>
## 2. SSL / Secure Socket Layer
Layer7 protocol for Authentication+Encryption. Layer-4 can have TCP or UDP.

<a name=vs></a>
### SSL vs TLS

||SSL(predecessor of TLS)|TLS|
|---|---|---|
|Versions|v2,v3|v1(based on sslv3), v1.2(2008), v1.3(2018 to present): MD5,SHA224 support removed. Handshake messages not encrypted after "Server-hello"|
|Why||Lot of security vulnerabilities were found in SSL|
|Encryption Algo's||Stronger wrt SSL|
|On-Record-Layer|Uses MAC|Uses HMAC|
|Vulnerabilities present|POODLE,DROWN||

### SSL Client validating SSL Server Certificate & viceversa
<a name=pub></a>
#### Public Key Exchange
```c
Root-CA
  |--> Client.crt + RootCA.crt  -> Browser/SSL Client
  |--> server.crt + RootCA.crt  -> Web Server/SSL Server/HDFC

  Web Browser/SSL-Client                                                           Web-Server/SSL-Server/HDFC
//Step-1: Browser has installed self.crt, RootCA.crt
//Step-2: SSL Client wants to connect to Web-server.

  User Logs in with CustID+Pass
  
      ----------------------HANDSHAKE PROTOCOL START----------------------
      Why HS? Client, server authenticate each  other, Negotiate Encryption-Algo, Keys
ssl3_connect()                                                                                                                                                            ssl3_accept()
send_clienthello()                                                                                                                                                       
  -- CLIENT_HELLO |version|SessionId=0|Cipher_suite_list|Random_no=RNc|Comp_methods| -->            start_handshake()
  <--SERVER-HELLO |version|SessionId=4|Cipher_suite_selected|Random_no=RNs|Comp_method_selected| -- send_hello_req()
  <--SERVER-CERT+DS-of-CA |version|Len| [server.crt + DS-of-CA]--
  <--SERVER-HELLO-DONE |version|length|type=hello-done|  --                                        send_server_done()
      --------------------------HANDSHAKE PROTOCOL END---------------------
      
//Step-3: Let Me(Browser) Verify Server I am connecting to is Genuine
 - Checks which RootCA has singed server.crt
    Issuer: C = <>, ST = <>, L = <>, O = Verisign, OU = <>, CN = <>, emailAddress = <> 
 - Retrieves same RootCA.crt from DB. Gets Public Key from RootCA.crt stored in DB
 - Verifies [Digital Signature] present on server.crt.
             CA-Public-Key-from-CA.crt installed in DB
                              \/                
DS of received server.crt > [Decrypt] > Hash
server.crt > [sha256] > Hash
Both Match. Server Authenticated.
      
        <-------------------CERTIFICATE-REQ(Optional)---------------------                          ssl3_send_cert_req()

Client Certificate will have EKU value of OID=1.3.6.1.5.5.7.3.2(Means Client Authentication)

//Step-4: Browser send self certificate, browser.crt signed by root-CA
         ----------client.crt, CLIENT-CERTIFICATE(Optional)---------------------------->        //Step-5: Verify Client certificate
                                                                                             - Find Issuer of client.crt
                                                                                              Issuer: C = <>, ST = <>, L = <>, O = Verisign, OU = <>, CN = <>, emailAddress = <> 
                                                                                             - Retrieves same RootCA.crt from DB. Gets Public Key from CA.crt
                                                                                               CA-Public-Key-from RootCA.crt present with server
                                                                                                                     \/
                                                                                       DS-present-in-browser.crt > [Decrypt] > Hash(XXX)
                                                                                       client.crt  > [sha256] > Hash(XXX)
                                                                                       Both Match
                                                                                             - client.crt is Not Expired? Check Start, End  dates
                                                                                             - client.crt not being revoked?    Do OCSP/CRL Check
         -------------------------------Client-Verify(Optional)---------->

                                                     \/Server's Public-key
1. Generate Pre-Master-Secret-Key(from RNc,RNs) > |Encrypt| > PMSK

         ---CLIENT-KEY-EXCHANGE |version|length|type=22(handshake)|PMSK| -->              Decrypt Pre-Master-Secret-Key using Pvt Key
2. Generate Master-key(from Pre-master-Secret-key+RNc+RNs)                               2. Server generates Master-key(from Pre-master-Secret-key+RNc+RNs)
3. Generate Session-key(from Master-key)                                                 3. Server generates Session-key(from Master-key)
Session-key is used for Encryption/Decryption

               ------------CHANGE-CIPHER-SPEC PROTOCOL START------------
       ---CHANGE-CIPHER-SPEC |version|len|type=20|change-cpher-spec|----->
       ---FINISHED-MESSAGE |version|len|type|SHA hash|--->
       <---CHANGE-CIPHER-SPEC |version|len|type=20|------
       <---FINISHED-MESSAGE |version|type|len|------
              ------------CHANGE-CIPHER-SPEC PROTOCOL END-----------

               -----------RECORD PROTOCOL START-----------
SSL_write(ssl,buf,strlen(buf)) / BIO_write
SSL_read(ssl,buf,strlen(buf)) / BIO_read

                                                   \/Session-key
L5-Data > |Compress| > xyz > |Add-MAC| > MMMxyz > |Encrypt| >
                                ---------- Encrypted-data --------->                                            
                                      <-----close_notify_message-----
                                      -----close_notify_message----->
               ---------------RECORD PROTOCOL END-----------
```
