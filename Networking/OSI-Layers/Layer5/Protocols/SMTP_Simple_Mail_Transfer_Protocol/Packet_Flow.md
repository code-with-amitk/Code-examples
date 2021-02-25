## SMTP Message Transfer
> Note all messages in SMTP are 4 characters Eg: HELO, MAIL RCPT etc.

**Steps**
- *1.* client connects on port=25 and sends HELO.
- *2.* server starts by sending a line of text telling he's prepared to receive mail. if client does not recieve it drops connection and starts again
- *3.*  the client announces whom the email is coming from and whom it is going, if invalid sender server rejects.
- *4.* Actual data transfer happens.
- *5.* Server accepts the data.
- *6.* client releases the connection.
```html
  SMTP-Client                                 SMTP-Server(listen=25)
    connect()
                <----TCP-3-way-handshake--->            //1
                -------HELO example.com---->
                  
            <-220 example.com SMTP service ready---     //2
                  
            ----MAIL FROM: <alice@example.com>-->       //3
             <-------250 sender ok------
            ---- RCPT TO: <bob@example.com>-->
             <-------250 sender ok------
                        
              --------DATA----------------->            //4
C: From: alice@cs.washington.edu
C: To: bob@ee.uwa.edu.au
C: MIME-Version: 1.0
C: Message-Id: <0704760941.AA00747@ee.uwa.edu.au>
C: Content-Type: multipart/alternative; boundary=qwertyuiopasdfghjklzxcvbnm
C: Subject: Earth orbits sun integral number of times
C: Body. Have a nice day.
             
              <---250 message accepted-------           //5
              -------QUIT--------->                     //6                      
```
