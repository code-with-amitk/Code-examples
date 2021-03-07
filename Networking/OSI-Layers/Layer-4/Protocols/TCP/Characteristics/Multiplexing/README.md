## Multiplexing
- On application layer there can be several protocols using TCP. Eg: SMTP, SSH, FTP, telnet. All will have different Port numbers.
- Every protocol's data is sent thru same IP and NIC card.
- When data for particular application arrives (at its port), TCP sends to appropriate Application.
```html
Application:    SSH   SMTP    Telnet
Transport       22    25      23
                |     |       |
                 -----|--------
IP                200.1.1.2
```
<img src=TCP_Multiplexing.png width=400 />
