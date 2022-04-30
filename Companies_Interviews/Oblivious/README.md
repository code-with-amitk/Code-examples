- [R2: Take home challenge](#r)

## R2. THC
Design CI/CD tool as github action.
- _1._ .oblivious folder, .oblivious/service.yaml exists in repository
- _2._ Confirm service.yaml confirms to json schema.
```c
user  Role  talk_to_server
amit  admin yes
ram   user  no
```
- _3._ Program sends auth_header and body to server. Encrypt auth_header.
```c
  $ ./a.exe username    //Take username as argument. if talk_to_server=no throw error.
  
  Client
  if (username = talk_to_server=yes) {
    //auth-header=username
    //body:
      Hash of complete repo
      meta-data=branch,date,repo name ----------{auth_header,body}--------> Server
                                      <--------Hello<username>------------
  }
    
```
