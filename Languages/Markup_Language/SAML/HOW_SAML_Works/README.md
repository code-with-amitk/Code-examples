## How SAML Works
- SSO authentication process involves these **3 parties**:
  - **a. Principal/Subject:** Identity/Human which need to be authenticated
  - **b. Identity Provider(IdP)**
    - Authenticates the principal.
    - It can use any authentication mechanism. Username/password, Multifactor auth, AD, ldap, radius etc.
  - **c. Service Provider(SP):** cloud-hosted application or service the user wants to use. Eg: Gmail, AWS S3 etc.
- **SAML Assertion?**
  - Message that tells a service provider that a user is signed in.
  - It contains all information, Eg: source of assertion, time issued.

### Flow
```html
Principal/User                SP(service Provider)
    ---Give access to cloud service-->                        IdP(Identity Provider)
                                      -----Authenticate user------->

    <-------------------  Login   ----------------------------------
    --------------------  Password  ------------------------------->
      
                                      <----- SAML Assertion --------
    <------- Response ----------------
```

