## ARP Spoofing
- **What?** 
  - Node sends ARP Request to know MAC Address for IP Address(a.b.c.d). A Malicious Node is sitting on LAN. 
  - It sends falsified ARP response (in reply to ARP request). Now, any packets intended for IP(a.b.c.d) would be received by Malicious intruder sitting in LAN.
- **Detect/Avoid ARP Spoofing?**
  - *1. Packet Filtering:* 
    - Packet filters inspect packets transmitted across network. Eg: Wireshark. Packet filters are capable of identifying/blocking packets with conflicting Source address information.
  - *2. Using ARP Spoofing Detection S/Ws:* 
    - There are many softwares which detect spoofed packets. These work on detecting & certifying data before transmitting & blocking data that appears spoofed. Eg; XARP, wireshark, 
  - *3. Encryption data before sending:* TLS, SSH, HTTPS are secure communication protocols. Data can be encrypted before sending & authenticated on reception.
