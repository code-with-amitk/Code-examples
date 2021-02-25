## SMTP (Simple Mail Transfer Protocol) / Port:25
- RFC 5321 Protocol for sending mails and reporting back delivery status/errors.
- [SMTP Terms](Terms.md)
- **Disadv:** No authentication, SMTP sends ASCII data, sends message as clear text(no Encryption).
  - Solution: ESMTP(Extended SMTP)

<img src="smtp-architecture.JPG" width=600 />

## Entities/Nodes in SMTP
> There are 2 entities in SMTP
- **1. User Agent/Email Reader(Outlook/Gmail/Thunderbird etc):** Allows people to read/send/compose/search mail.
- **2. Message Transfer Agent:** 
  - Transfers messages from source to destination.
  - Runs on  mail server machines. Uses SMTP to send mail from sender to reciever

## [SMTP Server client Exchange](Packet_Flow.md)
- **Sending Message from User-1 to User-2:** Message is sent as Envelope+Body
  - *1. Envelope:*  It contains all the information needed for transporting the message, such as the destination address, priority, and security level etc.
  - *2. Body:* Actual message.  It consists of 2 parts:
    - *2a. Header:*  contains control information for the user agents
    - *2b. Body:* For human reciepients 
