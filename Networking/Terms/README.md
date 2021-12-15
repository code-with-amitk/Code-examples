- [SDN](#sdn)

<a name=sdn></a>
## SDN / Software Defined Networking (Eg: opendaylight)
- Separating S/W from H/W. Routers, Switches can be controlled remotely. ie [Forwarding Plane(lies on Switch), Control Plane(lies on Serve with GUI)](/Networking/Terms).This is combination of    
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
### SDN Architecture
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
