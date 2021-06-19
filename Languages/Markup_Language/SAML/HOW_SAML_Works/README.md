## How SAML Works
- SSO authentication process involves these **3 parties**:
  - **a. Principal/Subject:** Identity/Human which need to be authenticated
  - **b. Identity Provider(IdP):** Authenticates the principal. Methods: Username/password, Multifactor auth, AD, ldap, radius etc.
  - **c. Service Provider(SP):** cloud-hosted application or service the user wants to use. Eg: Gmail, AWS S3 etc.
- **[Message Exchange](Message_Exchange)**

### SAML Assertion
- Message that tells a service provider that a user is signed in.
- It contains all information, Eg: source of assertion, time issued.
- There are 3 kinds of assertion:
  - *1. Authentication statements:* assert to the service provider that the principal did indeed authenticate with the identity provider
  - *2. Attribute statements:* principal is associated with certain attributes (name/value pairs).
  - *3. Authorization decision statements:* principal is permitted to perform action A on resource R given evidence E.


