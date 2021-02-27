## WebMail
- **What?** Here, User Agent is not downloaded on client computer as in **[SMTP](/Networking/OSI-Layers/Layer5/Protocols/Email/SMTP_Simple_Mail_Transfer_Protocol)** instead Web interface for sending and receiving mails is used.
- **Examples** Google Gmail, Microsoft Hotmail and Yahoo.
- **How it works?**
  - *1.* Similar to SMTP Message Transfer agent(MTA) collects SMTP messages, But in place of standalone Reciever User Agent(RUA), Web client is run.
  - *2.* MTA provides login page to user, when username/password are provided MTA creates Inbox on the fly and delivered using HTTP.
  - *3.* On client Web pages include JavaScript programs. These programs are run locally on the client in response to local events (e.g., mouse clicks).
