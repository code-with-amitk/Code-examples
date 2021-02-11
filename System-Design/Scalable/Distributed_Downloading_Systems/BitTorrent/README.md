# Bit Torrent

## 5. HLD
- **Torrent File:** This contains addresses of tracker servers.
- **Tracker server:** This has list of active nodes(client-IP addresses which are downloading a file) and fragment number which is already downloaded.

> Let's suppose user-1, user-2, .. user-n wants to download a Movie-xyz or VMware(.vmdk) file sized 3-4GB.
- *1.* All users will connect to Global Directory(well-known Web site) and requests tracker server IP.
- *2.* Users will connect to Tracker server to get list of users downloading file and fragments they hold. Also upload/download speed of peers.
- *3.* User-n will download fragment-x, connect to user-10, provide fragment-x to user-10 and get fragment-y from him.
  - *SLIDING WINDOW TCP* can be implemented for flow control between slow and fast users.
```c

    user-1  <-------------------TCP-connect--------------------------|
                                                                     |
            user-2 <-------------TCP-connect----------------|        |
                                                           \/       \/
user-n   <----------------TCP-connect------------------->  Global-Directory               //1
  |                                                           |- vim torrent-file
  |                                                               tracker-server 10.5.6.7 
  |                           
  |---------BitTorrent_protocol(GET Tracker-server for Movie-xyz)-->
    <---------10.5.6.7-----------------
                                                            Tracker(10.5.6.7)
  |-----BT_protocol(client,fragment info for Movie-xyz)-->        |                   //2
  |  <--------- user-10(fragments:2,5,6), ---------------
  |  
  |  
Downloads fragment-x
  |---------fragment-x,Movie-xyz,Give_me_fragment_2--------> User-10                  //3
    <---ACK, Fragment_2---------------------------
```

## 6. Bottlenecks
### A. Tracker-server
  - Tracker server can come down when huge number of clients connect
  - **Solution** User machines/Participating nodes becoming Tracker-servers for small number of files in DHT(Distributed Hash Table) approach.
### B. Free-Riding  
