## TCP Header
- Size: Min(20 bytes), Max(60 bytes)
```c
|src Port (2 byte) | Dst Port (2 byte) | Seq No (4 byte) | Ack No (4 byte) | HdrLength /Data Offset (4 bit) | Reserved (6 bit) | Control Bits (6 bit) | WindowSize/ Receiving BufferSize (2 byte) |	Complete Packet Checksum (16 bit) | Urgent Ptr (16 bit) | Options (0-40bytes) |	Pad |

Control Bits: URG ACK PSH RST SYN FIN 
```

### Feilds
- **SRC,DST PORTS:** 2<sup>16</sup> = 65536(65535 Ports Possible)
- **SEQUENCE NO(Reliability):** This is for reliable delivery of packets. 
  - Sender : Makes a packet, adds a sequence Number to it and sends. Sender sends 4,5,6,7,8,9,10
  - Receiver : Receives 4,5,6,8,9,10. Ohh I have lost seqno 7. 
  - For Reliability/Seq No to work, Both Sender & Receiver should synchronize their Seq No.s [3 Way Handshake]()
- **ACK NO(Reliability):** Used by Receiver to Tell sender which packet has arrived successfully.
  - Sender : Sends 4,5,6,7,8,9,10
  - Receiver : Receives 4,5,6,8,9,10. Sends ACK=4, ACK=5, ACK=6, ACK=8
  - Sender : Ohh ACK=7 not received, means Receiver has no
- **HEADER LENGTH:** Length of TCP Header in 4 byte Offset. 
  - Data Offset -> 5, Size of Header -> 5x4 = 20 bytes Data Offset -> 15, Size of Header -> 15x4=60 bytes
- **CONTROL FLAGS:**
  - SYN Flag: For Connection establishment, Start of 3-way handshake. See Layer5->TCP->TCP Transition States
  - FIN Flag: Closing the connection. See Layer5->TCP->TCP Transition States
  - URG Flag If Urgent Data is present
  - ACK Flag: This is ACK of earlier sent packet. See Layer5->TCP->TCP Transition States
  - PSH Flag : 
  - RST Flag: Something UNEXPECTED Happens at remote end. Most Common cases: [Other Reasons](https://blogs.technet.microsoft.com/networking/2009/08/12/where-do-resets-come-from-no-the-stork-does-not-bring-them/)
    - {Client/Server} Device received a segment from unknown device..
    - {Client/Server} Received Message with Incorrect/Invalid seqNumber or AckNumber Field. Receiver sends RST.
    - {Server} receives a SYN where no process is listening for connection.
    - Due to No response: {Client/server} node sends a packet & does not receive an ACK. After 6 retransmits of same packet if remote end has not replied, sender will send RST.
    - Application Reset.  {Server} If we see n/w and see no reasons as above then that must have been sent from application. Application could be making large number of short lived connections and soon gets out of ports. many ports may be in TIME WAIT state.
    - Another Application has grabbed same port.     {Server} seen less often, when some other process on server has grabbed the port. This generally will happen when a system is booted up with two applications that both want to listen on the same port.
    - 3rd Person(Router/Firewall/KDC) in N/W:        Any of these nodes may be resetting the connection. How to diagnose, see captures of both sender & receiver. See sender's IP address(if it of some 3rd party).

- **WINDOW SIZE:** Tells How many bytes I can receive at a time. When IP packets are received, they are placed in a temporary area of RAM known as a buffer until the receiving computer has a chance to process them; this value represents how big a buffer the                 receiving host has made available for this temporary storage of IP packets.
- **CHECKSUM(Error Detection):** TCP runs checksum on complete Packet (TCP Header+App Header+App Data) Unlike IP, which does Header checksum
  - Calculations: Same as IP Header but Here following fields are included:
  - Pseudo IP Header(Src IP, Dst IP, Reserved(8bit, all zeroes), Protocol(1byte, 6 in case of TCP), Length)
  - TCP Header
  - App Data
- **URGENT POINTER:** If URG flag is set, This points to address of urgent data
- **OPTIONS:**  | ----option kind(1 byte)--- | -----option length (1 byte) ------- | option data (variable) ------- |
  - Option Kind: specifies option type. In some cases only Option-Kind is presented, Receiver understands from that only.
  - Option-Length: length of entire option(in bytes). Option Length =  Option-Kind+Option-Length+Option-Data
  - Option-Data
  - Examples of options:
    - *1. Maximum segment Size(MSS):* Maximum amount of data that Receiver or Sender wants to receive(specified in Octets/bytes) OR maximum amount of data computer can handle at once(in single frame, unfragmented). It excludes TCP, IP Headers.
      - Default value: 536.
      - Each side can have different MSS.
      - This field must only be sent in the initial connection request (i.e., in segments with the SYN control bit set). If this option is not used, any segment size is allowed. This value cannot be changed When connection is Established.
    - *2. Window Scalar factor*
    - *3. SACK permitted*
    - *4. IR(Instant Recovery)* Used to distinguish encoded/XOR packets from regular packets.
      - [Encoding Type](https://tools.ietf.org/id/draft-flach-tcpm-fec-00.html#types): 0:Undefined, 1:Basic XOR, 2:Interleaved XOR, 3-255:Undefined
```html
  | kind=TBD | Len = 1 | Encoding Type |
```
- **PADDING:** Header must be padded with 0(ZERO) to make 4 byte aligned.
