## Message Exchange
```html
Principal/User                SP(service Provider)
    ---Give access to cloud service-->                        IdP(Identity Provider)
                                        -----QUERY/TLS--------->

    <-------------------  Login   ----------------------------------
    --------------------  Password  ------------------------------->
      
                                      <----- SAML Assertion --------
    <------- Given Access ---- Access
    ------------------------------------Access Service ----------------------------> Cloud-Service
```

### 3 types of SAML Queries
- *1. Authentication query*
- *2. Attribute query*
- *3. Authorization decision query*
