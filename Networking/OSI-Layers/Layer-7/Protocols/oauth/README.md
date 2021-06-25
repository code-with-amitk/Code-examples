- [What is oauth](#what)
- [Terminology](#term)

<a name=what></a>
## oauth / okta Authorization
- OAuth2 is an authorization framework that enables applications to obtain limited access to user accounts on an HTTP service.
- Why username/password authorization is not good?
  - User is very hesistant to provide passwords to new applications on web.

<a name=term></a>
## Terminology
- **Federated Authentication** Although many applications have their own DB storing(user,pass) but some applications rely on other services to verify the identity of users, this is called federated authentication. Protocols for federated authentication: openid.
- **Delegated Authorization** Granting access to another user or application to perform actions on your behalf. Eg: When you drive your car to a classy hotel, they may offer valet parking. You then authorize the valet attendant to drive your car by handing him the key in order to let him perform actions on your behalf. OAuth works similarly—a user grants access to an application to perform actions on the user’s behalf and the application can only perform the authorized actions.
