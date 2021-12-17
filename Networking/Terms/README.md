- [LAN, MAN, WAN](#vs)
- [Planes: Data, Control, Forwarding, Management](#pl)
- [SDN](#sdn)

<a name=vs></a>
### LAN(Local area network), MAN(metropolitan area network), WAN(wide area network)
||LAN|MAN|WAN|SD-WAN|
|---|---|---|---|---|
|What|connected devices in small n/w|Covers Larger area than LAN, connects devices across cities|Connects devices across countries|Connecting company site offices using MPLS, mobile networks, VPN and other technologies, [mpls](/Networking/OSI-Layers/Layer-2.5/MPLS)|
|Example|school, hospital n/w|towns, cities(multiple owners)|Satellite communication||

<a name=pl></a>
### Data Plane, Control Plane, Forwarding Plane, Management Plane
- **Plane?** Conceptual model used by routers and switches. Planes describe how packets travel to, from, and through a device.
- **Why planes are seperated?**
  - Technologies can be developed independetly.
  - Control plane features are not locked in data plane. *Eg: [SDN](#sdn)*.
- **Comparison**

|  | Control/Slow path/RE(Routing Engine) | Data/Forwarding/High Speed Path | Management | Service |
| --- | --- | --- | --- |---|
| Kind of Traffic | <ul><li>Traffic for myself. I need to respond.</li></ul> <ul><li>I need to generate message myself and participate in conversation.</li></ul> <ul><li> Eg: Routing traffic:OSPF, ping, management etc</li></ul> <ul><li>This is CPU intensive task</li></ul> | <ul><li>This is not my packet, I just need to forward</li></ul> <ul><li>Less CPU intensive task, hence faster.</li></ul> | <ul><li>Management traffic coming to device</li></ul> <ul><li>Eg: SSH, SNMP, Telnet</li></ul> <ul><li>This is **control plane** traffic if meant for myself.</ul></li> <ul><li>This becomes **data plane** traffic if need management of some other device, ie passing from myself to other device.</li></ul>|Most security features implemented here|
|How Implemented|Can be physical card or VM running|Mostly Hardware(Eg: NIC)|||
| How its achieved | | <ul><li> Layer-3:FIB</li></ul> <ul><li>Layer-2: RIB</li></ul> <ul><li>Layer-1: Specialized ASICs</li></ul>| ||
| Controls | <ul><li>How data is forwarded into network.</li></ul> <ul><li>This is brain of network.</li></ul> | |



<a name=sdn></a>
### SDN / Software Defined Networking (Eg: opendaylight)
- Separating S/W from H/W. Routers, Switches can be controlled remotely. ie [Forwarding Plane(lies on Switch), Control Plane(lies on Serve with GUI)](#pl).This is combination of    
  - _a. NFV(N/W Function Virtualization):_ Installing different Software on different Virtual machines.
  - _b. SDN:_ Controlling switches routing decisions from GUI. Person does not have to go physically to control/change Switch/Router.
- **Advantages**
  - _1._ Have global view of n/w using GUI, helps in Traffic Engineering, security enforcement
  - _2._ Simpler Switches
  - _3._ N/W can be customized, N/W open and programmable
- **Disadvantages:** 
  - _1._ SDN is single point of failure. If SDN controller fails whole system will come down.
```c
Traditional Networking:                
    [switch-1] -----  [switch-2] ------ [switch-3]
   /    |    \       /    |    \        /    |   \

SDN Networking:
            SDN-App1    SDN-App2...
              \           /
           [SDN-Controller-Server]            //Having Control Plane
           /        \           \
 switch-chip ---- switch-chip ---- switch-chip
  /  |    \       /    |    \     /    |     \
```
#### SDN Architecture
**Generic**
```c
        Application Plane                SDN App server/App Code
                                        NBI Driver(Implements Northbound APIs)
                                                    \/    /\
                                            NBI Agent(Exposes NB APIs)
        SDN Controller/                SDN Controller
        Control Plane            CDPI Driver(Implements Southbound APIs)     
                                                        \/
                                                    openflow|Other-Protocols
                                                        \/
                                    CDPI Agent   CDPI A       CDPI A        CDPI A(Exposes SB APIs)
    Forwarding Plane/       Switch1       switch2       Switch3       Switch4    
  Data Plane/Data Path
```
**OPENDAYLIGHT**
```c
        Application Plane        Network Applications/Services
                                         \/
                                  opendaylight REST API
                                          \/
        Controller Platform     	Extensions/Service Functions
                                           \/
                                  Service Abstraction Layer(SAL)
                                            \/
                                  Openflow|Other-Protocols(ONF)
                                 /        |            |            \
                              switch1    Switch2    Switch3    Switch4
```
