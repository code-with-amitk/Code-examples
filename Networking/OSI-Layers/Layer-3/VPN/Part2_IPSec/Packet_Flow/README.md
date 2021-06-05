## Packet Flow
- **Inbound Packet Flow:** IPSec pkt comes in
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
- **Outbound Packet Flow:** pkt comes on interface to be routed.
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
