## IGMP (Internet Group Management Protocol) / Protocol no 2
- **What?** 
  - This is a protocol with which host advertises his multicast group membership to neighboring switches/routers. Host and router both should be on same LAN.
  - TTL: 1 (Means IGMP Host is directly connected to IGMP Router)
  - Multicast management on **IPv6 networks** is handled by **Multicast Listener Discovery (MLD)** which is a part of ICMPv6.
- **How it works?**
  - A multicast server(on internet) serves particular multicast group & sends the multicat packets over internet.
  - A multicast router recieves the multicast packets and forwards to those hosts which are intrested in recieving the packets.
    - Multicast Router has:
      - Normal IP/Routing Table
      - Multicasting Table (PIM develops M-Route table)
  - Only 1 packet is sent from the source, and multiple copies are created by router and then sent to the desired recipients.

![ImgURL](https://i.ibb.co/4dnM8qm/igmp.png)

- **Message Types**

| Name | Meaning |
| --- | --- |
| Report | send by Host to Router to express intrest in recieving multicast packets of particular group |
| Query | <ul><li>Send by Router to hosts to ask whether you are still intrested in particular multicast group traffic or not</li></ul> <ul><li>Always sent on `224.0.0.1`</li></ul> <ul><li>This message is recieved by all nodes on LAN but only intrested responds</li></ul> <ul><li>When there is no reply to 3 consecutive IGMP membership queries, the router times out the group and stops sending query for that group</li></ul> | 
| Leave | Whenever a Host want to leave a multicast group it sends this message to Router on `224.0.0.2` |

- **Message Format**
```html
| Type(1 byte) | Max Res Time(1 byte) | checksum(2 byte) | Group Address(4 byte) |
```

- **Node Types**
  - **1. Router**
    - IGMP runs on 1 interface If Router has many interfaces connected to a network. Router may behave as Querier(Who can send Query messages) or Non-Querier.
    - All routers starts up as Querier only.
      - **Router vs Querier:** If Router Hears Query message from Router having Lower IP address, it itself becomes Non-Querier.
  - **2. HOST**
    - On reception of Query it sets DELAY TIMER(random value) for each multicast group it is member of. 
    - At expiry of timer, sends v2 Report with TTL=1.
    - If Host receives another report for the Group its time is running(means it will send report), It stops self timer for the group and does not sends the report. To suppress Duplicate reports in network.
      - **Unsolicited  Reports:** Host should send Immediately as it becomes member of particular group.

## TERMS
- **1. IGMP Snooping**
  - Means listening to IGMP Traffic between Router and Host.
  - **Why Required** By listening to these conversations the switch maintains a map of which links need which IP multicast streams.
