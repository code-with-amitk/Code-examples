**Configuring IP Address on Computers in Network?** There are 2 ways to do this.
- *1.* Manually visit each computer and configure IP
- *2.* DHCP

## DHCP / Dynamic Host Configuration Protocol / Port 67
- **Why?** when machine joins network, it will obtain IP address automatically using DHCP.
- **How to configure DHCP on Machine?** TCP/IP Settings->Automatic.
- **How it works(DORA)?** Every network has DHCP server(listening on port 67) which provides IP Addresses to clients.
> Discover, Offer, Request, Acknowledgement

  - (t=0)
    - New machine(Client3) joins to network. This machine does not have IP-Address but has MAC-Address(on ethernet card).
    - DHCP Client3 sends DHCP_Discover packet on LAN.
  - (t=1)
    - DHCP_Discover reaches DHCP server either directly or via router.
    - Server allocates free IP Address and sends back to client in DHCP_Offer.
```html
                                  DHCP-Client2(192.168.1.2)
    ---|----------------------------------|---LAN---------------------------|------------|-------
 DHCP_server(192.168.0.10)                                             Client-4    Client3(joins n/w)

        <-------------|DHCP_Discover|srcMAC=0.3|(broadcasts 255.255.255.255)--------Ask for IP Address
 Allocated IP3=192.168.1.3
        ----broadcasts 255.255.255.255|srcMac=.10|dstMAC=0.3|DHCP_Offer(Allocated IP3)--->
          
        <--|DHCP_Request|dstMAC=.10|srcMAC=0.3|(broadcasts 255.255.255.255)--------Can you give 192.168.1.7?
  Ok, Acknowledged
        --|DHCP_ACK|srcMAC=.10|dstMAC=0.3|(broadcasts 255.255.255.255)---------------->    

//Why Broadcast?
 - Since IP Address is not configured, server cannot talk to DHCP client unicast.
```

### Issues in DHCP
- **1. For how long an IP address should be allocated?** If a host leaves the network and does not return its IP address to the DHCP server, that address will be permanently lost.   - *Solution: Leasing* IP address is assigned for fixed period of time, just before lease time expires, the host must ask for a DHCP renewal. If it fails to make a request it cannot use the IP address.

### Use cases of DHCP
- **1. Used by ISPs.** DHCP is used by ISPs to set the parameters of devices over the Internet access link, so that customers do not need to phone their ISPs to get things done.
- **2. Companies.**

## [Advantages and Disadvatages of DHCP](Advantages_Disadv_of_DHCP.md)
