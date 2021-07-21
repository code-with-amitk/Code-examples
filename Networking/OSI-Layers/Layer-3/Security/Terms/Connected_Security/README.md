- [Connected Security](#What)
- [Components of CS](#Pillars)
  - [1. Threat Detection Engine](#TDE)
  - [2. Policy Engine](#PE)
- Flow
  - [1. Flow On Premisis](#OnPremisis)
  - [2. Flow On Cloud](#OnCloud)


<a name="What"></a>
## Connected Security
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
## Components of Connected Security
- **A. Perimeter Firewall** ie Front-end firewalls, which recieves the packets from internet.
- **B. Automate/Threat Engine/Policy Engine** 
  - Looks into packet forwared by perimeter firewall, decides whether its Threat/malware if yes informs Policy Engine.
  - Informs firewalls to enforce/execute policy. Examples:ATP(Advanced Threat Prevention) device, Cloud ATP
- **C. Policy Engine:** Node which enforces policies on switches/routers lying inside the secured network ie inside organization. 
- **D. Switches/Routers** On these devices policies are enforced.

<a name="TDE"></a>
### 1. Threat Detection Engine / ATP
- _a. Threat Feed:_ 
- _b. Ondemand detection engine:_ Takes feed does anlysis/sandboxing/ML and says provides verdict that it's a threat or not.
- _c. Mitigation:_ Gives verdict that these devices are botnets.

<a name="PE"></a>
### 2. Policy Engine
- Checks whether packet is malware or not, enforces policies on routers/switches to block the user downloading malware.

## Flow
<a name="OnPremisis"></a>
### 1. Flow On Premisis
- _1._ User inside secured network sends request to download a file(malware).
- _2,3._ When actual file comes to Perimeter-firewall, it forwards it to ATP(Threat Engine). 
  - ATP detects it as malware.
  - ATP provides file to Policy engine.
- _4._ ATP instructs perimeter firewall to drop packet
- _5._ Perimeter firewall drops packet, blocks user downloading the file.
  - User-A is pushed into seperate VLAN.
  - User-A's port is blocked, so that malware is not spread to other devices.
- _6._ Policy engine pushes policies to other switches/routers inside secured network so that all devices are aware, if user moves to someother port its not allowed to access internet, malware from there.
  - Policy enforcement is done based on RADIUS protocol.

<img src=connected_security.JPG width=700/>

<a name="OnCloud"></a>
### 2. Flow On Cloud
- All company infra is moved to cloud.
- Perimeter firewall(vSRX) runs inside cloud on VM protecting company infra and users.
- Juniper Cloud ATP, policy enforcer all runs on cloud.
