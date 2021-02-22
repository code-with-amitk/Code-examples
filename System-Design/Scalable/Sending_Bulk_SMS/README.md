## Bulk Message sending

### 5. HLD
**Steps**
- *0.* On web-server we already have:
  - *a.* list of people to whom message need to sent
  - *b.* Templated content of what message need to be sent.
- *1. to 6.* Same as FB news feed
- *7.* From home page browser selects 2 drop downs.
  - *a.* Group to which message need to be sent
  - *b.* Message template need to be sent
- *8.* Message reaches web server and it forwards to [SMSC/SMS Gateway](/Networking/SS7) by calling API SMSC understands.
- *9.* SMSC delivers messages to clients using MSC. SMPP(Short Message Peer-to-Peer) protocol will be used here.
  - SMPP is standard messaging protocol designed to send messages using TCP/IP to wireless mobile networks such as GSM, TDMA, CDMA etc. it can send messages upto 10,000/min. 
```html
  Web-Browser
7. User selects
    group-4, message-2  > |Hash| > XXX
        |
        ---> |encrypt| > YYY

                                --------
                  XXX,YYY >    |Internet|     --> |         Data-Center              |
                                --------           SSL_Term, Load_Balancer, Web_server 
                                                                            8.|
                                                                              ---------------> |SMSC or SMS Gateway|
                                                                                                    9
```
