Terms
- [Inbound, Outbound Requests](#io)
- Origin server
- User Agent
- [Intermediaries: proxy, gateway, and tunnel](#int)

## Terms
<a name=io></a>
### Inbound, Outbound Requests
 - inbound means "toward the origin server"
 - outbound means "toward the user agent".

<a name=os></a>
### Origin Server
Program that can provide authoritative responses to HTTP client

<a name=ua></a>
### User Agent
Any client programs that initiate a HTTP request.

<a name=int></a>
### Intermediaries
```c
UA ======Proxy=====Tunnel======Reverse_Proxy====== OS
```
#### Proxy
- A "proxy" is a message-forwarding agent that is chosen by the client, usually via local configuration.
- Some proxies are designed to apply transformations to selected messages or content while they are being forwarded

#### Gateway (or Reverse Proxy)
- Acts as an [origin server](#os) for the outbound connection but translates received requests and forwards them inbound to another server or servers.

#### Tunnel
- A blind relay between 2 connections without changing the messages.

