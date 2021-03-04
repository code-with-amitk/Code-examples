## IPv4 Header
- Header Length:
  - Min: 20 bytes
  - Max: 60 bytes(when Option(40 bytes) are present)

| Version(4 bit) | IP Hdr Len(4 bit) | Type of Service(2 byte) | Identification(2 byte) | Flags(3 bit) | Fragment Offset(13 bit) |TTL(1 byte) | Protocol(1 byte) | IP Hdr Chksum only(2 byte) | SrcIP(4 byte) | DstIP(4 byte) | IP Options(0-40bytes) | Padding | 
|---|---|---|---|---|---|---|---|---|---|---|---|---|

>VHTTIFFTPC: Vandana has time to Initiate fake friendship towards popular cowboy


- *VERSION:* 4 for IPv4, 6 for IPv6
- *HEADER LEN:* Stores Length of IP Header EXCLUDING Data packet(TCP Header+AppData). Calculation: [Header Length Field*4=Length of IP header]
    - Q-Why max length of IP header can be 60 bytes?              Ans- 4bit, can max represent number 15. 15*4=60 bytes(Including IP Options). 
    - Q-What is default value in this header Field?              Ans- Default value in this field is 5. 5*4=20 bytes(Without IP Options) 
- *TYPE OF SERVICE*  
```c
| PB | PB | PB | MIN-DELAY | MAX-THROUGHPUT | MAXIMIZE-RELIABILITY | MINIMIZE-MONTERAY-COST | UNUSED |
        PB(Precedence bit): 1st 3 Bits are Precedence bits & Ignored as of Today
```        
- *TOTAL LENGTH:* It represents total length of  IP Datagram.  [IP Header+L4 Header+L5 Header+L5 Data]
  - Q-What can be Maximum Length of IP Datagram?        Ans- 16Bit. 216=65535 bytes
- *IDENTIFICATION:* This is Kind of Seq-No. This is field is incremented every time packet is sent from source to destination. 
- *FLAGS:*    
```c
| Reserved | Don't Fragment | More Fragment |

DF: Tells router to not fragment the packet. if(DF==1 and pkt_size>MTU) //Discard the pkt. Send [ICMP] message back.
MF: Means other fragments are coming after me. All IP Fragments will have MF=1, But last will have MF=0.
```
- *FRAGMENT OFFSET( 8 byte boundary):* 
  - Usage: It is position of Data Portion of Particular Fragment, considering start of Offset =0, tells where in the current packet this fragment belongs.
- *TTL: Max Value. 28 = 255.* if packet is circulated or queued on 1 router for long time, TTL should be decremented. Without this packets will keep on roaming if routing table becomes corrupted.
  - Usage:  Preventing Indefinite Circulation: TTL is set on packet, When it reaches 0, packet is discarded.
- *PROTOCOL:* Represents Transport layer Protocol.  Usage: When receiver receives the packet, now IP layer will know to which layer it should deliver the packet  
- *HEADER CHECKSUM:* 1's Complement(All IP Header Fields summed using 1's complement method).    OR     one’s complement of the one’s complement sum of all 16 bit words
  - Usage: sender calculates the Checksum Fills in, sends. Receiver receives the packet, calculates Checksum, compares. If match OK, else reject. 
  - Calculation: Sum of IP Header taken 2 bytes at a time. Example Let IP Header: 0x4500003044224000800600008c7c19acae241e2b
```c
  - Divide in 2 byte fields & Add: 4500 + 0030 + 4422 + 4000 + 8006 + 0000 + 8c7c + 19ac + ae24 + 1e2b = 2BBCF
  - Add carry to result: 2 +  BBCF  = BBD1, Binary -> 1011101111010001
  - One's Complement(1011101111010001) -> 0100010000101110 ->442E
  - At each node IP Header checksum must be calculated and matched. 
```
- *OPTIONS:*
```c
    <-----------------    option type    --------------------------->
    | copied-bit(1 bit) | option-class(2 bit) | option-number(5 bit) | option-length(8 bit) | option-data(variable) |

Copied Bit: 1(If options needed to copied in all fragments) 0(If not)
Option class: Category into which Option belongs.       00: Control Option, 10: Debugging & Measurement
Option Number: Kind of Option
Option length: Complete Option length. Option Type + Option Length + Option data    
```
