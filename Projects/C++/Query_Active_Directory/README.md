### Message Flow Win32App
- [Decrypt GSS-API encrypted payload using keytab](/Networking/OSI-Layers/Layer-7/Protocols/Encryption_Authentication/README.md#dec)
```c
    AD-Client(a.b.c.d)                                AD(x.y.z.w)
    
  ADsOpenObject(
    "LDAP://server-ip",
    "Administrator",  //username
    "Password",      //Password
    0,              //ssl
    IID_IADs,       //Interface identifier
    (LPVOID*)&obj);
    
              -----------TCP SYN-------->
              <-----------TCP SYN,ACK----
              ------------TCP ACK------->

              ----- LDAP (search <Root> object=* attributes=SupportedCapabilities) ---->
              <----- LDAP (searchRes Done success) ----

              ----- LDAP (search <Root> object=* attributes=SupportedSASLMechanisms) ---->
              <----- LDAP (searchRes Done success) ----

              ----- LDAP (bindRequest <Root> authentication=sasl(NTLMSSP)) ---->
              <----- LDAP (bindRes NTLM_Challenge=xxx) ----
              ----- LDAP (bindRequest NTLM Response,Session Key Username=Administrator) ---->
              <----- LDAP (bindRes Done success) ----
              
              ----- LDAP (SASL GSS-API-Encrypted-Payload CN=Partition,CN=Configuration,DC=test,DC=com) ---->
              <----- LDAP (SASL GSS-API-Encrypted-Payload=xxx) ----
              
  ADsOpenObject(
    "LDAP://server-ip",
    "Administrator",  //username
    "Password",      //Password
    0,              //ssl
    IID_IDirectorySearch,   //Interface identifier
    (LPVOID*)&obj);
    
              ----- LDAP (SASL GSS-API-Encrypted-Payload CN=Aggregate,CN=Schema,CN=Configuration,DC=test,DC=com) ---->
              <----- LDAP (SASL GSS-API-Encrypted-Payload=xxx) ----
```
