- [Generations of Wireless communication/Telecommunication](#g)
- [VOIP](#v)

### Generations of Wireless communication/Telecommunication
- 1G / NMT / TACS / ETAC: Nordic mobile telephony, Total access communication system, European Total access communication systemSends analog signals. Disadv: Analog signals cannot go long distance
- 2G / GSM: Sends Digital signals. 1st converts Analog to Digital, sent digital, convert back to Analog 
- 2.5G / GPRS: General Packet radio Service. data rate: 50-60 kbps
- 2.75G / EDGE: Enhanced data rate for GSM Evolution. Data rate: 170 kbps
- 3G / UMTS: Universal Mobile Telecommunication system. Data rate: 384 kbps. Features: Video calling
- 3.5G / HSDPA: high Speed downlink packet access. focuses on download
- 3.75 / LTE (we are here): Long term Evolution
- 4G (Expected Yet not reached): 1Gbps: Stationary Object. 100mbps: moving object 
- 5G: Researching going on. 5Gbps

## VOIP(Voice over IP)/Cloud Telephony
- What? Sending voice(Audio), Image(Video) over IP network.
- Benefits? Less cost, No H/W cost, No maintenance cost, 0 costed long distance calls/international calls.
- Prerequisites? You only need internet connection.

### SIP(Session Initiation Protocol)
Signalling protocol used for starting, maintaining, terminating Media sessions over IP. ie sending Video/Audio over IP. SIP is text based protocol and formatting of SIP requests and responses is based on HTTP version 1.1. SIP can use both UDP or TCP as the underlying transport protocol.
- 3 protocols mainly used:
  - SIP: Establish/Terminate sessions
  - Session Description Protocol (SDP): for describing  multimedia sessions means to exchange information about audio/video channels
  - Real-time Transport Protocol (RTP) :Sending real-time streams of Audio/Video across network.
  - Protocols to be used in Conjunction
    - Real time Controlling Protocol(RTCP): For controlling media sent.
    - Real-Time streaming protocol (RTSP): for controlling delivery of streaming media
    - Media Gateway Control Protocol (MEGACO): for controlling gateways to the Public Switched Telephone Network (PSTN)
#### Packet Types
a. Signalling packets(SIP)    
b. Media packets
#### SIP Overview
```c
        Computer                                    SIP-Phone
                -------SIP-msg (Let's talk)-------->
                <-------SIP-msg (ACK)--------
Amit Speaking (Analog)
        \/
    [Speaker] > [Digital-Converter] 
                    \/
                    RTP(...) //Packed --RTP(Voice/Audio)------> //Unpacked    > [Analog-Converter] > analog-wave > Speaker
```
