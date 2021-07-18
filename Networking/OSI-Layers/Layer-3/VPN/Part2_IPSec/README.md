- [What is IPSec](#what)
- [Advantages, Disadvantages of IPSec](Advantages_Disadv_of_IPSec.md)
- Encrypting Data
  - [1. Tunnel Mode](#tun)
  - OR [2. Transport Mode](#tran)
- IPSec Packet Headers
  - [Authentication Header / AH](#ah)
  - OR [ESP(Encapsulating Security Payload)](#esp)
- Packet Flow
  - [Inbound](#in)
  - [Outbound](#out)

<a name=what></a>
## IPSec
- Set of open standards for ensuring secure private communication over Internet. IPSec does not support broadcast & multicast.
- Works over TCP

## Encrypting Data
<a name=tun></a>
### 1. Tunnel Mode
- New IP Header provided. For Firewall-to-Firewall Delivery.
- Consumes more CPU power. IP, TCP, App Protected.
```c
                            |-------  Encrypted   -----------|
      | New IP Hdr | ESP/AH | Old IP Hdr | TCP Hdr | App Hdr |
```
<a name=tran></a>
### 2. Transport Mode
- Host-to-Host Delivery. TCP & Application Protected.
```c
                                         |--  Encrypted   -------|
   | IP Hdr | ESP/AH(protocol=ESP or AH) | TCP/UDP Hdr | App Hdr |
```

## IPSec Packet Headers
```c
                     AH  | ESP
       ------------|-----|-----
Integrity check    | Yes | Yes 
Encryption Support | No  | Yes
IPv6 support       |  no | Yes
```

<a name=ah></a>
### Authentication Header / AH
- **Provides:** Authentication & Integrity
- **Does not provide** Encryption
```c
  |IP Header | Authentication_Header | TCP/UDP/IDMP | Application
             |                       |
  -----------                         ----------------------------------------------------------------------------------
 |                                                                                                                      |
 | Next Hdr(1 byte) | AH Len(4 byte) | Reserved | SPI(4 byte) | Seq No(4 byte) | ICV/HMAC/Authentication Data(variable) |
```
- *Next Header:* IP
- *Payload Length:* length of the Authentication Header
- *Security Parameters Index (SPI):* This is connection identifier. Receiver will search this SPI in SPD and find matching SA.
- *Sequence Number:* 
  - Seq no of all the packets sent on an SA. Every packet gets a unique sqe no, even retransmissions. This detects reply attacks.
  -  If all 2<sup>32</sup> are exhausted, a new SA must be established to continue communication.
- *ICV(Integrated check value)/Authentication Data:*  
  - This is HMAC(keyed Hash) calculated on complete packet (|AH|Original-IP-Hdr|TCP|Application|)
  - **How ICV is calculated?** TTL is not included in ICV since it changes at every router.
```c
 Shared key(k1) is established during ISAKMP phase.
    
             \/ k1
Magic No1 > |XOR| > aaa

             \/ k1
Magic No2 > |XOR| > bbb
  
  |AH|Original-IP-Hdr|TCP|APP| + aaa > |HASH| > ccc
  
  ccc + aaa > |HASH| > ICV
```

<a name=esp></a>
### ESP(Encapsulating Security Payload)
- **Provides**
  - Encryption
  - Integrity
  - Authentication: With ESP Header & Trailer, Authentication Data Tailor is also added to message.
- **Header**
```c
|New IP | ESP Hdr | Old IP | TCP | App | ESP Trailor | Auth Data/ICV |
        |         |                    |             |
      --           -                  -               -------------
     |              |                |                             |
     | SPI | Seq no |                |Padding | Pad Len | Next Hdr |
```
- *1. SPI:*  same as in AH
- *2. Seq No:* same as in AH
- *3. Next Hdr:* same as AH
- *4. ICV:* Same as AH But does not included in Header of Trailer but comes after trailer.
  - **Why ICV is placed at end?**
    - Advantage in a hardware implementation: HMAC can be calculated as the bits are going out over the network interface and appended to the end. This is why Ethernet and other LANs have their CRCs in a trailer, rather than in a header.
    - With AH, the packet has to be buffered and the signature computed before the packet can be sent, potentially reducing the number of packets/sec that can be sent.

## Packet Flow
<a name=in></a>
#### Inbound Packet Flow: IPSec pkt comes in from n/w
```c
    if(proto == IPPROTO_AH | IPPROTO_ESP){
        //Check SPI & Get matching SA
        if(SA == transport){
            //Decrypt Send to N/w Layer
        }else{
            //Remove Outer IP Header
            //Decrypt.    send to N/W
        }
    } 
```
<a name=out></a>
#### Outbound: IPSec pkt comes on interface to be routed
```c
    if (IPSec){
        Check Src & Dst in SP for outgoing Interface.
        If (IPSec_none)    By Pass    
        if(SP=IPSec_discard)    Drop
        if(Apply_IPSec){
            //Get SA
            if(mode == Tunnel){    //Paste New IP Hdr    }
            else if(mode==Transport)
        }
    } 
```

