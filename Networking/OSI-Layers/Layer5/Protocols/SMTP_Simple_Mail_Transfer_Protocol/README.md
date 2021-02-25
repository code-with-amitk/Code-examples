## SMTP (Simple Mail Transfer Protocol) / Port:25
- RFC 5321 Protocol for sending mails and reporting back delivery status/errors.
- [SMTP Terms](Terms.md)
- [SMTP Server client Exchange, Packet Flow](Packet_Flow.md)
- **Disadv:** No authentication, SMTP sends ASCII data, sends message as clear text(no Encryption).
  - Solution: ESMTP(Extended SMTP)

## Entities/Nodes in SMTP
> There are 2 entities in SMTP
<img src="smtp-architecture.JPG" width=600 />
- **1. User Agent/Email Reader(Outlook/Gmail/Thunderbird etc):** Allows people to read/send/compose/search mail.
- **2. Message Transfer Agent:** 
  - Transfers messages from source to destination.
  - Runs on  mail server machines. Uses SMTP to send mail from sender to reciever
