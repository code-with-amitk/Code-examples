**Scale on Cloud**
- [Requirements](#r)
- HLD
  - [1 Client & server on same Machine](#h1)
  - [1 M Clients](#h2)

### Requirements
- Functional: Write application that serves 1M users
- [Non-Functional](/System-Design/Scalable)

## HLD
> Start from 1 since, journey of 1000 miles begins with 1 step.

<a name=h1></a>
### 1 Client & server on same Machine
```c
      |--------------------------------------|        1. Server listening on REST endpoint http://localhost:9091/user/{id}
      |                       SERVER         |        2. Client sends HTTP Req to server 
      |  CLIENT                  1           |        3. Server gets user information from file.
      |    2 -HTTP GET{id=2}--->         FILE|            |user-id|name|address|phone-no|
      |                         ----3---->   |        4. Server creates json response and send to client
      |                         <---------   |
      |                       {              |
      |                         name:"a"     |
      |                         address:""   |
      |     <-----4----------- }             |
      |--------------------------------------|
```

<a name=h2></a>
### 1 M Clients
<img src=images/scale_on_cloud.jpg width=900 />
