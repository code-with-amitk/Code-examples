- [What is oauth](#what)
- [Actors in oauth](#actors)
- [Terminology](#term)

<a name=what></a>
## oauth / okta Authorization
- OAuth2 is an authorization framework that enables applications to obtain limited access to user accounts on an HTTP service.
- Why username/password authorization is not good?
  - User is very hesistant to provide passwords to new applications on web.

<a name=actors></a>
## Actors in oauth
- **1. Resource server:** The server hosting user-owned resources(photos, videos, contacts etc) eg: google.
- **2. Resource owner / User:** He has the ability to grant access to their own data hosted on the resource server.
- **3. Client:** An application who want to perfom actions on user Resources(on behalf of users) with its authorization, does API requests to Resource server.
- **4. Authorization server:** This gets consent from the resource owner and issues access tokens to client.
- **5. Access/Bearer Tokens:** When client possesses these access tokens he can access protected resources. No additional information is needed to make API call. Then this token is sent in HTTP authorization header.
```http
GET /tasks/v1/lists/@default/tasks HTTP/1.1 
Host: www.googleapis.com
Authorization: Bearer ya29.AHES6ZSzX
```

<a name=term></a>
## Terminology
- **Federated Authentication** Although many applications have their own DB storing(user,pass) but some applications rely on other services to verify the identity of users, this is called federated authentication. Protocols for federated authentication: openid.
- **Delegated Authorization** Granting access to another user or application to perform actions on your behalf. Eg: When you drive your car to a classy hotel, they may offer valet parking. You then authorize the valet attendant to drive your car by handing him the key in order to let him perform actions on your behalf. OAuth works similarly—a user grants access to an application to perform actions on the user’s behalf and the application can only perform the authorized actions.
