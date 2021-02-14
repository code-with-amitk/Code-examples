## DNS(Domain Name Service)
- Layer-5 protocol For converting hostname to IP and reverse. Port=53(udp and tcp both)Use udp by default, fall back to tcp if on udp cannot communicate.

## How Forward lookup works?
```c
 BROWSER(amit.fb.com)
Search: yahoo.com
IP<>hostname (not found in browser cache)                                                                                                              
  - | MAC | IP | UDP destPort=53 |                                                                                                                                 
     | DNS Query{Hdr QR:0,Question:1}{Body QName:yaho.com,Type:A,Class:IN}->     Office_DNS-srvr/ISP/Local_DNS_Server/
                                                                                 Recursive_DNS_srvr(fb.com)
                                                                                 cannot find IP<>hostname
                                                                             Finds Rootname server's IP using NS record from zone file
                                                                                         --------------DNS Query----------->  ROOT-NAMESERVER
                                                                                                                       Finds TLD server handling .com
                                                                                                                                                  .com TLD
                                                                                                                                  ------DNS Query --->
                                                                                           <----IP address of Authoritative-DNS-server(8.8.8.8)---------
                                        Authoritative-Name-Server(8.8.8.8) <----DNS Query -----
                                                                            yahoo.com = x.x.x.x
                                            -| DNS Response{Type:A,TTL:23min,Address:x.x.x.x}--->
                                            
        <----------| DNS Response{Hdr QR:1,Question:1}{Body Ans:1}{Answer:x.x.x.x}---------------------
```        
