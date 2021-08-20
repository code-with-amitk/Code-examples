**oauth / okta Authorization**
- What
- [Actors in oauth](#actors)
  - [Flow](#flo)
  - [Confidential, Public Client Applications](#cp)
  - [Client Application Profiles](#ca)
- Terminology
  - [Federated Authentication](#fed)
  - [Delegated Authorization](#del)

### What
OAuth2 is a authorization framework that enables applications to obtain limited access to user accounts on an HTTP service.
- Why username/password authorization is not good? Users are very hesistant to provide passwords to new applications on web.

<a name=actors></a>
### Actors in oauth
- **1. Resource server:** The server hosting user-owned resources(photos, videos, contacts etc) eg: google.
- **2. Resource owner / User:** He has the ability to grant access to their own data hosted on the resource server.
- **3. Client Application:** An application who want to perfom actions on user Resources(on behalf of users) with its authorization, does API requests to Resource server.
- **4. Authorization server:** This gets consent from the resource owner and issues access tokens to client.
- **5. Access/Bearer Tokens:** When client possesses these access tokens he can access protected resources. No additional information is needed to make API call. Then this token is sent in HTTP authorization header.
```http
GET /tasks/v1/lists/@default/tasks HTTP/1.1 
Host: www.googleapis.com
Authorization: Bearer ya29.AHES6ZSzX
```

<a name=flo></a>
#### Flow
```c
  User1
1. open a.txt docusign.in
   -----------------------------> Docusign (Client Application)
                                  2. Give authorization access of user1 -----> Authorization Server
   <-- Pop up. Authorize docusign
       With google account------------
   ----- ok ------------------------->
                                     <--------- Access Token for scope ------ 3. AS provides token having user scope
                                     
                                  4. Access a.txt using token
                                      |---------------------------> Document_Store
                                      <-------------------------------|
   <------- Doc opened ---------- 5. Opens a.txt for user
```

<a name=cp></a>
#### Confidential, Public Client Applications
- **1. Confidential:** Client running on protected/secured server. It can securly save credentials as well
- **2. Public:** Application running on user's device(mobile or laptop or browser), cannot save credentials.

<a name=ca></a>
#### Client Application Profiles
- **1. Web Application:** [Confidential client]() with code on protected server.
- **2. User Agent-Based App:** This is public client with code executing in user's browser. Eg: JS
- **3. Native Application:** Public client ie installed and executing on user's machine.

## Terminology
<a name=fed></a>
#### Federated Authentication 
Although many applications have their own DB storing(user,pass) but some applications rely on other services to verify the identity of users, this is called federated authentication. Protocols for federated authentication: openid.

<a name=del></a>
#### Delegated Authorization
Granting access to another user or application to perform actions on your behalf. Eg: When you drive your car to a 5star hotel, they may offer valet parking. You then authorize the valet attendant to drive your car by handing him the key in order to let him perform actions on your behalf. OAuth works similarly—a user grants access to an application to perform actions on the user’s behalf and the application can only perform the authorized actions.

