## IMAP (Internet Message Access Protocol)  / Port 143 / RFC 3501
- Protocol for delivery of Email messages from Message Transfer Agent to Receiver User Agent(in [SMTP](/Networking/OSI-Layers/Layer5/Protocols/Email/SMTP_Simple_Mail_Transfer_Protocol)).
- IMAP is an improvement [POP3 protocol](/Networking/OSI-Layers/Layer5/Protocols/Email/POP3_Post_Office_Protocol_v3/README.md)
- **How it works?** Mail server runs an IMAP server that listens to port 143, user agent runs an IMAP client
  - Client connects to server and begin 
```html
  IMAP_Server(port 143)               IMAP Client
                                      connect()
              <---TCP 3 Way Handshake-->
                                      Authenticate self to server
          <-Login or Authenticate command-
                                      Secure the connection
          <--- starttls command--------
                                      List available folders
          <----list command--------                
            
```
- **IMAP Commands**
```html
Command Description
CAPABILITY List server capabilities
STARTTLS Start secure transport (TLS; see Chap. 8)
LOGIN Log on to server
AUTHENTICATE Log on with other method
SELECT Select a folder
EXAMINE Select a read-only folder
CREATE Create a folder
DELETE Delete a folder
RENAME Rename a folder
SUBSCRIBE Add folder to active set
UNSUBSCRIBE Remove folder from active set
LIST List the available folders
LSUB List the active folders
STATUS Get the status of a folder
APPEND Add a message to a folder
CHECK Get a checkpoint of a folder
FETCH Get messages from a folder
SEARCH Find messages in a folder
STORE Alter message flags
COPY Make a copy of a message in a folder
EXPUNGE Remove messages flagged for deletion
UID Issue commands using unique identifiers
NOOP Do nothing
CLOSE Remove flagged messages and close folder
LOGOUT Log out and close connection
```
