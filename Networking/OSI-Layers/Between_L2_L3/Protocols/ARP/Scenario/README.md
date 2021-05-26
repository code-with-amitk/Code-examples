## Example Scenario
- There are 3 Computers on Office LAN(newly connected). host1 want to sent pkt to host3
- [CAM Table]()
```console
          Switch
   port1   port2    port3
   /        \            \
hostA       hostB       hostC
192.168.0.1   .2         .3


      Host-A                                 
A want to send pkt to C
A knows C's IP via DNS or Routing Table
if(ARP_Cache_table has MAC of C) {
} else {
  Broadcast ARP REQ
  with dstMAC=ff:ff:ff:ff:ff:ff
}  
  ------------ARP-REQ-------------------------->      SWITCH
|srcIP=.|dstIP=.3|srcMAC=.|dstMAC=ff:ff:ff:ff:ff:ff|
                                                    Build CAM Table
                                                    Port    MAC-Address
                                                    port1    hostA
                                    Forward ARP-REQ on all remaining interfaces
                                                                                
                                                                                Host-B
                                                                     Discard pkt(dstIP != mine)
                                                                     
                                                                                              HOST-C
                                                                                            dstIP=MyIP Yes
                                                                                       Insert MAC-A in my cache
                                                          <------------ARP-REP-----------------
                                                          |srcIP=.|dstIP=..|srcMAC=......:C|dstMAC=.|
          <--------------Forward--------------------------                                                          
```

  
