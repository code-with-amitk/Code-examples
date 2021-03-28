### Example
> Let's suppose user-1, user-2, .. user-n wants to download a Movie-xyz or VMware(.vmdk) file sized 3-4GB.
- *1.* All users will connect to Global Directory(well-known Web site) and requests [Tracker Server](Terms.md) IP.
- *2.* After getting tracker IP, will connect to Tracker server(over HTTP) and gets complete list of clients downloading files/fragments(ie Swarm).
- *3.* User-n will only connect with user-m from [Neighbour set](Terms.md).
- *4.* User-n downloads fragment-1, connect to user-n, provide fragment-1 & gets fragment-2.
  - *SLIDING WINDOW TCP* can be implemented for flow control between slow and fast users.
```c

    node/user-1  <-------------------TCP-connect--------------------------|
                                                                          |
            node/user-2 <-------------TCP-connect----------------|        |
                                                                \/       \/
node/user-n   <----------------TCP-connect------------------->  Global-Directory               //1
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
  |---------fragment-x,Movie-xyz,Give_me_fragment_2--------> node/User-10                  //4
    <---ACK, Fragment_2---------------------------
```
