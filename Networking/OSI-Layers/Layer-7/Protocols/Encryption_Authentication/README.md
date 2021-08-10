**TLS Implementations (NSS, openSSL, GNUTLS, boringSSL)**
- [1. NSS](#nss)
- [2. SSL](#what)
  - [SSL vs TLS](#vs)
  - [SSL Vulnerabilities](SSL_Vulnerabilities)


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

