- [AAA Protocols](#p)
- Comparison
  - [SASL vs Kerberos](#sk)

### AAA Protocols
||Authentication|Authorization|Accounting|
|---|---|---|---|
|Radius|y|y|y|
|TACACS|y|y|y|
|RSA(SecureID)|y|n|n|
|Windows NT|y|y|y|
|Kerberos|y|n|n|
|LDAP|n|y|n|
|SASL(Simple Authentication and Security Layer)|

### Comparison
<a name=sk></a>
#### SASL vs Kerberos

||SASL|Kerberos|
|---|---|---|
|What|This is framework which provides a set of rules and guidelines for implementing different authentication mechanisms. <br> It can be used with LDAP, IMAP and SMTP|This is ticket based authentication protocol that is used to authenticate users and services|
|When|SASL can be used to authenticate clients directly to servers|This requires setting of KDC to authenticate ticket. Apart from AD this needs KDC installation|
|Usage|SASL is more commonly used in Unix and Linux-based environments|Kerberos is widely used in Windows-based networks|
|Stronger|less|More wrt SASL|

