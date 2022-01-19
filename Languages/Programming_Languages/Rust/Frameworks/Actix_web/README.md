Actix_Web
- [Actix http Webserver exposing REST API](#w)
  - [Code](Code)

## Actix_Web
Fast, powerful, open source web framework for Rust. Actix_web is sponsored by microsoft on github.

<a name=w></a>
## Actix http Webserver exposing REST API
- Check [How REST Works](/Networking/OSI-Layers/Layer-7/WebServer_WebClient_WebService/WebClient_Connecting_WebServer/REST/README.md#how). Remember REST-API exposes a resource via [HTTP CRUD Methods](/Networking/OSI-Layers/Layer-7/Protocols/HTTP/README.md#mea) and allows to perform operations on it. 
```rs
//Here we have taken Resource=user.

REST API           |   Desc                                         |   function
-------------------|------------------------------------------------|-------------------
GET /users         | returns all users                              |   get_users()
GET /users/{id}    | returns the user with a given id               |   get_user_by_id()
POST /users        | takes in a JSON payload and creates a new user |   post_add_user()
DELETE /users/{id} | deletes the user with a given id               |   delete_user()
```
