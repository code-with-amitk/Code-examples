## POP3 / Post Office Protocol, version 3 / RFC 1939
- POP3 is used for delivery of Email messages from Message Transfer Agent to Receiver User Agent in [SMTP](/Networking/OSI-Layers/Layer5/Protocols/Email/SMTP_Simple_Mail_Transfer_Protocol).
- [IMAP](/Networking/OSI-Layers/Layer5/Protocols/Email/IMAP_Internet_Message_Access_Protocol) is improvement over POP3.

||POP3|IMAP|
|---|---|---|
|Adv|Simple wrt IMAP|
|Disadv|Less secure, less no of messages wrt IMAP|Have encyption, more messages|

- **How it works?**
  - In POP3 mails are downloaded to user agent computer as compared in SMTP/IMAP mails are downloaded to IMAP server.
  - This makes life harder for users.
  - **Disadv** Also, user agent computer crashes all email may be lost permanently.
