- [Problem, Solution:Connected Security](#What)
- [Pillars of CS](#Pillars)

<a name="What"></a>
## What?
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
  - Turns routing devices(routers, switches) into security devices(eg: firewall, IPS, VPNs etc).

<a name="Pillars"></a>
## Pillars of Connected Security
- **1. See** ie any function that detects the threat
- **2. Automate** Solution(Software/hardware) that removes threat, executes/starts engine to remove threat.
- **3. Protect** Enforcement of policies at network (eg: firewalls, IPS etc) takes policies from central engine and execute policies
```c
//CS is not a devie its a architecture

                Switch    Automate           Protect
internet        NFX250    SRX300/SRX4000    SRX5400
```
