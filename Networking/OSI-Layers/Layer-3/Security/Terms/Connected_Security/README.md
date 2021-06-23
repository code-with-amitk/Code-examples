- [1. What is Connected Security](#What)
- [2. Components of CS](#Pillars)
  - [2.1 Threat Detection Engine](#TDE)
  - [2.2 Policy Engine](#PE)
- [3. Flow CS](#Flow)

<a name="What"></a>
## What is Connected Security?
- **Presently day scenario:** All security devices work indivisually ie seperately protects the orgnization. Works in phylo.
```c
<--------------------------- 1 Orgnization ------------------------->
                      |
  site-1  router-1  firewall(Cisco)
                      |                                                               internet
                                                     |
                                  router-n    DDos Defense(Palo Alto)
                                                     |
```
- **Solution?** Connected Security
  - All components are connected, even belonging to different vendors.
  - Each component is leveraged euqally ie Network and security elements are used equally.
  - Turns routing devices(routers, switches) into security devices(eg: firewall, IPS etc).

<a name="Pillars"></a>
## 2. Components of Connected Security
- **A. Perimeter Firewall** ie Front-end firewalls, which recieves the packets from internet.
- **B. Automate/Threat Engine/Policy Engine** 
  - Looks into packet forwared by perimeter firewall, decides whether its Threat/malware if yes informs Policy Engine.
  - Informs firewalls to enforce/execute policy. Examples:ATP(Advanced Threat Prevention) device, Cloud ATP
- **C. Policy Engine:** Node which enforces policies on switches/routers lying inside the secured network ie inside organization. 
- **D. Switches/Routers** On these devices policies are enforced.

<a name="TDE"></a>
### 2.1 Threat Detection Engine
- _a. Threat Feed:_ 
- _b. Ondemand detection engine:_ Takes feed does anlysis/sandboxing/ML and says provides verdict that it's a threat or not.
- _c. Mitigation:_ Gives verdict that these devices are botnets.

<a name="PE"></a>
### 2.2 2.2 Policy Engine
- Checks whether packet is malware or not, enforces policies on routers/switches to block the user downloading malware.

<a name="Flow"></a>
## 3. Flow
- _1._ User inside secured network sends request to download a file(malware).
- _2._ When actual file comes to Perimeter-firewall, it forwards it to ATP(Threat Engine).
- 3. ATP detects it as malware and forward to policy enforcer(Policy Engine)
- 4. Policy engine pushes policies based on RADIUS protocol.
  - User-A is pushed into seperate VLAN.
  - User-A's port is blocked, so that malware is not spread to other devices.
```c
//CS is not a devie its a architecture

    Company-network           
user-A   ----switch-1
         ------|
Download a.txt  //1 ------------------------------------------ PERIMETER-FIREWALL -----  internet  --------> Malware
                                                                          <----------------- a.txt --------------
                                                               Forwards to ATP  //2
                                          ATP(THREAT ENGINE)<-a.txt-                 
                                          a.txt is malware    //3
                          POLICY-ENGINE<-a.txt-
         swtich-2 <--pushes policy-- //4
```


