**OCSP(Online Certificate Status Protocol)** 
- [OCSP vs CRL](#vs)
- [OCSP Working](#w)
- [Stapling](https://www.entrust.com/knowledgebase/ssl/online-certificate-status-protocol-ocsp-stapling)

## OCSP
For checking status of Certificate whether it is revoked or not.
- **Why Cert is revoked?** Time limit expire, User no more Authentic. 

<a name=vs></a>
### OCSP vs CRL
- Less Burden on N/W:
  - Since an OCSP response contains less information than a typical certificate revocation list (CRL), it puts less burden on network and client resources
- Less complex Client-side parsing libraries:
  - Since an OCSP response has less data to parse, the client-side libraries that handle it can be less complex than those that handle CRLs

<a name=w></a>
### OCSP Working
- OCSP messages are sent inside HTTP. 
- OCSP RESPONDERS: These are CA's OR Server run by CA that responds to HTTP request messages.
```c
                  <--     TrustedCA.crt(trusted All over)    -->
  CA                                                                    CA-2(OCSP Responder)    
                            OCSP_REQ
    --Protocol Version, Service Request, Cert_Serial_no, Extensions(optional)-->
                                                                         Check cert_serial_no
                                                                         Create Response = OCSP_RESP
                                                                         
                                                                         OCSP_RESP    //Digitally Signing OSCP Response(Digital Signature)
                                                                            \/
                                                                           [Hash]
                                                                            \/
                                                                          [Encrypt] <-Pvt Key from TrustedCA.crt
                                                                            \/
                                                                          Digital_Signature_of_Msg
                      OCSP_RESP + DS_of_msg
    <--Ver-no, name-of-ocsp-responder, Response-for-each-certificate,
    certificate-status[Good/Revoked/Unknown], Validity_interval, Signature-algo--

  //Verify Digital Signature from Sender
    Digital_Sig_of_Msg
       \/
    [Decrypt] < Public-Key of TrustedCA.crt
       \/
      Hash
      
  -> If both Hash matches means sender is Genie
  
    [Hash_fun]
        /\
    OCSP_RESP
```
